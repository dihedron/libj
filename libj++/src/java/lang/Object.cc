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
			jboolean result = false;
			Class const & thisClass = getClass(); 
			if(thisClass == otherClass) {
				return true;
			} else {
				// check superclasses
				Class const * super = &thisClass;
				while((super = super->getSuperclass()) != nullptr) {  
					if(super->getName() == otherClass.getName()) {
						return true;
					}
				}
				// how do we check for interfaces, since interfaces 
				// have no associated class object in our scheme?
			} 
			return result;
		}

		jboolean Object::instanceOf(Interface const & otherInterface) const {
			for(auto s: getClass().getInterfaces()) {
				if(*s == otherInterface) {
					return true;
				}
			}
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
