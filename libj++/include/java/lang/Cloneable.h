/*
 * Cloneable.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_CLONEABLE
#define JAVA_LANG_CLONEABLE

#include <java/lang/Object.h>

namespace java {
	namespace io {
		/// A pure virtual class implementing the Cloneable
		/// marker interface.
		interface Cloneable {
		public:
			/// The name of the interface.
			static constexpr char const * name = "java.lang.Cloneable"; 
		};				
	}
}

#endif // JAVA_LANG_CLONEABLE

