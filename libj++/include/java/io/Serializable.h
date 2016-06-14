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
			static constexpr char const * name = "java.io.Serializable";// java::lang::String name; 

			//static java::lang::String const & getName() { return name; } 
		};				
	}
}

#endif // JAVA_LANG_SERIALIZABLE

