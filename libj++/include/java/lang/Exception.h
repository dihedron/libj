/*
 * Exception.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_EXCEPTION
#define JAVA_LANG_EXCEPTION

#include <java/lang/Throwable.h>

namespace java {
	namespace lang {
		class Exception : public Throwable {
		public:
			/// The Exceptions' Class object.
			static const Class klass;

			/// Default constructor.
			Exception() { }

			/// Copy constructor.
			///
			/// Creates an Exception object, initialising its internal status
			/// with that of the provided object.
			/// \param other the object to copy the internal status from.
			Exception(Exception const & other) : Throwable(other) { }

			/// Constructor.
			/// 
			/// Initialises the Exception with a message and no
			/// root cause.
			/// \param message the message associated to this Throwable.
			Exception(String const & message) : Throwable(message) { }

			/// Constructor.
			/// 
			/// Initialises the Exception with a message and a
			/// root cause.
			/// \param message the message associated to this Exception.
			/// \param cause the cause associated to this Exception.
			Exception(String const & message, Throwable const & cause) : Throwable(message, cause) { }
			
			/// Virtual destructor.
			virtual inline ~Exception() {
				finalize();
			}

			/// Assignment operator.
			///
			/// Copies the contents of the other Throwable into
			/// this one.
			/// \param other the Throwable to copy from.
			Exception & operator=(Exception const & other);

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			virtual inline Class const & getClass() const {
				return Exception::klass; 
			}

			/// Returns a String representation of this Exception.
			///
			/// Returns the name of this class, a ": " and then the
			/// result of the invocation of getLocalizedMessage().
			/// \return the Exception as a String.
			//virtual String toString() const;

		protected:

			/// Cleans up the root Exception pointer, if any.
			inline virtual void finalize() {
				//std::cout << "finalize in Exception" << std::endl;
			}
		};
	}
}


#endif // JAVA_LANG_EXCEPTION

