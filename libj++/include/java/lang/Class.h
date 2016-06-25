/*
 * Class.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_CLASS
#define JAVA_LANG_CLASS

#include <java/lang/Object.h>
#include <java/lang/String.h>
#include <initializer_list>
#include <list>


namespace java {
	namespace lang {

		class Interface;

		class Class : public Object {
		public:

			/// Returns a reference to the shared Class object.
			///
			/// Returns the shared reference to the Class object for 
			/// this class; all object share the same instance, which 
			/// is a local static constant object: this makes sure that 
			/// the Class object is initialised as soon as this class
			/// is reerences, and that there is no problem with concurrent
			/// access since it can only be instantiated once (see 
			/// Scott Meyers, Effective C++, Item 4).
			/// \return a reference to the shared Class object.
			static Class const & klass();

			/// Constructor.
			///
			/// Creates an instance of a Class object.
			/// \param name the name of the class
			/// \param super a reference to the superclass
			Class(String const & name, Class const * super = nullptr);

			/// Constructor.
			///
			/// Creates an instance of a Class object; it stores the names of
			/// the (directly) implemented interfaces into the Class; any 
			/// interfaces implemented by superclasses are assumed to be 
			/// stored there. 
			/// \param name the name of the class
			/// \param super a reference to the superclass
			/// \param a variable list of implemented Interfaces
			Class(String const & name, Class const * super, std::initializer_list<Interface const *> interfaces);			

			/// Returns whether this type represents an Interface.
			///
			/// Returns whether this type represents an Interface.
			/// \return whether this type represents an Interface.
			inline virtual jboolean isInterface() const {
				return false;
			}

			/// Returns the Class object representing this class.
			///
			/// Returns the Class object representing this class; in the 
			/// case of Class, this is a reference to an instance naming 
			/// itself.
			/// \return the Class object representing the class.
			inline virtual Class const & getClass() const {
				return Class::klass();
			}

			/// Returns the superclass of this Class.
			///
			/// Returns the superclass of this Class, or nullptr if
			/// this Class represents Object, which has no parent class.
			/// \return the superclass of this Class, or nullptr.
			inline Class const * getSuperclass() const {
				return super_;
			}			

			/// Returns the name of this Class.
			///
			/// Returns the fully qualified name of this Class,
			/// including the package name.
			/// \return the name of this Class
			inline String const & getName() const {
				return name_;
			}

			/// Returns the short name of this Class.
			///
			/// Returns the short name of this Class,
			/// excluding the package name.
			/// \return the short name of this Class
			inline String getSimpleName() const {
				return name_.substring(name_.lastIndexOf('.') + 1);
			}

			/// Returns the canonical name of this Class.
			///
			/// Returns the canonical name of this Class.
			/// \return the canonical name of this Class
			inline String getCanonicalName() const {
				return getName();
			}

			/// Returns a (possibly empty) list of interfaces.
			///
			/// Returns the list of interfaces directly implemented
			/// by this class, plus all those implemented by superclasses;
			/// this list can be empty.
			/// \return the list of implemented interfaces.
			inline std::list<Interface const *> getInterfaces() const {
				return interfaces_;
			}
			
			/// Returns a String representation of this Class.
			/// 
			/// Returns a String representation of this Class, including 
			/// the (hardcoded) name of the Class, an "@" sign and the
			/// hexadecimal representation of the Object's hashCode().
			/// \return a String representation of this class.
			virtual String toString() const;

			/// Checks whether this Class is equal to the other.
			///
			/// Checks whether this Class is equal to the other.
			/// \return whether this Class is equal to the other.
			jboolean operator==(Class const & other) const;

		private:
			/// The fully qualified name of the class.
			const String name_;

			/// A pointer to the superclass, if any, nullptr otherwise. 
			const Class * super_;			

			/// A (possibly empty) list of directly implemented or
			/// extended interfaces.
			std::list<Interface const *> interfaces_;
		};				
	}
}

#endif // JAVA_LANG_CLASS

