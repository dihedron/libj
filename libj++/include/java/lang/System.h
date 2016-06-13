/*
 * System.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#ifndef JAVA_LANG_SYSTEM
#define JAVA_LANG_SYSTEM

#include <java/lang/Object.h>
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
		class System : public Object {
		public:

			/// The shared reference to the Class object for this
			/// class; all object share the same instance.
			static const Class klass;


			static long long currentTimeMillis();

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
			System() : Object() { throw new Object(); }

			/// Constructor.
			///
			///	Creates a new object, copying the contents of another
			/// object instance.
			/// \param other the object to be copied
			System(const System & other) : Object(other) { throw new Object(); }
	
			/// Destructor.
			///
			/// The default destructor does nothing, except invoking
			/// the finalize() method.
			virtual ~System() { 
				finalize();
			}

			/// Assignment operator.
			///
			/// A do-nothing assignment operator.
			/// \param other the object to copy from.
			System & operator=(System const & other) { throw new Object(); return *this; }
					
		protected:

			virtual Object clone() const { throw new Object(); }

			/// Performs a final cleanup.
			/// 
			/// Cleans up any resources associated with this object,
			/// before its associated memory is recalled.
			virtual void finalize() { }
		};
	}
}
#endif // JAVA_LANG_OBJECT

