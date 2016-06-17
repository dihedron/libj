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
			/// The Runnable Interface object.
			static const Interface klass;			

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

