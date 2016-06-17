/*
 * Thread.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */



#ifndef JAVA_LANG_THREAD
#define JAVA_LANG_THREAD

#include <java/lang/Object.h>
#include <java/lang/Class.h>
#include <java/lang/Runnable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <thread>


namespace java {
	namespace lang {
		class Thread : public Object, public Runnable {
		public:
			/// The Threads' Class object.
			static const Class klass;

			/// Default constructor.
			Thread();

			/// Constructor.
			///
			/// A constructor based on a Runnable.
			/// \param runnable the Runnable object implementing the Thread's logic.
			Thread(Runnable * runnable);

			/// Constructor.
			///
			/// A constructor providing the thread's name.
			/// \param the name of the Thread
			Thread(String const & name);

			/// Constructor.
			///
			/// A constructor providing both the Runnable and the Thread's name.
			/// \param runnable the Runnable object implementing the Thread's logic.
			/// \param the name of the Thread
			Thread(Runnable * runnable, String const & name);

			/// Returns the identifier of this Thread. 
			///
			/// The thread ID is a positive long number generated when this thread 
			/// was created. The thread ID is unique and remains unchanged during 
			/// its lifetime. When a thread is terminated, this thread ID may be reused.
			/// \return the Thread id.
			jlong getId() const;
			

			/// Sets the name of the Thread.
			///
			/// Sets the name of the Thread to the given value.
			/// \param name the new name of the Thread.
			inline void setName(String const & name) {
				name_ = name;
			}

			/// Returns the name of the Thread.
			///
			/// Returns the name of the Thread; if no name is explicitly
			/// provided, a name is generated.
			/// \return the nam eof the Thread.
			inline String const & getName() const { 
				return name_;
			}

			/// Starts the thread.
			///
			/// Starts the thread, executing the logic that is either in the
			/// provided Runnable, or in the overridden run() method.
			void start();

			/// Waits for the thread to finish.
			///
			/// Puts the calling thread in wait for the given thread to 
			/// complete its processing; this method only returns when the
			/// Thread object has finished.
			void join();

			/// The actual implementation of the Thread.
			///
			/// This method can be overridden by any sub-class; it if is not, 
			/// and a Runnable is provided instead, the Runnable's run method 
			/// is invoked.
			virtual void run() { }

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return Thread::klass; 
			}

			/// Puts the calling Thread to sleep.
			///
			/// Puts the calling Thread to sleep for at least the given
			/// number of milliseconds.
			/// \param millis the minimum number of milliseconds to sleep.
			static void sleep(long long millis);

			/// Puts the calling Thread to sleep.
			///
			/// Puts the calling Thread to sleep for at least the given
			/// number of milliseconds and nanoseconds, depending on the
			/// precision of the system scheduler's clock.
			/// \param millis the minimum number of milliseconds to sleep.
			/// \param nanos the additional number of nanoseconds to sleep.
			static void sleep(long long millis, int nanos);

			/// Yield the CPU to other Threads.
			///
			/// Suggests the system to yield CPU time to other Threads.
			static void yield();

		protected:
			/// Returns a clone of the current Object.
			///
			/// This method actually does nothing exception copying onto
			/// the stack the current Object, in order for it to be
			/// transferred back to the caller.
			/// \return a copy of the current object.
			inline virtual Object clone() const { throw CloneNotSupportedException("Cannot clone a Thread."); }		
			
		private:
			/// The optional Runnable object. 
			Runnable * runnable_;

			/// The underlying STL thread object.
			std::thread * thread_;

			/// The optional name of the Thread.
			String name_;
		};
	}
}


#endif // JAVA_LANG_THREAD

