/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 *
 * libj is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libj is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdlib>
#include <iostream>

#include <config.h>


#include <java/lang/Class.h>
#include <java/lang/String.h>
#include <java/lang/Integer.h>
#include <java/lang/System.h>
#include <java/lang/Thread.h>
#include <java/lang/CloneNotSupportedException.h>

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

	CloneNotSupportedException ex("hallo!");
	std::cout << "class name: \"" << ex.getClass().getName() << "\", simple name: \"" << ex.getClass().getSimpleName() << "\"" << std::endl;

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

static void testThreads() {
	MyRunnable r1("1"), r2("2"), r3("3"), r4("4");
	Thread t1(&r1), t2(&r2), t3(&r3), t4(&r4);

	std::cout << "---------------- TEST THREADS ----------------" << std::endl;	
	std::cout << "starting threads..." << std::endl;
	t1.start();
	t2.start();
	t3.start();
	t4.start();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	std::cout << std::endl << "... threads complete!" << std::endl;
	std::cout << "---------------- TEST THREADS ----------------" << std::endl;
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

