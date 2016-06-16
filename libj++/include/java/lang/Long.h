/*
 * Long.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_LONG
#define JAVA_LANG_LONG

#include <java/lang/Number.h>
#include <java/lang/Class.h>
#include <sstream>
#include <iomanip>

namespace java {
	namespace lang {
		class Long : public Number {
		public:

			/// The Longs' Class object.
			static const Class klass;

			template <typename T> static inline String toHexString(T const & t);
						
			Long() : value_(0) { }
			Long(jshort value) : value_(value) { }
			Long(jint value) : value_(value) { }
			Long(jlong value) : value_(value) { }
			Long(const Long & other) : Number(other), value_(other.value_) { }

			virtual ~Long() { }


			/// Returns this Long's class object.
			///
			/// Returns this Long's class object; the returned object
			/// is shared among all instances.
			/// \return the Class object.
			inline virtual Class const & getClass() const {
				return Long::klass; 
			}

			virtual String toString() const;

			/// Returns the value of the specified number as a byte.
			/// 
			/// Returns the value of the specified number as a byte. This may 
			/// involve rounding or truncation
			/// \return the numeric value represented by this object after 
			/// conversion to type byte.
			virtual jbyte byteValue() const;

			/// Returns the value of the specified number as a double.
			///
			/// Returns the value of the specified number as a double. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type double.
			virtual double doubleValue() const;

			/// Returns the value of the specified number as a float.
			///
			/// Returns the value of the specified number as a float. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type float.
			virtual float floatValue() const;

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


			operator int() const { return (int)value_; }

			Long operator+(jshort value) const { return Long(value_ + (jlong)value); }
			Long operator+(jint value) const { return Long(value_ + (jlong)value); }	
			Long operator+(jlong value) const { return Long(value_ + (jlong)value); }

			Long operator+(Long const & other) const { return Long(value_ + other.value_); }

			friend std::ostream & operator<<(std::ostream & os, Long const & integer);
			
		private:
			/// The underlying 64-bits value.
			jlong value_;
		};
	}
}


#endif // JAVA_LANG_LONG

