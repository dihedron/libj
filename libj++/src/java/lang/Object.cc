/*
 * Object.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Object.h>
#include <java/lang/Class.h>
#include <java/lang/Interface.h>
#include <java/lang/String.h>
#include <java/lang/Number.h>

namespace java {
	namespace lang {
				
		jboolean Object::instanceOf(Class const & otherClass) const {
			
			Class const * thisClass = &(getClass());
			do {
				if(*thisClass == otherClass) {
					std::cout << "compared class " << thisClass->getName() << " against " << otherClass.getName() << ": equal" << std::endl;
					return true;
				} else {
					std::cout << "compared class " << thisClass->getName() << " against " << otherClass.getName() << ": different" << std::endl;
				}
				for(auto i : thisClass->getInterfaces()) {
					if(otherClass == *i) {
						std::cout << "compared interface " << i->getName() << " against " << otherClass.getName() << ": equal" << std::endl;
						return true;
					} else {
						std::cout << "compared interface " << i->getName() << " against " << otherClass.getName() << ": different" << std::endl;
					}
 				}			
			} while((thisClass = thisClass->getSuperclass()) != nullptr);
			return false;  
		}

		String Object::toString() const {			
			return getClass().getName() + "@" + Number::toHexString(hashCode());
		}		

		std::ostream & operator<<(std::ostream & os, Object const & object) {
			os << object.toString();
			return os;
		}
	}
}
