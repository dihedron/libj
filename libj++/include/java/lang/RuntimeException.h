/*
 * RuntimeException.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_RUNTIMEEXCEPTION
#define JAVA_LANG_RUNTIMEEXCEPTION

#include <java/lang/Exception.h>

namespace java {
	namespace lang {
		class RuntimeException : public Exception {
		public:
			/// The RuntimeException' Class object.
			static const Class klass;

			/// Default constructor.
			RuntimeException() { }

			/// Copy constructor.
			///
			/// Creates a RuntimeException object, initialising its 
			/// internal status with that of the provided object.
			/// \param other the object to copy the internal status from.
			RuntimeException(RuntimeException const & other) : Exception(other) { }

			/// Constructor.
			/// 
			/// Initialises the RuntimeException with a message and no
			/// root cause.
			/// \param message the message associated to this RuntimeException.
			RuntimeException(String const & message) : Exception(message) { }

			/// Constructor.
			/// 
			/// Initialises the RuntimeException with a message and a
			/// root cause.
			/// \param message the message associated to this RuntimeException.
			/// \param cause the cause associated to this RuntimeException.
			RuntimeException(String const & message, Throwable const & cause) : Exception(message, cause) { }
			
			/// Virtual destructor.
			inline virtual ~RuntimeException() {
				finalize();
			}

			/// Assignment operator.
			///
			/// Copies the contents of the other RuntimeException into
			/// this one.
			/// \param other the RuntimeException to copy from.
			RuntimeException & operator=(RuntimeException const & other);

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return RuntimeException::klass; 
			}
		};
	}
}


#endif // JAVA_LANG_RUNTIMEEXCEPTION

