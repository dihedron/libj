/*
 * Integer.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_INTEGER
#define JAVA_LANG_INTEGER

#include <java/lang/Number.h>
#include <java/lang/Class.h>
#include <sstream>
#include <iomanip>

namespace java {
	namespace lang {
		class Integer : public Number {
		public:

			/// The Integers' Class object.
			static const Class klass;				  

			/// Default constructor.
			///
			/// Creates a new Integer object, initialising its value to 0.
			Integer() : value_(0) { }

			/// Constructor.
			///
			/// Creates a new Integer, initialising it to the given value.
			/// \param value the value to use for initialisation.
			Integer(jbyte value) : value_(value) { }

			/// Constructor.
			///
			/// Creates a new Integer, initialising it to the given value.
			/// \param value the value to use for initialisation.
			Integer(jshort value) : value_(value) { }

			/// Constructor.
			///
			/// Creates a new Integer, initialising it to the given value.
			/// \param value the value to use for initialisation.
			Integer(jint value) : value_(value) { }

			/// Returns this Integer's class object.
			///
			/// Returns this Integer's class object; the returned object
			/// is shared among all instances.
			/// \return the Class object.
			inline virtual Class const & getClass() const {
				return Integer::klass; 
			}				  

			/// Returns the value of the specified number as a byte.
			/// 
			/// Returns the value of the specified number as a byte. This may 
			/// involve rounding or truncation
			/// \return the numeric value represented by this object after 
			/// conversion to type byte.
			virtual jbyte byteValue() const;

			/// Returns the value of the specified number as a short.
			///
			/// Returns the value of the specified number as a short. This may 
			/// involve rounding or truncation.
			/// \return the numeric value represented by this object after 
			/// conversion to type short.
			virtual jshort shortValue() const;

			/// Returns the value of the specified number as an int.
			///
			/// Returns the value of the specified number as an int. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type int.
			virtual jint intValue() const;

			/// Returns the value of the specified number as a long.
			///
			/// Returns the value of the specified number as a long. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type long.
			virtual jlong longValue() const;

			/// Returns the value of the specified number as a float.
			///
			/// Returns the value of the specified number as a float. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type float.
			virtual float floatValue() const;

			/// Returns the value of the specified number as a double.
			///
			/// Returns the value of the specified number as a double. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type double.
			virtual double doubleValue() const;

			/// Returns the Integer as a String.
			/// 
			/// Returns the string representation of the Integer.
			/// \return the Integer as a String.			 
			virtual String toString() const;

			operator int() const { return (int)value_; };

			Integer operator+(jshort value) const { return Integer(value_ + value); }
			Integer operator+(jint value) const { return Integer(value_ + value); }	
			Integer operator+(jlong value) const { return Integer(value_ + (jint)value); }

			Integer operator+(Integer const & other) const { return Integer(value_ + other.value_); }

			friend std::ostream & operator<<(std::ostream & os, Integer const & integer);

		private:
			jint value_;
		};
	}
}


#endif // JAVA_LANG_INTEGER

