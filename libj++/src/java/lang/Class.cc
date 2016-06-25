/*
 * Class.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Class.h>
#include <java/lang/Number.h>

namespace java {
	namespace lang {

		Class const & Class::klass() {
			static const Class klass("java.lang.Class", &Object::klass());
			return klass;
		}

		Class::Class(String const & name, Class const * super) 
			: name_(name)
			, super_(super) {
		}

		Class::Class(String const & name, Class const * super, std::initializer_list<Interface const *> interfaces) 
			: name_(name)
			, super_(super) {
			if(interfaces.size() > 0) {
				for(auto ref : interfaces) {
					interfaces_.push_back(ref);
				}
			}
		}		
		
		String Class::toString() const {
			// the name of the class must be hardcoded in this case, otherwise 
			// we would end up in an infinite loop between toString() and getClass()
			return String("java.lang.Class@") + Number::toHexString(hashCode());
		}

		jboolean Class::operator==(Class const & other) const {
			return name_ == other.name_;
		}
	}
}

