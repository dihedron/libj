/*
 * VirtualMachineError.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/VirtualMachineError.h>

namespace java {
	namespace lang {

		Class const & VirtualMachineError::klass() {
			static const Class klass("java.lang.VirtualMachineError", &Error::klass());
			return klass;
		}
	}
}

