/*
 * Error.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_ERROR
#define JAVA_LANG_ERROR

#include <java/lang/Throwable.h>

namespace java {
	namespace lang {
		class Error : extends Throwable {
		public:
			/// Returns a reference to the shared Class object.
			///
			/// Returns the shared reference to the Class object for 
			/// this class; all object share the same instance, which 
			/// is a local static constant object: this makes sure that 
			/// the Class object is initialised as soon as this class
			/// is reerences, and that there is no problem with concurrent
			/// access since it can only be instantiated once (see 
			/// Scott Meyers, Effective C++, Item 4).
			/// \return a reference to the shared Class object.
			static Class const & klass();

			/// Default constructor.
			Error() { }

			/// Constructor.
			/// 
			/// Initialises the Error with a message and no
			/// root cause.
			/// \param message the message associated to this Error.
			Error(String const & message) : Throwable(message) { }

			/// Constructor.
			/// 
			/// Initialises the Error with a message and a
			/// root cause.
			/// \param message the message associated to this Error.
			/// \param cause the cause associated to this Error.
			Error(String const & message, Throwable const & cause) : Throwable(message, cause) { }
			
			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return Error::klass(); 
			}
		};
	}
}


#endif // JAVA_LANG_ERROR

