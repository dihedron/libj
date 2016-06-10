/*
 * Class.h
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

#ifndef JAVA_LANG_CLASS
#define JAVA_LANG_CLASS

#include <java/lang/Object.h>
#include <java/lang/String.h>

namespace java {
    namespace lang {

    	class Number;
        
        class Class : public Object {
        public:
				
            Class(String const & name);
				
            Class(const Class & other);
				
            virtual ~Class() { }

            virtual Class & getClass() const {
            	return Class::klass;
            }

			String const & getName() const {
				return name_;
			}

			String toString() const;
				
        private:
			String name_;

			/// The Class' object Class.
			static Class klass;			
        };        
    }
}

#endif // JAVA_LANG_CLASS

