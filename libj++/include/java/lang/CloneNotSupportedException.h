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

			/// Copy constructor.
			///
			/// Creates a CloneNotSupportedException object, initialising its 
			/// internal status with that of the provided object.
			/// \param other the object to copy the internal status from.
			CloneNotSupportedException(CloneNotSupportedException const & other) : Exception(other) { }

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
			
			/// Virtual destructor.
			inline virtual ~CloneNotSupportedException() {
				finalize();
			}

			/// Assignment operator.
			///
			/// Copies the contents of the other CloneNotSupportedException into
			/// this one.
			/// \param other the CloneNotSupportedException to copy from.
			CloneNotSupportedException & operator=(CloneNotSupportedException const & other);

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

