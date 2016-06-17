/*
 * Serializable.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_SERIALIZABLE
#define JAVA_LANG_SERIALIZABLE

#include <java/lang/Object.h>
#include <java/lang/String.h>
#include <java/lang/Interface.h>

namespace java {
	namespace io {
		/// A pure virtual class implementing the Serializable
		/// marker interface.
		interface Serializable {
		public:
			/// The shared reference to the Interface object for this
			/// class; all Serializables share the same instance.
			static const java::lang::Interface klass;
		};				
	}
}

#endif // JAVA_LANG_SERIALIZABLE

