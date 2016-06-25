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

			/// Returns a reference to the shared Class object.
			///
			/// Returns the shared reference to the Class object for 
			/// this class; all object share the same instance, which 
			/// is a local static constant object: this makes sure that 
			/// the Class object is initialised as soon as this class
			/// is reerences, and that there is no problem with concurrent
			/// access since it can only be instantiated once (see 
			/// Scott Meyers, Effective C++, Item 4).
			/// \return a reference to the shared Class object.
			static Class const & klass();

			/// Returns the current timestamp in millliseconds.
			///
			/// Returns the current timestamp as the number of milliseconds 
			/// since the Epoch.
			/// \return the current timestamp in milliseconds.
			static jlong currentTimeMillis();

			/// Terminates the currently running pseudo-VM.
			///
			/// Terminates the currently running pseudo-VM, returning 
			/// the given exit code.
			/// \param status the process' exit code to return.
			static void	exit(jint status);

			/// Runs the garbage collector.
			///
			/// This method does noting in release builds; in debug builds
			/// it may dump all the outstanding memory blocks allocated via
			/// operators new and new[], and may therefore help finding any
			/// memory leaks.
			static void gc();

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return System::klass(); 
			}


		private:
			
			/// Default constructor.
			System() : Object() { throw new UnsupportedOperationException("Cannot instantiate an object of class java.lang.System."); }
					
		protected:

			/// Performs a clone of the System, object.
			///
			/// The clone operation is not supported, so this
			/// method will throw a CloneNotSupportedException.
			virtual Object clone() const { throw new CloneNotSupportedException("Cannot clone an object of type java.lang.System."); }
		};
	}
}
#endif // JAVA_LANG_SYSTEM

