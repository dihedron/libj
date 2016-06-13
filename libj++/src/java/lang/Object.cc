/*
 * Object.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Object.h>
#include <java/lang/Class.h>
#include <java/lang/String.h>
#include <java/lang/Number.h>

namespace java {
	namespace lang {
				
		const Class Object::klass("java.lang.Object");

		inline String Object::toString() const {			
			return getClass().getName() + "@" + Number::toHexString(hashCode());
		}		

		std::ostream & operator<<(std::ostream & os, Object const & object) {
			os << object.toString();
			return os;
		}
	}
}
