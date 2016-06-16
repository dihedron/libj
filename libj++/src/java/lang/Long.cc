/*
 * Long.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/Long.h>
#include <java/lang/String.h>

namespace java {
	namespace lang {

		const Class Long::klass("java.lang.Long", Number::klass);


		jbyte Long::byteValue() const {
			return (jbyte)value_;
		}

		double Long::doubleValue() const {
			return (double)value_;
		}

		float Long::floatValue() const {
			return (float)value_;
		}

		jshort Long::shortValue() const {
			return (jshort)value_;
		}

		jint Long::intValue() const {
			return (jint)value_;
		}

		jlong Long::longValue() const {
			return (jlong)value_;
		}

		String Long::toString() const {			
			return String::valueOf(this->value_);
		}	

		std::ostream & operator<<(std::ostream & os, Long const & number) {
			os << number.value_;
			return os;
		}
	}
}