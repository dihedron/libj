/*
 * VM.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */
#ifndef LIBJPP_VM
#define LIBJPP_VM

/// The boolean type, with a proper C++ name.
typedef bool 			jboolean;

/// The character type, with a proper C++ name.
typedef char			jchar;

/// The byte type (8 bits).
typedef unsigned char	jbyte;

/// The short integer type (usually 16 bits).
typedef short			jshort;

/// The integer type (usually 32 bits).
typedef int				jint;

/// The long integer type (usually 64 bits).
typedef long long		jlong;

/// The real (floating point) number type.
typedef float			jfloat;

/// The double precision real (floating point) number type.
typedef double			jdouble;

//
// LANGUAGE EXTENSIONS 
//
// These are macros that help reduce the impedance mismatch
// between Java and C++ in terms of keywords.
//
#ifndef interface
#	define 	interface 		class
#endif

#ifndef instanceof
#	define instanceof(T)	.instanceOf(T::klass)
#endif 

//
// TRACES
//
#define DBG 	std::cout << "[D] "
#define INF 	std::cout << "[I] "
#define WRN 	std::cout << "[W] "
#define ERR 	std::cout << "[E] "

#define ENDC	std::endl;

#endif // LIBJPP_VM
