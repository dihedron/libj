 /*
 * Map.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/util/Map.h>
#include <java/lang/Interface.h>

namespace java {
	namespace util {

		using namespace java::lang;

		template <>
		Interface const & Map<Void, Void>::klass() {
			static const Interface klass("java.util.Map");
			return klass;
		}
	}
}