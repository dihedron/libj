/*
 * RuntimeException.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/RuntimeException.h>
#include <java/lang/Class.h>

namespace java {
	namespace lang {
		const Class RuntimeException::klass("java.lang.RuntimeException", Exception::klass);
	}
}