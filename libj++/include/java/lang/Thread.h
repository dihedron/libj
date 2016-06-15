/*
 * Number.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */



#ifndef JAVA_LANG_NUMBER
#define JAVA_LANG_NUMBER

#include <java/lang/Object.h>
#include <java/lang/Class.h>
#include <java/lang/Runnable.h>
#include <thread>

namespace java {
	namespace lang {
		class Thread : public Object, public Runnable {
		public:
			/// The Threads' Class object.
			static const Class klass;

			/// Default constructor.
			Thread() : runnable_(nullptr), thread_(nullptr) { }

			/// Copy constructor.
			///
			/// Creates a Thread object, initialising its internal status
			/// with that of the provided object.
			/// \param other the object to copy the internal status from.
			/// \todo: should we forbid copying a thread?
			Thread(Thread const & other) : runnable_(other.runnable_), thread_(other.thread_) { }

			/// Virtual destructor.
			virtual ~Thread() {
				finalize();
			}

			/// The actual implementation of the Thread.
			///
			/// This method can be overridden by any sub-class; it if is not, 
			/// and a Runnable is provided instead, the Runnable's run method 
			/// is invoked.
			virtual void run();

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return Thread::klass; 
			}

			/// Performs a clanup on the object.
			inline virtual void finalize() { }
			
		private:
			/// The optional Runnable object. 
			Runnable * runnable_;

			/// The underlying STL thread object.
			std::thread * thread_;
		};
	}
}


#endif // JAVA_LANG_THREAD

