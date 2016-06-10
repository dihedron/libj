/*
 * Class.cc
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

#include <java/lang/Class.h>
#include <java/lang/Number.h>

namespace java {
	namespace lang {
				
		Class Class::klass("java.lang.Class");

		Class::Class(String const & name) 
			: name_(name) {
		}

		Class::Class(const Class& other) 
			: name_(other.name_) {
		}

		String Class::toString() const {
			// the name of the class must be hardcoded in this case, otherwise 
			// we sould end up in an infinite loop between toString() and getClass()
			return String("java.lang.Class@") + Number::toHexString(hashCode());
		}
	}
}

