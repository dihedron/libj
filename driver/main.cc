/*
 * main.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "memleak.h"

#include <VM.h>

#include <java/lang/Class.h>
#include <java/lang/String.h>
#include <java/lang/Integer.h>
#include <java/lang/System.h>
#include <java/lang/Thread.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/util/HashMap.h>

using namespace java::lang;
using namespace java::util;

static void testClasses() {
	std::cout << "---------------- TEST CLASSES ----------------" << std::endl;
	{
		String s;
		std::cout << "a String's class is \"" << s.getClass() << "\": \"" << s.getClass().getName() << "\"" << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;	

	{
		Integer i;
		std::cout << "an Integer's class is \"" << i.getClass() << "\": \"" << i.getClass().getName() << "\"" << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		CloneNotSupportedException e("hallo!");
		std::cout << "a CloneNotSupportedException's class is \"" << e.getClass() << "\": \"" << e.getClass().getName() << "\"" << std::endl;
		for(auto i : e.getClass().getInterfaces()) {
			std::cout << " - implements interface " << i << std::endl;
		}
	}

	std::cout << "----------------------------------------------" << std::endl;

	UnsupportedOperationException ex("hallo!");
	std::cout << "class name: \"" << ex.getClass().getName() << "\", simple name: \"" << ex.getClass().getSimpleName() << "\"" << std::endl;

	{
		UnsupportedOperationException e1, e2;
		Throwable t;
		std::cout << "equal classes are equal? " << (e1.getClass() == e2.getClass()) << " (expected true)" << std::endl;
		std::cout << "different classes are equal? " << (e1.getClass() == t.getClass()) << " (expected false)" << std::endl;

		std::cout << "UnsupportedOperationException instanceof Throwable? " << (e1.instanceOf(Throwable::klass())) << " (expected true)" << std::endl;
		std::cout << "UnsupportedOperationException instanceof Exception? " << (e1.instanceOf(Exception::klass())) << " (expected true)" << std::endl;
		std::cout << "UnsupportedOperationException instanceof Object? " << (e1.instanceOf(Object::klass())) << " (expected true)" << std::endl;
		std::cout << "UnsupportedOperationException instanceof Thread? " << (e1.instanceOf(Thread::klass())) << " (expected false)" << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		UnsupportedOperationException e1;
		std::cout << "UnsupportedOperationException instanceof Throwable? " << e1 instanceof(Throwable) << " (expected true)" << std::endl;
		/*std::cout << "UnsupportedOperationException instanceof Exception? " << (e1.instanceOf(Exception::klass)) << " (expected true)" << std::endl;
		std::cout << "UnsupportedOperationException instanceof Object? " << (e1.instanceOf(Object::klass)) << " (expected true)" << std::endl;
		std::cout << "UnsupportedOperationException instanceof Thread? " << (e1.instanceOf(Thread::klass)) << " (expected false)" << std::endl;
		*/
	}
	std::cout << "---------------- TEST CLASSES ----------------" << std::endl;
}

static void testStrings() {
	std::cout << "---------------- TEST STRINGS ----------------" << std::endl;
	String s("hallo, world!");    
    std::cout << "string " << s << " (\"" << s.toString() << "\") has hashCode " << s.hashCode() << " and class " << s.getClass().getName() << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

    String s1("s1"), s2("s2");
    std::cout << "s1: \"" << s1 << "\", s2: \"" << s2 << "\"" << std::endl; 
    s2 = s1;
    std::cout << "s1: \"" << s1 << "\", s2: \"" << s2 << "\"" << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	String s3("java.lang.Class");
	std::cout << s3 << " from last dot onwards would be \"" << s3.substring(s3.lastIndexOf('.') + 1) << "\"" << std::endl;
	std::cout << s3 << " from last comma onwards would be \"" << s3.substring(s3.lastIndexOf(',') + 1) << "\"" << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	String s4("/usr/bin/man");
	std::cout << s4 << " from the / before the last is \"" << s4.substring(s4.lastIndexOf('/', 7)) << "\" (expected \"/bin/man\")" << std::endl;

	std::cout << "---------------- TEST STRINGS ----------------" << std::endl;
}

static void testIntegers() {
    Integer i(10);
    std::cout << "integer " << i << " (\"" << i.toString() << "\") has hashCode " << i.hashCode() << " and class " << i.getClass().getName() << std::endl;	
}

class MyRunnable : public Runnable {
public:

	MyRunnable(String const & symbol) : Runnable(), symbol_(symbol) { }

	void run() {
		for(int i = 0; i < 800; ++i) {
			Thread::yield();
			std::cout << symbol_;			
		}
	}
private:
	String symbol_;
};

constexpr int MAX_THREADS = 10;

static void testThreads() {
	std::cout << "---------------- TEST THREADS ----------------" << std::endl;
	std::vector<MyRunnable *> runnables;
	std::vector<Thread> threads;
	for(int i = 0; i < MAX_THREADS; ++ i) {
		MyRunnable * r = new MyRunnable(String::valueOf(i));
		runnables.push_back(r);
		threads.push_back(Thread(r));
	}

	std::cout << "starting threads..." << std::endl;
	for(auto & t : threads) {
		t.start();
	}
	for(auto & t : threads) {
		t.join();
	}

	std::cout << std::endl << "... threads complete!" << std::endl;
	std::cout << "---------------- TEST THREADS ----------------" << std::endl;

	for(auto r : runnables) {
		delete r;
	}
}

static void testHashMap() {
	std::cout << "---------------- TEST HASHMAP ----------------" << std::endl;
	HashMap<String, String> map;
	map.put("Hallo", "World");
	String * s = map.get("Hallo");
	std::cout << "value for 'Hallo' is '" << *s << "' (expected 'World')" << std::endl;
	
	std::cout << "----------------------------------------------" << std::endl;

	HashMap<Integer, String> map2;
	for(jint i = 0; i < 100; ++i) {
		map.put(i, String("number_") + i);
	}

	std::cout << "map2[24] = '" << *map.get(24) << "' (expected 'number 24')" << std::endl;

	std::cout << "---------------- TEST HASHMAP ----------------" << std::endl;
}

/*
 * 
 */
int main(int argc, char** argv) {
/*
	VM::initialise();
    
    testClasses();

    testStrings();

    testIntegers();

	testThreads();

	testHashMap();
*/
	printf("main: 1\n");
	void * pointer = malloc(1024);
	printf("main: 2\n");
	pointer = realloc(pointer, 2048);
	printf("main: 3\n");
	free(pointer);
	printf("main: 4\n");
	return 0;

    std::cout << "current time millis: " << System::currentTimeMillis() << std::endl;


	std::cout << "--------------------------------" << std::endl;
	String s("pippo"); 
	std::cout << "--------------------------------" << std::endl;

	VM::finalise();

    System::exit(0);
}

