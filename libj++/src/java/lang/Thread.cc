/*
 * Thread.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/Thread.h>
#include <thread>
#include <sstream>
#include <iomanip>				

#include <assert.h>

 namespace java {
 	namespace lang {
 		const Class Thread::klass("java.lang.Thread", Object::klass, { "java.lang.Runnable" });

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
		, thread_(nullptr),
		name_(name) {			
		}

		long long Thread::getId() const {
			long long id = -1;
			if(thread_ != nullptr) {
				std::stringstream stream;
				stream << thread_->get_id();
				stream >> id;
			}
			return id;
		}

		void Thread::start() {
			if(thread_ != nullptr) {
				throw /*IllegalthreadState*/Exception("Cannot start a Thread twice.");
			}
			if(runnable_ != nullptr) {
//				thread_ = new std::thread(runnable_->run, this->runnable_);
			} else {
//				thread_ = new std::thread(run, this);
			}
		}
 	}
 }