/*
 * Interface.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Interface.h>
#include <java/lang/Number.h>

namespace java {
	namespace lang {

		Class const & Interface::klass() {
			static const Class klass("java.lang.Interface", &Class::klass());
			return klass;
		}
		
		Interface::Interface(String const & name) 
			: Class(name, &Object::klass()) {
		}

		Interface::Interface(String const & name, std::initializer_list<Interface const *> interfaces) 
			: Class(name, &Object::klass(), interfaces) {
		}
	}
}

