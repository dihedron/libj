/*
 * UnsupportedOperationException.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION
#define JAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION

#include <java/lang/RuntimeException.h>

namespace java {
	namespace lang {
		class UnsupportedOperationException : public RuntimeException {
		public:
			/// The UnsupportedOperationException' Class object.
			static const Class klass;

			/// Default constructor.
			UnsupportedOperationException() { }

			/// Copy constructor.
			///
			/// Creates a UnsupportedOperationException object, initialising its 
			/// internal status with that of the provided object.
			/// \param other the object to copy the internal status from.
			UnsupportedOperationException(UnsupportedOperationException const & other) : RuntimeException(other) { }

			/// Constructor.
			/// 
			/// Initialises the UnsupportedOperationException with a message and no
			/// root cause.
			/// \param message the message associated to this UnsupportedOperationException.
			UnsupportedOperationException(String const & message) : RuntimeException(message) { }

			/// Constructor.
			/// 
			/// Initialises the UnsupportedOperationException with a message and a
			/// root cause.
			/// \param message the message associated to this UnsupportedOperationException.
			/// \param cause the cause associated to this UnsupportedOperationException.
			UnsupportedOperationException(String const & message, Throwable const & cause) : RuntimeException(message, cause) { }
			
			/// Virtual destructor.
			inline virtual ~UnsupportedOperationException() {
				finalize();
			}

			/// Assignment operator.
			///
			/// Copies the contents of the other UnsupportedOperationException into
			/// this one.
			/// \param other the UnsupportedOperationException to copy from.
			UnsupportedOperationException & operator=(UnsupportedOperationException const & other);

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return UnsupportedOperationException::klass; 
			}
		};
	}
}


#endif // JAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION

