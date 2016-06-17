/*
 * Number.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_NUMBER
#define JAVA_LANG_NUMBER

#include <java/lang/Object.h>
#include <java/lang/Class.h>
#include <sstream>
#include <iomanip>

namespace java {
	namespace lang {
		class Number : public Object {
		public:
			/// The Numbers' Class object.
			static const Class klass;

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual Class const & getClass() const {
				return Number::klass; 
			}

			/// Returns the value of the specified number as a byte.
			/// 
			/// Returns the value of the specified number as a byte. This may 
			/// involve rounding or truncation
			/// \return the numeric value represented by this object after 
			/// conversion to type byte.
			virtual jbyte byteValue() const = 0;

			/// Returns the value of the specified number as a short.
			///
			/// Returns the value of the specified number as a short. This may 
			/// involve rounding or truncation.
			/// \return the numeric value represented by this object after 
			/// conversion to type short.
			virtual jshort shortValue() const = 0;

			/// Returns the value of the specified number as an int.
			///
			/// Returns the value of the specified number as an int. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type int.
			virtual jint intValue() const = 0;

			/// Returns the value of the specified number as a long.
			///
			/// Returns the value of the specified number as a long. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type long.
			virtual jlong longValue() const = 0;

			/// Returns the value of the specified number as a float.
			///
			/// Returns the value of the specified number as a float. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type float.
			virtual float floatValue() const = 0;

			/// Returns the value of the specified number as a double.
			///
			/// Returns the value of the specified number as a double. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type double.
			virtual double doubleValue() const = 0;

			/// Converts the given Number to an hexadecimal String.
			///
			/// Converts the current Number to an hexadecimal String.
			/// \param the Number to be converted to its hex representation.
			/// \return a String with the hexadecimal representation of the Number
			template <typename T> static inline String toHexString(T const & t);
		};

		template <typename T> 
		String Number::toHexString(T const & t) {
			std::stringstream stream;
			stream << "0x" << std::hex << t;
			return String(stream.str().c_str());
		}
	}
}


#endif // JAVA_LANG_NUMBER

