 /*
 * Iterator.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/util/Iterator.h>
#include <java/lang/Interface.h>

namespace java {
	namespace util {

		template <>
		java::lang::Interface const & Iterator<void>::klass() {
			static const java::lang::Interface klass("java.util.Iterator");
			return klass;
		}
	}
}