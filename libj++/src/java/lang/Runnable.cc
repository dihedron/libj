/*
 * Runnable.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/Runnable.h>
#include <java/lang/Interface.h>

namespace java {
	namespace lang {
		Interface const & Runnable::klass() {
			static const Interface klass("java.lang.Runnable");
			return klass;
		}
	}
}

