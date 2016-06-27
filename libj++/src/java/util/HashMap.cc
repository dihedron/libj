 /*
 * HashMap.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/util/HashMap.h>
#include <java/lang/Interface.h>

namespace java {
	namespace util {

		using namespace java::lang;

		template<>
		Class const & HashMap<Void, Void>::klass() {
			static const Class klass("java.util.HashMap", &AbstractMap<Void, Void>::klass(), { &Serializable::klass(), &Cloneable::klass() });
			return klass;
		}

		
	}
}