
#include "memleak.h"

#if DETECT_MEMLEAKS

	#include <iostream>
	#include <java/lang/OutOfMemoryError.h>

	static void track(void * pointer, size_t size, char const * filename, unsigned long line) {
		std::cout << "allocated " << size << " bytes at address " << pointer;
		if(filename != nullptr) {
			std::cout << " (source: " << filename << ":" << line << ")";
		} 
		std::cout << std::endl;
	}

	static void retrack(void * oldpointer, void * newpointer, size_t size, char const * filename, unsigned long line) {
		std::cout << "reallocated " << size << " bytes from address " << oldpointer << " to address " << newpointer;
		if(filename != nullptr) {
			std::cout << " (source: " << filename << ":" << line << ")";
		} 
		std::cout << std::endl;
	}

	static void untrack(void * pointer) {
		std::cout << "freed memory at address " << pointer << std::endl;
	}
	

	void * __malloc(size_t size, char const * filename = nullptr, unsigned long line = 0) {
		void * pointer;
	
		#undef  malloc
		#define malloc(s)	malloc(s)

	  	pointer = (void *) malloc(size);
	  	track(pointer, size, filename, line);
	
		#undef  malloc
		#define malloc(s)	__malloc(s, __FILE__, __LINE__)
	  
	  	return pointer;
	}

	void * __calloc(size_t count, size_t size, char const * filename = nullptr, unsigned long line = 0) {
		void * pointer;
	
		#undef  calloc
		#define calloc(s, t)	calloc(s, t)

	  	pointer = (void *) calloc(count, size);
	  	track(pointer, size * count, filename, line);
	
		#undef  calloc
		#define calloc(s, t)	__calloc(s, t, __FILE__, __LINE__)
	  
	  	return pointer;
	}
	
	void * __realloc(void * oldpointer, size_t size, char const * filename = nullptr, unsigned long line = 0) {
	
		#undef  realloc
		#define realloc(s, t)	realloc(s, t)

		
	  	void * newpointer = (void *) realloc(oldpointer, size);		
	  	retrack(oldpointer, newpointer, size, filename, line);
	
		#undef  realloc
		#define realloc(s, t)	__realloc(s, t, __FILE__, __LINE__)
	  
	  	return newpointer;
	}

	void __free(void * pointer)	{
		untrack(pointer);

		#undef  free
		#define free(s)		free(s)

		free(pointer);

		#undef  free
		#define free(s)		__free(s)
	}	
	
	void * operator new(size_t size) {		
 		void * p = __malloc(size); 
 		if(p != nullptr) {
			//std::cout << "* memleak: allocated " << size << " bytes from heap at address " << p << std::endl;
			return p;
		}
		// ANSI/ISO compliant behavior would require throwning std::bad_alloc()
		throw java::lang::OutOfMemoryError(); 
	}

	void operator delete (void *p) noexcept(true) {
		//std::cout << "* memleak: freeing memory at address " << p << std::endl;
 		__free(p);
	}	

	// see http://en.cppreference.com/w/cpp/memory/new/operator_new	
 
#endif // DETECT_MEMLEAKS
