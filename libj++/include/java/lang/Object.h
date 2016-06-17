/*
 * Object.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */



#ifndef JAVA_LANG_OBJECT
#define JAVA_LANG_OBJECT

#include <java/lang/ValueTypes.h>
#include <macros.h>
#include <iostream>

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
		class Object {
		public:

			/// The shared reference to the Class object for this
			/// class; all object share the same instance.
			static const Class klass;						
												
			/// Default constructor.
			Object() { }
						
			/// Compares this object to another for equality.
			///
			/// Compares this instance of object to the other one,
			/// returning true if and only if the two objects are 
			/// the exact same instance.
			/// \param other the object to be compared with this one.
			/// \return true if the other object is the same instance 
			/// as this one.
			inline virtual jboolean equals(Object const & other) const { 
				return (this == &other); 
			}
						
			/// Returns the object's hashcode.
			///
			/// Returns the object's hash code, which is ideally unique;
			/// as a matter of fact, it returns the object's address in
			/// memory, so that no two objects can share the same address 
			/// unless they are the same object.
			/// \return the object's hash code.
			inline virtual jlong hashCode() const { 
				return reinterpret_cast<jlong>(this);
			}

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return Object::klass; 
			}

			/// Checks if the current object can be cast to the givenm type.
			///
			/// Checks if the current object is an instance of, or can be
			/// cast to the given type: if the given type is a clas, it must
			/// be a superclass of the curre Object's one for this to be true;
			/// if it is an interface, it must be directly implemented by this
			/// Object's class or by any of its superclasses.
			/// \param otherClass the Class or interface to check against.
			/// \return whether this Object can be cast to the given type.
			jboolean instanceOf(Class const & otherClass) const;

			jboolean instanceOf(String const & otherInterface) const;

			/// Returns a string preresentation of the object.
			///
			/// This method provides a string representation of the 
			/// object; it can be used to customise the way the object
			/// is printed out to a text stream.
			/// \return the object's string representation.
			virtual String toString() const;

			friend std::ostream & operator<<(std::ostream & os, Object const & object);

		protected:
			/// Returns a clone of the current Object.
			///
			/// This method actually does nothing exception copying onto
			/// the stack the current Object, in order for it to be
			/// transferred back to the caller.
			/// \return a copy of the current object.
			inline virtual Object clone() const { return *this; }

			/// Performs a final cleanup.
			/// 
			/// Cleans up any resources associated with this object,
			/// before its associated memory is recalled. It really 
			/// does nothing on this class, but it can be overridden.
			inline virtual void finalize() { }
		};
	}
}

#endif // JAVA_LANG_OBJECT

