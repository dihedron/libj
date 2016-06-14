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

#ifndef interface
#	define interface class
#endif // interface

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

			/// Constructor.
			///
			///	Creates a new object, copying the contents of another
			/// object instance.
			/// \param other the object to be copied
			Object(const Object & other) { }
	
			/// Destructor.
			///
			/// The default destructor does nothing, except invoking
			/// the finalize() method.
			virtual ~Object() { 
				finalize();
			}

			/// Assignment operator.
			///
			/// A do-nothing assignment operator.
			/// \param other the object to copy from.
			Object & operator=(Object const & other) { std::cout << "copying" << std::endl; return *this; }
						
			/// Compares this object to another for equality.
			///
			/// Compares this instance of object to the other one,
			/// returning true if and only if the two objects are 
			/// the exact same instance.
			/// \param other the object to be compared with this one.
			/// \return true if the other object is the same instance 
			/// as this one.
			inline virtual boolean equals(Object const & other) const { 
				return (this == &other); 
			}
						
			/// Returns the object's hashcode.
			///
			/// Returns the object's hash code, which is ideally unique;
			/// as a matter of fact, it returns the object's address in
			/// memory, so that no two objects can share the same address 
			/// unless they are the same object.
			/// \return the object's hash code.
			inline virtual long long hashCode() const { 
				return reinterpret_cast<long long>(this);
			}

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return Object::klass; 
			}

			/// Returns a string preresentation of the object.
			///
			/// This method provides a string representation of the 
			/// object; it can be used to customise the way the object
			/// is printed out to a text stream.
			/// \return the object's string representation.
			virtual String toString() const;

			friend std::ostream & operator<<(std::ostream & os, Object const & object);

		protected:
			virtual Object clone() const { }

			/// Performs a final cleanup.
			/// 
			/// Cleans up any resources associated with this object,
			/// before its associated memory is recalled.
			virtual void finalize() { }
		};
	}
}

#endif // JAVA_LANG_OBJECT

