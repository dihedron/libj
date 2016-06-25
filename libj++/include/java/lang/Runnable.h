/*
 * Runnable.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_RUNNABLE
#define JAVA_LANG_RUNNABLE

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		/// A pure virtual class implementing the Runnable interface.
		interface Runnable {
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

			/// The method implementing the logic to be run in a separate thread.
			///
			/// When an object implementing interface Runnable is used to create 
			/// a thread, starting the thread causes the object's run method to 
			/// be called in that separately executing thread. The general contract 
			/// of the method run is that it may take any action whatsoever.
			virtual void run() = 0; 
		};				
	}
}

#endif // JAVA_LANG_RUNNABLE

