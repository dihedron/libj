 /*
 * Iterable.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/Iterable.h>
#include <java/lang/Interface.h>

namespace java {
	namespace lang {

		template <>
		Interface const & Iterable<void>::klass() {
			static const Interface klass("java.lang.Iterable");
			return klass;
		}
	}
}