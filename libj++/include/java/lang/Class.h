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

		class Class : public Object {
		public:
			/// The Class' object Class.
			static const Class klass;				 
	
			/// Constructor.
			///
			/// Creates an instance of a Class object; this is only
			/// relevant when creating the Class of the Object class,
			/// since it initiaalises the parent Class to nullptr (which
			//  is noly true at the very root of the hierarchy).
			/// \param name the name of the class
			Class(String const & name);

			/// Constructor.
			///
			/// Creates an instance of a Class object.
			/// \param name the name of the class
			/// \param super a reference to the superclass
			Class(String const & name, Class const & super);

			/// Constructor.
			///
			/// Creates an instance of a Class object; it stores the names of
			/// the (directly) implemented interfaces into the Class; any 
			/// interfaces implemented by superclasses are assumed to be 
			/// stored there. 
			/// \param name the name of the class
			/// \param super a reference to the superclass
			/// \param a variable list of Strings representing the implemented interfaces
			Class(String const & name, Class const & super, std::initializer_list<char const *> interfaces);
	
			/// Copy constructor.
			///
			/// Copies the object's internal status from the other object.
			/// \param other the object to copy from
			Class(const Class & other);
	
			/// Destructor.
			inline virtual ~Class() { 
				finalize();
			}

			/// Returns the Class object representing this class.
			///
			/// Returns the Class object representing this class; in the 
			/// case of Class, this is a reference to an instance naming 
			/// itself.
			/// \return the Class object representing the class.
			inline virtual Class const & getClass() const {
				return Class::klass;
			}

			/// Returns the superclass of this Class.
			///
			/// Returns the superclass of this Class, or nullptr if
			/// this Class represents Object, which has no parent class.
			/// \return the superclass of this Class, or nullptr.
			inline Class const * getSuperclass() const {
				return super_;
			}

			std::list<String> getInterfaces() const;

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

			/// Returns a String representation of this Class.
			/// 
			/// Returns a String representation of this Class, including 
			/// the (hardcoded) name of the Class, an "@" sign and the
			/// hexadecimal representation of the Object's hashCode().
			/// \return a String representation of this class.
			virtual String toString() const;

			/// Cleans up any memory associated with a Class object.
			inline virtual void finalize() { }
				
		private:
			/// The fully qualified name of the class.
			const String name_;

			/// A pointer to the superclass, if any, nullptr otherwise. 
			const Class * super_;

			// TODO: this must be a list, so no need to keep a count!
			std::list<String> interfaces_;
		};				
	}
}

#endif // JAVA_LANG_CLASS

