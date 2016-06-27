 /*
 * Iterator.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/util/Iterator.h>
#include <java/lang/Interface.h>
#include <VM.h>

namespace java {
	namespace util {

		using namespace java::lang;

		template <>
		Interface const & Iterator<Void>::klass() {
			static const Interface klass("java.util.Iterator");
			return klass;
		}
	}
}