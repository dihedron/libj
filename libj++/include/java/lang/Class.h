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

namespace java {
	namespace lang {

		class Class : public Object {
		public:
			/// The Class' object Class.
			static const Class klass;				 
	
			Class(String const & name);

			Class(String const & name, Class const & super);

			Class(String const & name, Class const & super, std::initializer_list<String> interfaces);
	
			Class(const Class & other);
	
			virtual ~Class() { }

			virtual Class const & getClass() const {
				return Class::klass;
			}

			Class const * getSuperclass() const {
				return super_;
			}

			//List<String> const & getInterfaces() const;

			String const & getName() const {
				return name_;
			}

			String toString() const;
				
		private:
			const String name_;

			const Class * super_;

			// TODO: this must be a list, so no need to keep a count!
			String * interfaces_;
		};				
	}
}

#endif // JAVA_LANG_CLASS

