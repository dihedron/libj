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

using namespace java::lang;


static void testClasses() {
	String s;
	std::cout << "a String's class is \"" << s.getClass() << "\": \"" << s.getClass().getName() << "\"" << std::endl;	

	Integer i;
	std::cout << "a Integer's class is \"" << i.getClass() << "\": \"" << i.getClass().getName() << "\"" << std::endl;	
}

static void testStrings() {
	String s("hallo, world!");    
    std::cout << "string " << s << " (\"" << s.toString() << "\") has hashCode " << s.hashCode() << " and class " << s.getClass().getName() << std::endl;

    String s1("s1"), s2("s2");
    std::cout << "s1: \"" << s1 << "\", s2: \"" << s2 << "\"" << std::endl; 
    s2 = s1;
    std::cout << "s1: \"" << s1 << "\", s2: \"" << s2 << "\"" << std::endl; 
}

static void testIntegers() {
    Integer i(10);
    std::cout << "integer " << i << " (\"" << i.toString() << "\") has hashCode " << i.hashCode() << " and class " << i.getClass().getName() << std::endl;	
}

/*
 * 
 */
int main(int argc, char** argv) {

	std::cout << "hallo from libj++ ver." << LIBJPP_VERSION_MAJOR << "." << LIBJPP_VERSION_MINOR << "!" << std::endl;    

    testClasses();

    testStrings();

    testIntegers();

    std::cout << "current time millis: " << System::currentTimeMillis() << std::endl;
    
    return 0;
}

