/*
 * Cloneable.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Cloneable.h>
#include <java/lang/Interface.h>

namespace java {
	namespace lang {
		Interface const & Cloneable::klass() {
			static const Interface klass("java.lang.Cloneable");
			return klass;
		}
	}
}

