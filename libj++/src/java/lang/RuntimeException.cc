/*
 * RuntimeException.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/RuntimeException.h>

namespace java {
	namespace lang {

		Class const & RuntimeException::klass() {
			static const Class klass("java.lang.RuntimeException", &Exception::klass());
			return klass;
		}
	}
}

