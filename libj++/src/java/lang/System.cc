/*
 * System.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

 #include <java/lang/System.h>
 #include <java/lang/Class.h>
 #include <chrono>
 #include <stdlib.h>

namespace java {
	namespace lang {

		Class const & System::klass() {
			static const Class klass("java.lang.System", &Object::klass());
			return klass;
		}
		
		jlong System::currentTimeMillis() {
 			return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		}

		void System::exit(jint status) {
			::exit(status);
		}		

		void System::gc() {
#ifdef NDEBUG
#else
#endif						
		}
 	}
}