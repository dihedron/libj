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

		Class::Class(String const & name, Class const & super, std::initializer_list<char const *> interfaces) 
			: name_(name)
			, super_(&super) {
			if(interfaces.size() > 0) {
				for(auto ref : interfaces) {
					interfaces_.push_back(ref);
				}
			}
		}

		Class::Class(const Class& other) 
			: name_(other.name_)
			, super_(other.super_) {
		}

		std::list<String> Class::getInterfaces() const {			
			std::list<String> interfaces(interfaces_);
			if(super_ != nullptr) {
				interfaces.merge(super_->getInterfaces());
			}
			return interfaces;
		}

		String Class::toString() const {
			// the name of the class must be hardcoded in this case, otherwise 
			// we would end up in an infinite loop between toString() and getClass()
			return String("java.lang.Class@") + Number::toHexString(hashCode());
		}
	}
}

