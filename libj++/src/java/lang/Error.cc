/*
 * Error.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Error.h>

namespace java {
	namespace lang {

		Class const & Error::klass() {
			static const Class klass("java.lang.Error", &Throwable::klass());
			return klass;
		}
	}
}

