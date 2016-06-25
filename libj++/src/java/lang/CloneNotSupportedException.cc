/*
 * CloneNotSupportedException.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/CloneNotSupportedException.h>

namespace java {
	namespace lang {
		Class const & CloneNotSupportedException::klass() {
			static const Class klass("java.lang.CloneNotSupportedException", &Exception::klass());
			return klass;
		}
	}
}

