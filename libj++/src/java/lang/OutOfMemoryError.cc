/*
 * OutOfMemoryError.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/OutOfMemoryError.h>

namespace java {
	namespace lang {
		Class const & OutOfMemoryError::klass() {			
			static const Class klass("java.lang.OutOfMemoryError", &VirtualMachineError::klass());
			return klass;
		}
	}
}

