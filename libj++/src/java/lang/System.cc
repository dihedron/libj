/*
 * System.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

 #include <java/lang/System.h>
 #include <java/lang/Class.h>
 #include <chrono>

 namespace java {
 	namespace lang {
 		const Class System::klass("java.lang.System", Object::klass);

 		long long System::currentTimeMillis() {
 			return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
 		}
 	}
 }