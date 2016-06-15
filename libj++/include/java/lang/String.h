/*
 * String.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */


#ifndef JAVA_LANG_STRING
#define JAVA_LANG_STRING

#include <java/lang/Object.h>
#include <iostream>
#include <string>
#include <sstream>

namespace java {
	namespace lang {
		
		class String : public Object {
		public:
						
			/// Factory method for converting values to a String.
			///
			/// Converts a value or a type to String, if an appropriate conversion
			/// can be performed. there is no need to supply the template type
			/// unless the compiler is incapable of figuring it out by itself.
			/// \param t the value to be converted to a String
			/// \return a String object representing the given value.
			template <typename T> static inline String valueOf(T const & t);
			
			/// Default constructor.
			///
			/// Creates an empty string.
			String() : value_("") { }

			/// Copy constructor.
			///
			/// Creates a new String, copying the other object's contents.
			/// \param other the string to copy from.
			String(const String & other) : value_(other.value_) { }

			/// Constructor.
			///
			/// Creates a String initialising it to the given C-style string.
			/// \param string the C-style string to copy from.
			String(const char * string) : value_(string) { }  

			/// Destructor.
			///
			/// Cleans up the object.
			virtual ~String() { 
				finalize();
			}

			/// Assignment operator.
			///
			/// A do-nothing assignment operator.
			/// \param other the object to copy from.
			String & operator=(String const & other);

			/// Returns the object's class.
			///
			/// Returns a Class object representing this object's class.
			/// \return a Class object representing Strings.
			virtual Class & getClass() const;

			/// Returns the String itself.
			///
			/// Overrides the generit tostring() method returning the String itself.
			/// \return the string itself.
			virtual String toString() const;

			String operator+(String const & string) const;
			String operator+(long value) const;	
			String operator+(long long value) const;

			/// Compares two strings.
			///
			/// Lexicographically compares two strings, returning whether
			/// this one precedes the other one.
			/// \param other the String to compare against
			/// \return whether this String comes before the other
			inline virtual bool operator<(String const & other) {
				return *this < other;
			}

			/// Compares two strings.
			///
			/// Lexicographically compares two strings, returning whether
			/// this one comes after the other one.
			/// \param other the String to compare against
			/// \return whether this String comes after the other
			inline virtual bool operator>(String const & other) {
				return *this > other;
			}			 

			friend std::ostream & operator<<(std::ostream & os, String const & string);

			/// Cleans up the object's internal status.
			inline virtual void finalize() {
				//std::cout << "finalize in String" << std::endl;
			}

		private:
			/// Constructor.
			///
			/// Creates a new String object and initialises it using the 
			/// given STL string object's value.
			/// \param string an STL string object to use for initialisation
			String(std::string const & string) : value_(string) { } 
	
			/// The uderlying String's value.
			std::string value_;   

			/// The Strings' shared class object.
			static Class klass;
		};

		template <typename T> 
		String String::valueOf(T const & t) {
			std::stringstream ss;
			ss << t;
			return String(ss.str());
		}				
	}
}

#endif // JAVA_LANG_STRING

