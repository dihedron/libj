/*
 * Integer.cc
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
#include <java/lang/Integer.h>
#include <java/lang/String.h>

namespace java {
	namespace lang {

		Class Integer::klass("java.lang.Integer");


		byte Integer::byteValue() const {
			return (byte)value_;
		}

		double Integer::doubleValue() const {
			return (double)value_;
		}

        float Integer::floatValue() const {
        	return (float)value_;
        }

        int Integer::intValue() const {
        	return value_;
        }

        long Integer::longValue() const {
        	return (long)value_;
        }

        short Integer::shortValue() const {
        	return (short)value_;
        }

		Class & Integer::getClass() const { 
			 return Integer::klass; 
		}

		String Integer::toString() const {			
			return String::valueOf(this->value_);
        }	

		std::ostream & operator<<(std::ostream & os, Integer const & integer) {
			os << integer.value_;
			return os;
		}
	}
}