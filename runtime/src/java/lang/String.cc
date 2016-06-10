/*
 * String.cc
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
