/*
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

#ifndef JAVA_LANG_OBJECT
#define JAVA_LANG_OBJECT

#include <java/lang/ValueTypes.h>
#include <macros.h>
#include <iostream>

namespace java {
    namespace lang {
        
        class Class;
        class String;
        
        /// The root of the object's hierarchy.
        ///
        /// The object class lies at the root of the objects'
        /// hierarchy; each class must inherit from Object, and
        /// gets some methgod for free, such as hashCode() and
        /// toString().
        class Object {
        public:
            
			/// Default constructor.
            Object() { }

            /// Constructor.
            ///
            ///	Creates a new object, copying the contents of another
            /// object instance.
            /// \param other the object to be copied
            Object(const Object & other) { }
				
            /// Destructor.
            virtual ~Object() { }

            /// Assignment operator.
            ///
            /// A do-nothing assignment operator.
            /// \param other the object to copy from.
            Object & operator=(Object const & other) { std::cout << "copying" << std::endl; return *this; }
            
            /// Compares this object to another for equality.
            ///
            /// Compares this instance of object to the other one,
            /// returning true if and only if the two objects are 
            /// the exact same instance.
            /// \param other the object to be compared with this one.
            /// \return true if the other object is the same instance 
            /// as this one.
            inline virtual boolean equals(Object const & other) const { 
                return (this == &other); 
            }
            
            /// Returns the object's hashcode.
            ///
            /// Returns the object's hash code, which is ideally unique;
            /// as a matter of fact, it returns the object's address in
            /// memory, so that no two objects can share the same address 
            /// unless they are the same object.
            /// \return the object's hash code.
            inline virtual long long hashCode() const { 
                return reinterpret_cast<long long>(this);
            }

            /// Returns the object's class.
            /// 
            /// Returns the object's class object.
            /// \return the object's class object.
            inline virtual Class & getClass() const {
                return Object::klass; 
            }

            /// Returns a string preresentation of the object.
            ///
            /// This method provides a string representation of the 
            /// object; it can be used to customise the way the object
            /// is printed out to a text stream.
            /// \return the object's string representation.
            virtual String toString() const;

            friend std::ostream & operator<<(std::ostream & os, Object const & object);

        protected:
                virtual Object clone() const { }
                virtual void finalize() { }
        private:
            
            /// The shared reference to the Class object for this
            /// class; all object share the same instance.
            static Class klass;

        };
    }
}
#endif // JAVA_LANG_OBJECT

