/*
 * Serializable.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/io/Serializable.h>

namespace java {
	namespace io {
		java::lang::Interface const & Serializable::klass() {
			static const java::lang::Interface klass("java.lang.Serializable");
			return klass;
		}
	}
}

