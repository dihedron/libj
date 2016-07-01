#ifndef MEMLEAK_H
#define MEMLEAK_H

// Set to 1 to enable memory leak detection
#define DETECT_MEMLEAKS 0

#if DETECT_MEMLEAKS
	//
	// memory leak detection enabled
	//

	#include <new>
	#include <cstdlib>

	void * operator new(size_t size);
	void   operator delete (void *p) noexcept(true);

	void * __malloc(size_t size, char const * filename, unsigned long line);
	void * __calloc(size_t count, size_t size, char const * filename, unsigned long line);
	void * __realloc(void * pointer, size_t size, char const * filename, unsigned long line);
    void   __free(void * pointer);

	// replace memory functions with tracking versions
	#define   malloc(s)       __malloc(s,__FILE__, __LINE__)
	#define   calloc(s, t)    __calloc(s, t, __FILE__, __LINE__)
	#define   realloc(s, t)   __realloc(s, t, __FILE__, __LINE__)
	#define   free(s)         __free(s)

	// TODO: override all versions of new[] and delete[], taking into 
	// account that some of them do not throw and return a null pointer 
	// instead, plus provide logging versions of all C memory functions
	// such as malloc calloc realloc and free via macros taking the __FILE__ 
	// and __LINE__ parameters; store this information into an array
	// so that any outstanding memory block can be logged when the 
	// program exits (with some _atexit() or via an explicit call to 
	// java::lang::System::gc() by the program)

#else 
	//
	// memory leak detection not enabled
	//

#endif // DETECT_MEMLEAKS

#endif // MEMLEAK_H