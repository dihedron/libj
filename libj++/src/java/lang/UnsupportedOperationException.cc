/*
 * UnsupportedOperationException.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/UnsupportedOperationException.h>

namespace java {
	namespace lang {
		Class const & UnsupportedOperationException::klass() {			
			static const Class klass("java.lang.UnsupportedOperationException", &RuntimeException::klass());
			return klass;
		}
	}
}

