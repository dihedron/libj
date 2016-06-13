/*
 * Serializable.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_SERIALIZABLE
#define JAVA_LANG_SERIALIZABLE

#include <java/lang/Object.h>
#include <java/lang/String.h>

namespace java {
	namespace io {
		/// A pure virtual class implementing the Serializable
		/// marker interface.
		interface Serializable {
		public:
			static const java::lang::String name; 
		};				
	}
}

#endif // JAVA_LANG_SERIALIZABLE

