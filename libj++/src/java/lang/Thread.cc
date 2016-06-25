/*
 * Thread.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/Thread.h>				

#include <assert.h>

 namespace java {
 	namespace lang {

		Class const & Thread::klass() {
			static const Class klass("java.lang.Thread", &Object::klass(), { &Runnable::klass() });
			return klass;
		}		 

		Thread::Thread()
		: runnable_(nullptr)
		, thread_(nullptr) {	
		}

		Thread::Thread(Runnable * runnable)
		: runnable_(runnable)
		, thread_(nullptr) {			
		}

		Thread::Thread(String const & name)
		: runnable_(nullptr)
		, thread_(nullptr) 
		, name_(name) {
		}			

		Thread::Thread(Runnable * runnable, String const & name)
		: runnable_(runnable)
		, thread_(nullptr)
		, name_(name) {			
		}

		jlong Thread::getId() const {
			jlong id = -1;
			if(thread_ != nullptr) {
				std::stringstream stream;
				stream << thread_->get_id();
				stream >> id;
			}
			return id;
		}

		/// A bridge between Runnable::run() and std::thread.
		///
		/// This static function is used as a bridge between the
		/// Runnable's run() method and the way the std::thread
		/// API expects a __cdecl or __stdcall (that is, non 
		/// _thiscall) method as the implementation of the Thread's 
		/// business logic; the trick is provided by the first
		/// parameter to this method, which is the Runnable pointer
		/// and can therefore be used to access the virtual run() 
		/// method.
		/// \param runnable a pointer to the Runnable to execute. 
		static void bridge(Runnable * runnable) {
			if(runnable != nullptr) {
				runnable->run();
			}
		}		

		void Thread::start() {
			if(thread_ != nullptr) {
				throw /*IllegalthreadState*/Exception("Cannot start a Thread twice.");
			}
			if(runnable_ != nullptr) {
				thread_ = new std::thread(bridge, this->runnable_);
			} else {
				thread_ = new std::thread(bridge, this);
			}
		}

		void Thread::join() {
			if(thread_ != nullptr) {
				thread_->join();
			}
		}

		void Thread::sleep(long long millis) {
			std::this_thread::sleep_for(std::chrono::milliseconds(millis));			
		}

		void Thread::sleep(long long millis, int nanos) {
			long long pause = millis * 1000 + nanos;
			std::this_thread::sleep_for(std::chrono::nanoseconds(pause));			
		}

		void Thread::yield() {
			std::this_thread::yield();
		}	
 	}
 }