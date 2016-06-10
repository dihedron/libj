/*
 * Integer.h
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

#ifndef JAVA_LANG_LONG
#define JAVA_LANG_LONG

#include <java/lang/Object.h>
#include <java/lang/Class.h>
#include <sstream>
#include <iomanip>

namespace java {
	namespace lang {
		class Long : public Object {
        public:

        	template <typename T> static inline String toHexString(T const & t);
            
            Integer() : value_(0) { }
            Integer(int value) : value_(value) { }
            Integer(const Integer & other) : value_(other.value_) { }
			
            virtual ~Integer() { }

            virtual Class & getClass() const;

            virtual String toString() const;

            operator int() const { return value_; };

            Integer operator+(int value) const { return Integer(value_ + value); }
			Integer operator+(long value) const { return Integer(value_ + (int)value); }	
            Integer operator+(long long value) const { return Integer(value_ + (int)value); }

            Integer operator+(Integer const & other) const { return Integer(value_ + other.value_); }

			friend std::ostream & operator<<(std::ostream & os, Integer const & integer);
		private:
			int value_;

			/// The Integers' Class object.
			static Class klass;
		};

        template <typename T> 
        String Integer::toHexString(T const & t) {
			std::stringstream ss;
			ss << "0x" << std::hex << t;
            return String(ss.str());
        }
	}
}


#endif // JAVA_LANG_INTEGER

