/*
 * CloneNotSupportedException.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Class.h>

namespace java {
	namespace lang {

		const Class CloneNotSupportedException::klass("java.lang.CloneNotSupportedException", Exception::klass);

		CloneNotSupportedException & CloneNotSupportedException::operator=(CloneNotSupportedException const & other) {
			if(this != &other) {
				Exception::operator=((Exception const &)other);
			}
			return *this;
		}
	}
}