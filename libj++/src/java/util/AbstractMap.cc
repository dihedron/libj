/*
 * AbstractMap.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/util/AbstractMap.h>
#include <java/lang/Interface.h>

namespace java {
	namespace util {

		using namespace java::lang;

		template<>
		Class const & AbstractMap<Void, Void>::klass() {
			static const Class klass("java.util.AbstractMap", &Object::klass(), { &Map<Void, Void>::klass() });
			return klass;
		}
	}
}