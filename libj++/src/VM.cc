
#include <java/lang/Object.h>
#include <java/lang/Class.h>
#include <java/lang/Interface.h>
#include <java/lang/Cloneable.h>
#include <java/lang/Number.h>
#include <java/lang/Integer.h>
#include <java/lang/Long.h>
#include <java/lang/System.h>
#include <java/lang/Runnable.h>
#include <java/lang/Thread.h>
#include <java/util/Iterator.h>
#include <java/lang/Iterable.h>

#include <org/dihedron/log/Level.h>

using namespace java::lang;
using namespace java::util;
using namespace java::io;

using namespace org::dihedron::log;

const Level Threshold(Level::dbg); 

//void * operator new(std::size_t n) throw(std::bad_alloc) {
  // allocates memory 
//}

//void operator delete(void * p) throw() {
  // deletes memory
//}

/*
constexpr int ARRAY_METADATA_SIZE = 4; 

/// This oveerides the standandar C++ allocator to provide a
/// mechanism that is analogous to that provided by talloc:
/// store the size of the array somewhere before the starting
/// address of the data block, and use it to check if there is
/// an out-of-bounds access attempt.
void *operator new[](std::size_t s) throw(std::bad_alloc) {
	// this is equivalent
	void * data = calloc(s + ARRAY_METADATA_SIZE);
    return NULL;
}

void operator delete[](void *p) throw()
{
    // TODO: implement
}
*/

// The following is to fix a GCC bug whereby major() and
// minor() are macros, defined as gnu_dev_major and 
// gnu_dev_minor, effectively polluting the user's namespace 
#if defined _GNU_SOURCE || defined _BSD_SOURCE 
#	ifdef major
#		undef major
#	endif
#	ifdef minor
#		undef minor
#	endif
#endif // _GNU_SOURCE || _BSD_SOURCE


VM::VM() {
	 throw UnsupportedOperationException("Cannot instantiate a VM");
}

const char * VM::logo = "                      ..     ...        \n"
						"                       ..   ...         \n"
						"          ....         ... ...  .       \n"
						"           ....         ...........     \n"
						"           .....        .......         \n"
						"           .......      .......         \n"
						"           ........     .........       \n"
						"           ...    ..   ....             \n"
						"           .. .   ..  ...               \n"
						"           ..    .......                \n"
						"          ......... ....                \n"
						"          ........  ....                \n"
						"         .....       ...                \n"
						"        ......        ..                \n"
						"        .. ..         ...               \n"
						"        .. ..          ..               \n"
						"         ....          ...              \n"
						"         ....           ..              \n"
						"        ....     ...    ...             \n"
						"         ...   .......  ...             \n"
						"          ..  .........  ..             \n"
						"          .......   .......             \n"
						"          .....       .....             \n"
						"          ...          ....             \n"
						"                         .              \n";


void VM::initialise() {
	//std::cout << logo << std::endl;

	// start tracking memory leaks

	// initialise logging

	// load environment

	// load system properties from file or from command line

	std::cout << std::endl;
	std::cout << "    +-------------------------------+" << std::endl;
	std::cout << "    |   VM version " << VM::major() << "." << VM::minor() << "." << VM::patch() << " started.   |" << std::endl;
	std::cout << "    +-------------------------------+" << std::endl;
	std::cout << std::endl;
}

void VM::finalise() {

	// clean up logging

	// dump memory leaks if necessary 

	std::cout << std::endl;
	std::cout << "    +-------------------------------+" << std::endl;
	std::cout << "    |  VM version " << VM::major() << "." << VM::minor() << "." << VM::patch() << " terminated. |" << std::endl;
	std::cout << "    +-------------------------------+" << std::endl;
	std::cout << std::endl;
	// do memory dump if in memory debug mode
}