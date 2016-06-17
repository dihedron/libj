/*
 * CloneNotSupportedException.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_CLONENOTSUPPORTEDEXCEPTION
#define JAVA_LANG_CLONENOTSUPPORTEDEXCEPTION

#include <java/lang/Exception.h>

namespace java {
	namespace lang {
		class CloneNotSupportedException : public Exception {
		public:
			/// The CloneNotSupportedExceptions' Class object.
			static const Class klass;

			/// Default constructor.
			CloneNotSupportedException() { }

			/// Constructor.
			/// 
			/// Initialises the CloneNotSupportedException with a message and no
			/// root cause.
			/// \param message the message associated to this CloneNotSupportedException.
			CloneNotSupportedException(String const & message) : Exception(message) { }

			/// Constructor.
			/// 
			/// Initialises the CloneNotSupportedException with a message and a
			/// root cause.
			/// \param message the message associated to this CloneNotSupportedException.
			/// \param cause the cause associated to this CloneNotSupportedException.
			CloneNotSupportedException(String const & message, Throwable const & cause) : Exception(message, cause) { }
			
			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return CloneNotSupportedException::klass; 
			}
		};
	}
}


#endif // JAVA_LANG_CLONENOTSUPPORTEDEXCEPTION

