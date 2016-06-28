/*
 * AbstractMap.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_UTIL_ABSTRACTMAP
#define JAVA_UTIL_ABSTRACTMAP

#include <java/util/Map.h>

namespace java {
	namespace util {
		/// A pure virtual class implementing the Map interface.
		template<typename K, typename V>
		class AbstractMap : extends java::lang::Object, implements Map<K, V> {
		public:

			/// Returns a reference to the shared Class object.
			///
			/// Returns the shared reference to the Class object for 
			/// this class; all object share the same instance, which 
			/// is a local static constant object: this makes sure that 
			/// the Class object is initialised as soon as this class
			/// is reerences, and that there is no problem with concurrent
			/// access since it can only be instantiated once (see 
			/// Scott Meyers, Effective C++, Item 4).
			/// \return a reference to the shared Class object.
			static java::lang::Class const & klass(); 

			/// Destructor.
			virtual ~AbstractMap() { }

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual java::lang::Class const & getClass() const {
				return AbstractMap::klass(); 
			}			

		protected:
			/// Constructor; only subclasses can instantiate an AbstractMap.
			AbstractMap() { }
		};	

		using namespace lang;

		template<typename K, typename V>
		Class const & AbstractMap<K, V>::klass() {
			static const Class klass("java.util.AbstractMap", &Object::klass(), { &Map<K, V>::klass() });
			return klass;
		}					
	}
}

#endif // JAVA_UTIL_ABSTRACTMAP

