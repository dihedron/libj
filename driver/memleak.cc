
#include "memleak.h"

#if DETECT_MEMLEAKS

	#include <iostream>
	#include <iomanip>
	#include <map>
	#include <cstring>
	#include <mutex>
	#include <java/lang/OutOfMemoryError.h>

	// Each time a meory block is allocated, an additional integer is
	// prepended to store the memory block id, which is an atomic counter
	// incremented each time a new block is allocated. The actual block 
	// information is stored in a std::map having the given integer as
	// the key and a struct containing info on the source file and  

	struct Block {
		size_t			size;
		const char * 	source;
		unsigned long 	line;
	};

	class GC {
	public:
    	GC() { }
    	GC & operator= (GC const &) = delete;

    	void add(void * pointer, size_t size, const char * filename, unsigned long line) {
			Block block { size, nullptr, line };
			printf("GC::add: 1\n");
			do {
				if(filename == nullptr) {
					block.source = "unknown location";
					break;
				}
				block.source = std::strrchr(filename, '/');
				if(block.source != nullptr) {
					block.source += 1;
					break;
				}
				block.source = std::strrchr(filename, '\\');
				if(block.source != nullptr) {
					block.source += 1;
					break;
				}
			} while(false);
			printf("block { size: %u, source: %s, line: %lu }\n", block.size, block.source, block.line);
			
        	printf("GC::add: 2\n"); 
			{
				std::lock_guard<std::mutex> lock(mutex_);
				printf("GC::add: 3\n");
				blocks_[pointer] = block;
				printf("GC::add: 4\n");
			}
			printf("GC::add: 5\n");
    	}

		void remove(void * pointer) {
			printf("5\n");
        	std::lock_guard<std::mutex> lock(mutex_);
			printf("6\n");
			blocks_.erase(pointer);
			printf("7\n");
		} 

	private:
    	std::mutex 						mutex_;
    	std::map<void *, Block> 		blocks_;
	};

	static GC gc;


	void * __malloc(size_t size, char const * filename = nullptr, unsigned long line = 0) {
		void * pointer;
		printf("malloc: 1\n");
	
		#undef  malloc
		#define malloc(s)	malloc(s)

		pointer = (void *) malloc(size);
		printf("malloc: 2\n");
		gc.add(pointer, size, filename, line);
		printf("malloc: 3\n");
	
		#undef  malloc
		#define malloc(s)	__malloc(s, __FILE__, __LINE__)
	  
	  	return pointer;
	}

	void * __calloc(size_t count, size_t size, char const * filename = nullptr, unsigned long line = 0) {
		void * pointer;
	
		#undef  calloc
		#define calloc(s, t)	calloc(s, t)

	  	pointer = (void *) calloc(count, size);
		gc.add(pointer, size, filename, line);
	
		#undef  calloc
		#define calloc(s, t)	__calloc(s, t, __FILE__, __LINE__)
	  
	  	return pointer;
	}
	
	void * __realloc(void * oldpointer, size_t size, char const * filename = nullptr, unsigned long line = 0) {
	
		#undef  realloc
		#define realloc(s, t)	realloc(s, t)

		
	  	void * newpointer = (void *) realloc(oldpointer, size);
		gc.remove(oldpointer);
		gc.add(newpointer, size, filename, line);
	
		#undef  realloc
		#define realloc(s, t)	__realloc(s, t, __FILE__, __LINE__)
	  
	  	return newpointer;
	}

	void __free(void * pointer)	{		

		#undef  free
		#define free(s)		free(s)

		free(pointer);
		gc.remove(pointer);

		#undef  free
		#define free(s)		__free(s)
	}	
	
	void * operator new(size_t size) {
		printf("::new: 1\n");

		#undef  malloc
		#define malloc(s)	malloc(s)

		void * p = (void *) malloc(size);

		#undef  malloc
		#define malloc(s)	__malloc(s, __FILE__, __LINE__)
		
		printf("::new: 2\n"); 
 		if(p != nullptr) {
			return p;
		}
		// ANSI/ISO compliant behavior would require throwning std::bad_alloc()
		throw java::lang::OutOfMemoryError(); 
	}

	void operator delete (void *p) noexcept(true) {
		#undef  free
		#define free(s)		free(s)

		free(p);

		#undef  free
		#define free(s)		__free(s)
	}	

	// see http://en.cppreference.com/w/cpp/memory/new/operator_new	
 
#endif // DETECT_MEMLEAKS
