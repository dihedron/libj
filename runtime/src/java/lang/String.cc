/*
 * String.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#include <java/lang/String.h>
#include <java/lang/Class.h>

namespace java {
	namespace lang {

		Class String::klass("java.lang.String");

		String & String::operator=(String const & other) {
			std::cout << "copying string" << std::endl;
			if(this != &other) {
				this->value_= other.value_;
			}
			return *this;
		}

		Class & String::getClass() const { 
			 return String::klass; 
		}

		String String::toString() const {			
			return *this;
		}		

		String String::operator+(String const & string) const {
			return String(this->value_ + string.value_);
		}
		
		String String::operator+(long value) const {
			return valueOf(value);//String("copia con intero");
		}

		String String::operator+(long long value) const {
			return valueOf(value);//String("copia con long long");
		}
		
		std::ostream & operator<<(std::ostream & os, String const & string) {
			os << string.value_;
			return os;
		}
	}
}
