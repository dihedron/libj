/*
 * main.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include <config.h>


#include <java/lang/Class.h>
#include <java/lang/String.h>
#include <java/lang/Integer.h>
#include <java/lang/System.h>
#include <java/lang/Thread.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/UnsupportedOperationException.h>

using namespace java::lang;

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
		std::cout << "UnsupportedOperationException instanceof Throwable? " << (e1.instanceOf(Throwable::klass)) << " (expected true)" << std::endl;
		std::cout << "UnsupportedOperationException instanceof Exception? " << (e1.instanceOf(Exception::klass)) << " (expected true)" << std::endl;
		std::cout << "UnsupportedOperationException instanceof Object? " << (e1.instanceOf(Object::klass)) << " (expected true)" << std::endl;
		std::cout << "UnsupportedOperationException instanceof Thread? " << (e1.instanceOf(Thread::klass)) << " (expected false)" << std::endl;
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

/*
 * 
 */
int main(int argc, char** argv) {
	
	std::cout << "hallo from libj++ ver." << LIBJPP_VERSION_MAJOR << "." << LIBJPP_VERSION_MINOR << "." << LIBJPP_VERSION_PATCH << "!" << std::endl;    

    testClasses();

    testStrings();

    testIntegers();

	testThreads();

    std::cout << "current time millis: " << System::currentTimeMillis() << std::endl;
    
    return 0;
}

