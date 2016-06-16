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

			template <typename T> static inline String toHexString(int value);

			/// Default constructor.
			///
			/// Creates a new Integer object, initialising its value to 0.
			Integer() : Number(), value_(0) { }

			/// Constructor.
			///
			/// Creates a new Integer, initialising it to the given value.
			/// \param value the value to use for initialisation.
			Integer(int value) : Number(), value_(value) { }

			/// Copy constructor.
			///
			/// Creates a new Integer, copying its value from the provided one.
			/// \param other the Integer to copy the internal status from.
			Integer(const Integer & other) : Number(), value_(other.value_) { }

			/// Assignment operator.
			/// 
			/// Copies the status of the given object into this number.
			/// \param other the object to copy the internal status from.
			Integer & operator=(Integer const & other);

			/// Destructor.
			virtual ~Integer() { 
				finalize();
			}

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
			virtual byte byteValue() const;

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

			/// Returns the value of the specified number as an int.
			///
			/// Returns the value of the specified number as an int. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type int.
			virtual int intValue() const;

			/// Returns the value of the specified number as a long.
			///
			/// Returns the value of the specified number as a long. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type long.
			virtual long longValue() const;

			/// Returns the value of the specified number as a short.
			///
			/// Returns the value of the specified number as a short. This may 
			/// involve rounding or truncation.
			/// \return the numeric value represented by this object after 
			/// conversion to type short.
			virtual short shortValue() const;

			/// Returns the 
			virtual String toString() const;



			operator int() const { return value_; };

			Integer operator+(int value) const { return Integer(value_ + value); }
			Integer operator+(long value) const { return Integer(value_ + (int)value); }	
			Integer operator+(long long value) const { return Integer(value_ + (int)value); }

			Integer operator+(Integer const & other) const { return Integer(value_ + other.value_); }

			friend std::ostream & operator<<(std::ostream & os, Integer const & integer);

			inline virtual void finalize() {
				//std::cout << "finalize in Integer" << std::endl;
			}
		private:
			int value_;

		};

		template <typename T> 
		String Integer::toHexString(int value) {
			std::stringstream stream;
			stream << "0x" << std::hex << value;
			return String(stream.str().c_str());
		}
	}
}


#endif // JAVA_LANG_INTEGER

