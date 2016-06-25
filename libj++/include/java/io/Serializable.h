/*
 * Serializable.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_SERIALIZABLE
#define JAVA_LANG_SERIALIZABLE

#include <java/lang/Object.h>
#include <java/lang/Interface.h>

namespace java {
	namespace io {
		/// A pure virtual class implementing the Serializable
		/// marker interface.
		interface Serializable {
		public:

			/// Returns a reference to the shared Interface object.
			///
			/// Returns the shared reference to the Interface object for 
			/// this interface; all object share the same instance, which 
			/// is a local static constant object: this makes sure that 
			/// the Interface object is initialised as soon as this interface
			/// is referenced, and that there is no problem with concurrent
			/// access since it can only be instantiated once (see 
			/// Scott Meyers, Effective C++, Item 4).
			/// \return a reference to the shared Interface object.
			static java::lang::Interface const & klass();
		};				
	}
}

#endif // JAVA_LANG_SERIALIZABLE

