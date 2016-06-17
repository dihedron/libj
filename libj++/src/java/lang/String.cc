/*
 * String.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/String.h>
#include <java/lang/Class.h>

namespace java {
	namespace lang {

		String String::operator+(String const & string) const {
			return String(this->value_ + string.value_);
		}
		
		String String::operator+(long value) const {
			return valueOf(value);
		}

		String String::operator+(long long value) const {
			return valueOf(value);
		}
		
		std::ostream & operator<<(std::ostream & os, String const & string) {
			os << string.value_;
			return os;
		}
	}
}
