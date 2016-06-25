/*
 * Number.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/Number.h>

namespace java {
	namespace lang {

		Class const & Number::klass() {
			static const Class klass("java.lang.Number", &Object::klass());
			return klass;
		}		
	}
}
