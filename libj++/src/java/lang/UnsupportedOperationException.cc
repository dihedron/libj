/*
 * UnsupportedOperationException.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/Class.h>

namespace java {
	namespace lang {

		const Class UnsupportedOperationException::klass("java.lang.UnsupportedOperationException", RuntimeException::klass);

		UnsupportedOperationException & UnsupportedOperationException::operator=(UnsupportedOperationException const & other) {
			if(this != &other) {
				RuntimeException::operator=((RuntimeException const &)other);
			}
			return *this;
		}
	}
}