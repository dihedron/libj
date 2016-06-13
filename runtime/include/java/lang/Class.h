/*
 * Class.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_CLASS
#define JAVA_LANG_CLASS

#include <java/lang/Object.h>
#include <java/lang/String.h>

namespace java {
	namespace lang {

		class Class : public Object {
		public:
			/// The Class' object Class.
			static const Class klass;				 
	
			Class(String const & name);

			Class(String const & name, Class const & super);
	
			Class(const Class & other);
	
			virtual ~Class() { }

			virtual Class const & getClass() const {
				return Class::klass;
			}

			Class const * getSuperclass() const {
				return super_;
			}

			String const & getName() const {
				return name_;
			}

			String toString() const;
				
		private:
			const String name_;

			const Class * super_;

		};				
	}
}

#endif // JAVA_LANG_CLASS

