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

			/// Default constructor.
			Number() { }

			/// Copy constructor.
			///
			/// Creates a number object, initialising its internal status
			/// with that of the provided object.
			/// \param other the object to copy the internal status from.
			Number(Number const & other) { }

			/// Virtual destructor.
			virtual ~Number() {
				finalize();
			}

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
			virtual byte byteValue() const = 0;

			/// Returns the value of the specified number as a double.
			///
			/// Returns the value of the specified number as a double. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type double.
			virtual double doubleValue() const = 0;

			/// Returns the value of the specified number as a float.
			///
			/// Returns the value of the specified number as a float. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type float.
			virtual float floatValue() const = 0;

			/// Returns the value of the specified number as an int.
			///
			/// Returns the value of the specified number as an int. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type int.
			virtual int intValue() const = 0;

			/// Returns the value of the specified number as a long.
			///
			/// Returns the value of the specified number as a long. This may 
			/// involve rounding.
			/// \return the numeric value represented by this object after 
			/// conversion to type long.
			virtual long longValue() const = 0;

			/// Returns the value of the specified number as a short.
			///
			/// Returns the value of the specified number as a short. This may 
			/// involve rounding or truncation.
			/// \return the numeric value represented by this object after 
			/// conversion to type short.
			virtual short shortValue() const = 0;

			/// Performs a clanup on the object.
			inline virtual void finalize() { }
			
			template <typename T> static inline String toHexString(T const & t);
		private:
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

