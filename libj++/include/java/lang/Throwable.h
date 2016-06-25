/*
 * Throwable.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_THROWABLE
#define JAVA_LANG_THROWABLE

#include <java/lang/Object.h>
#include <java/lang/String.h>
#include <java/io/Serializable.h>

namespace java {
	namespace lang {
		class Throwable : public Object, public java::io::Serializable {
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
			static Interface const & klass();

			/// Default constructor.
			Throwable();

			/// Constructor.
			/// 
			/// Initialises the Throwable with a message and no
			/// root cause.
			/// \param message the message associated to this Throwable.
			Throwable(String const & message);

			/// Constructor.
			/// 
			/// Initialises the Throwable with a message and a
			/// root cause.
			/// \param message the message associated to this Throwable.
			/// \param cause the cause associated to this Throwable.
			Throwable(String const & message, Throwable const & cause);
			
			/// Returns this Throwable's message.
			///
			/// Returns this Throwable's message, or an mepty String.
			/// \return this Throwable's message
			virtual String const & getMessage() const {
				return message_;
			}

			/// Returns a localized message.
			///
			/// Subclasses can return a localized version of this message
			/// by overriding this method; the defaule implementation 
			/// behaves as getMessage().
			/// \return this Throwable's message.
			virtual String getLocalizedMessage() const {
				return getMessage();
			}

			/// Returns th cause of this Throwable.
			///
			/// Returns the pointer to the cause of this Throwable,
			/// nullptr if it has no cause.
			/// \return  the pointer to the cause of this Throwable
			virtual Throwable const * getCause() const {
				return cause_;
			} 

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return Throwable::klass(); 
			}

			/// Returns a String representation of this Throwable.
			///
			/// Returns the name of this class, a ": " and then the
			/// result of the invocation of getLocalizedMessage().
			/// \return the Throwable as a String.
			virtual String toString() const;
			
			/// Cleans up the root Throwable pointer, if any.
			inline virtual void finalize() {				
				if(cause_ != nullptr) {
					delete cause_;
					cause_ = nullptr;
				}
			}

		protected:

			/// The message associated with this throwable.
			String message_;

			/// A root cause to this exception.
			Throwable * cause_; 
		};
	}
}


#endif // JAVA_LANG_THROWABLE

