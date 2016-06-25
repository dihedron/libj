/*
 * Exception.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Exception.h>

namespace java {
	namespace lang {

		Class const & Exception::klass() {
			static const Class klass("java.lang.Exception", &Throwable::klass());
			return klass;
		}
	}
}

