
#include "memleak.h"

#if DETECT_MEMLEAKS

	#include <iostream>
	#include <java/lang/OutOfMemoryError.h>
	
	void * operator new(size_t size) {		
 		void * p = malloc(size); 
 		if(p != nullptr) {
			std::cout << "* memleak: allocated " << size << " bytes from heap at address " << p << std::endl;
			return p;
		}
		// ANSI/ISO compliant behavior would require throwning std::bad_alloc()
		throw java::lang::OutOfMemoryError(); 
	}

	void operator delete (void *p) noexcept(true) {
		std::cout << "* memleak: freeing memory at address " << p << std::endl;
 		free(p);
	}	

	// see http://en.cppreference.com/w/cpp/memory/new/operator_new	
 
#endif // DETECT_MEMLEAKS
