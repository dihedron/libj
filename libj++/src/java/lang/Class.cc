/*
 * Class.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Class.h>
#include <java/lang/Number.h>

namespace java {
	namespace lang {
		
		const Class Class::klass("java.lang.Class", Object::klass);

		Class::Class(String const & name) 
			: name_(name)
			, super_(nullptr) {
		}

		Class::Class(String const & name, Class const & super) 
			: name_(name)
			, super_(&super) {
		}

		Class::Class(const Class& other) 
			: name_(other.name_)
			, super_(other.super_) {
		}

		String Class::toString() const {
			// the name of the class must be hardcoded in this case, otherwise 
			// we sould end up in an infinite loop between toString() and getClass()
			return String("java.lang.Class@") + Number::toHexString(hashCode());
		}
	}
}

