/*
 * System.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#ifndef JAVA_LANG_SYSTEM
#define JAVA_LANG_SYSTEM

#include <java/lang/Object.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/UnsupportedOperationException.h>

namespace java {
	namespace lang {
		
		class Class;
		class String;
				
		/// The root of the object's hierarchy.
		///
		/// The object class lies at the root of the objects'
		/// hierarchy; each class must inherit from Object, and
		/// gets some methgod for free, such as hashCode() and
		/// toString().
		class System : public Object {
		public:

			/// The shared reference to the Class object for this
			/// class; all object share the same instance.
			static const Class klass;


			static jlong currentTimeMillis();

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return System::klass; 
			}

			/// Returns a string preresentation of the object.
			///
			/// This method provides a string representation of the 
			/// object; it can be used to customise the way the object
			/// is printed out to a text stream.
			/// \return the object's string representation.
			virtual String toString() const;

		private:
			
			/// Default constructor.
			System() : Object() { throw new UnsupportedOperationException("Cannot instantiate an object of class java.lang.System."); }
					
		protected:

			/// Performs a clone of the System, object.
			///
			/// The clone operation is not supported, so this
			/// method will throw a clonenotSupportedException.
			virtual Object clone() const { throw new CloneNotSupportedException("Cannot clone an object of type java.lang.System."); }
		};
	}
}
#endif // JAVA_LANG_SYSTEM

