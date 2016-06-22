
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

using namespace java::lang;
using namespace java::io;

const Class Object::klass("java.lang.Object");
const Class Class::klass("java.lang.Class", &Object::klass);
const Class Interface::klass("java.lang.Interface", &Class::klass);
const Class String::klass("java.lang.String", &Object::klass);
const Interface Cloneable::klass("java.lang.Cloneable");
const Class System::klass("java.lang.System", &Object::klass);
const Class Number::klass("java.lang.Number", &Object::klass);
const Class Integer::klass("java.lang.Integer", &Number::klass);
const Class Long::klass("java.lang.Long", &Number::klass);
const Interface Serializable::klass("java.io.Serializable");
const Interface Throwable::klass("java.lang.Throwable", { &java::io::Serializable::klass });
const Class Exception::klass("java.lang.Exception", &Throwable::klass);
const Class RuntimeException::klass("java.lang.RuntimeException", &Exception::klass);
const Class CloneNotSupportedException::klass("java.lang.CloneNotSupportedException", &Exception::klass);
const Class UnsupportedOperationException::klass("java.lang.UnsupportedOperationException", &RuntimeException::klass);
const Interface Runnable::klass("java.lang.Runnable");
const Class Thread::klass("java.lang.Thread", &Object::klass, { &Runnable::klass });

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