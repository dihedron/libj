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

			/// The Strings' shared class object.
			static const Class klass;		
						
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

			/// Constructor.
			///
			/// Creates a String initialising it to the given C-style string.
			/// \param string the C-style string to copy from.
			String(const char * string) : value_(string) { }  

			/// Returns the last occurrence of the specified character.
			/// 
			/// Returns the index within this string of the last occurrence 
			/// of the specified character.
			/// \param ch the character to look for
			/// \return the index of the character, -1 if not found.
  			inline int lastIndexOf(char ch) const { 
				return value_.find_last_of(ch);
			}

			/// Returns the last occurrence of the specified character.
			/// 
			/// Returns the index within this string of the last occurrence 
			/// of the specified character, searching backward starting at 
			/// the specified index.
			/// \param ch the character to look for
			/// \param fromIndex
			/// \return the index of the character, -1 if not found.
  			inline int lastIndexOf(char ch, int fromIndex) const { 
				return value_.find_last_of(ch, fromIndex);
			}
			
/*
 int 	lastIndexOf(String str)
          Returns the index within this string of the rightmost occurrence of the specified substring.
 int 	lastIndexOf(String str, int fromIndex)
          Returns the index within this string of the last occurrence of the specified substring, searching backward starting at the specified index.
		  */

			/// Returns the length of this String.
			///
			/// Returns the length of this String, 0 if the String
			/// is empty.
			/// \return the length of the String
			inline int length() const {
				return (int)value_.size();
			}     

			/// Returns a new string that is a substring of this string.
			/// 
			/// Returns a new string that is a substring of this string,
			/// starting at the the given index until the end
			/// \param beginIndex the index of the first included character
			/// \return a substring, starting at the given index
			inline String substring(int beginIndex) const {
				return String(value_.substr(beginIndex).c_str());
			}

			/// Returns a new string that is a substring of this string.
			/// 
			/// Returns a new string that is a substring of this string,
			/// between the given start (included) and end (excluded) positions
			/// \param beginIndex the index of the first included character
			/// \param endIndex the index of the first excluded character
			/// \return a substring, between the two indexes
			inline String substring(int beginIndex, int endIndex) const {
				return String(value_.substr(beginIndex, endIndex).c_str());
			}

			/// Returns the object's class.
			///
			/// Returns a Class object representing this object's class.
			/// \return a Class object representing Strings.
			inline virtual Class const & getClass() const {
				return String::klass;
			}

			/// Returns the String itself.
			///
			/// Overrides the generic toString() method returning a copy
			/// of the String itself (for compliance with the original  
			/// method signature).
			/// \return a copy of the String itself.
			inline virtual String toString() const {
				return *this;
			}

			/// Concatenates two strings.
			///
			/// Concatenates this string with the other, returning a new
			/// String as a result.
			/// \param string the String to append to this one.
			/// \return a new String containing the two Strings.
			String operator+(String const & string) const;

			/// Concatenates an 8-bit integer to this String.
			///
			/// Concatenates this string with the given 8 bits integer, 
			/// returning a new String as a result.
			/// \param value the 8 bits value to append to this one.
			/// \return a new String containing the concatenation.				
			String operator+(jbyte value) const;

			/// Concatenates a 16-bit integer to this String.
			///
			/// Concatenates this string with the given 16 bits integer, 
			/// returning a new String as a result.
			/// \param value the 16 bits value to append to this one.
			/// \return a new String containing the concatenation.				
			String operator+(jshort value) const;

			/// Concatenates a 32-bit integer to this String.
			///
			/// Concatenates this string with the given 32 bits integer, 
			/// returning a new String as a result.
			/// \param value the 32 bits value to append to this one.
			/// \return a new String containing the concatenation.				
			String operator+(jint value) const;
			
			/// Concatenates a 64-bit long to this String.
			///
			/// Concatenates this string with the given 64 bits long, 
			/// returning a new String as a result.
			/// \param value the 64 bits value to append to this one.
			/// \return a new String containing the concatenation.				
			String operator+(jlong value) const;

			inline virtual jboolean operator==(String const & other) const {
				return value_ == other.value_;
			}

			/// Compares two strings.
			///
			/// Lexicographically compares two strings, returning whether
			/// this one precedes the other one.
			/// \param other the String to compare against
			/// \return whether this String comes before the other
			inline virtual bool operator<(String const & other) const {
				return value_ < other.value_;
			}

			/// Compares two strings.
			///
			/// Lexicographically compares two strings, returning whether
			/// this one comes after the other one.
			/// \param other the String to compare against
			/// \return whether this String comes after the other
			inline virtual bool operator>(String const & other) const {
				return value_ > other.value_;
			}			 

			friend std::ostream & operator<<(std::ostream & os, String const & string);

		private:
			/// Constructor.
			///
			/// Creates a new String object and initialises it using the 
			/// given STL string object's value.
			/// \param string an STL string object to use for initialisation
			String(std::string const & string) : value_(string) { } 
	
			/// The uderlying String's value.
			std::string value_;   
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

