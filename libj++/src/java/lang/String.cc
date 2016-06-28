/*
 * String.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/String.h>
#include <java/lang/Class.h>

namespace java {
	namespace lang {

		Class const & String::klass() {
			static const Class klass("java.lang.String", &Object::klass());
			return klass;
		}		

		String String::operator+(String const & string) const {
			return String(this->value_ + string.value_);
		}
		
		String String::operator+(jbyte value) const {
			return *this + valueOf(value);
		}

		String String::operator+(jshort value) const {
			return *this + valueOf(value);
		}

		String String::operator+(jint value) const {
			return *this + valueOf(value);
		}

		String String::operator+(jlong value) const {
			return *this + valueOf(value);
		}
		
		std::ostream & operator<<(std::ostream & os, String const & string) {
			os << string.value_;
			return os;
		}
	}
}
