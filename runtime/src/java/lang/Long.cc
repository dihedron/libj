/*
 * Long.cc
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
#include <java/lang/Long.h>
#include <java/lang/String.h>

namespace java {
	namespace lang {

		const Class Long::klass("java.lang.Long", Number::klass);


		byte Long::byteValue() const {
			return (byte)value_;
		}

		double Long::doubleValue() const {
			return (double)value_;
		}

        float Long::floatValue() const {
        	return (float)value_;
        }

        int Long::intValue() const {
        	return (int)value_;
        }

        long Long::longValue() const {
        	return (long)value_;
        }

        short Long::shortValue() const {
        	return (short)value_;
        }

		String Long::toString() const {			
			return String::valueOf(this->value_);
        }	

		std::ostream & operator<<(std::ostream & os, Long const & number) {
			os << number.value_;
			return os;
		}
	}
}