/*
 * Interface.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_INTERFACE
#define JAVA_LANG_INTERFACE

#include <java/lang/Class.h>

namespace java {
	namespace lang {

		class Interface : public Class {
		public:

			/// The Interface' object Class.
			static const Class klass;

			/// Constructor.
			///
			/// Creates an instance of an Interface object.
			/// \param name the name of the interface.
			Interface(String const & name);

			/// Constructor.
			///
			/// Creates an instance of an Interface object; it stores the 
			/// names of the (directly) implemented interfaces into the 
			/// Interface; any interfaces implemented by superinterfaces
			/// are assumed to be stored there. 
			/// \param name the name of the interface
			/// \param a variable list of Interfaces representing the 
			///        implemented interfaces
			Interface(String const & name, std::initializer_list<Interface const *> interfaces);

			/// Returns whether this type represents an Interface.
			///
			/// Returns whether this type represents an Interface.
			/// \return whether this type represents an Interface.
			inline virtual jboolean isInterface() const {
				return true;
			}

			/// Returns the Class object representing this class.
			///
			/// Returns the Class object representing this class.
			/// \return the Class object representing the class.
			inline virtual Class const & getClass() const {
				return Interface::klass;
			}		
		};				
	}
}

#endif // JAVA_LANG_INTERFACE

