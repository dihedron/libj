/*
 * Integer.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/Integer.h>
//#include <java/lang/String.h>

namespace java {
	namespace lang {

		const Class Integer::klass("java.lang.Integer", Number::klass);


		jbyte Integer::byteValue() const {
			return (jbyte)value_;
		}

		double Integer::doubleValue() const {
			return (double)value_;
		}

		float Integer::floatValue() const {
			return (float)value_;
		}

		jshort Integer::shortValue() const {
			return (jshort)value_;
		}

		jint Integer::intValue() const {
			return value_;
		}

		jlong Integer::longValue() const {
			return (jlong)value_;
		}

		String Integer::toString() const {			
			return String::valueOf(this->value_);
		}	

		std::ostream & operator<<(std::ostream & os, Integer const & number) {
			os << number.value_;
			return os;
		}
	}
}