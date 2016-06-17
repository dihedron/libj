/*
 * Cloneable.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_CLONEABLE
#define JAVA_LANG_CLONEABLE

#include <java/lang/Object.h>
#include <java/lang/Interface.h>

namespace java {
	namespace lang {
		/// A pure virtual class implementing the Cloneable
		/// marker interface.
		interface Cloneable {
		public:

			/// The shared reference to the Interface object for this
			/// class; all object share the same instance.
			static const Interface klass;			};				
	}
}

#endif // JAVA_LANG_CLONEABLE

