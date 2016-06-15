/*
 * Thread.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

 #include <java/lang/Thread.h>
 #include <thread>

 namespace java {
 	namespace lang {
 		const Class Thread::klass("java.lang.Thread", Object::klass, { "java.lang.Runnable" });

		 void Thread::run() {
			 if(runnable_ != nullptr) {
				 runnable_->run();
			 }
		 }
 	}
 }