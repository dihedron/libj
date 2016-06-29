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
	void operator delete (void *p) noexcept(true);

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