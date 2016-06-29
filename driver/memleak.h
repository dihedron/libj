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

#else 
	//
	// memory leak detection not enabled
	//


#endif // DETECT_MEMLEAKS

#endif // MEMLEAK_H