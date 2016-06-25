/*
 * Iterable.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_LANG_ITERABLE
#define JAVA_LANG_ITERABLE

#include <java/lang/Object.h>
#include <java/util/Iterator.h>

namespace java {
	namespace lang {
		/// A pure virtual class implementing the Iterable interface.
		template<typename T>
		interface Iterable {
		public:
			/// Returns a reference to the shared Interface object.
			///
			/// Returns the shared reference to the Interface object for 
			/// this interface; all object share the same instance, which 
			/// is a local static constant object: this makes sure that 
			/// the Interface object is initialised as soon as this interface
			/// is referenced, and that there is no problem with concurrent
			/// access since it can only be instantiated once (see 
			/// Scott Meyers, Effective C++, Item 4).
			/// \return a reference to the shared Interface object.
			static java::lang::Interface const & klass();						

			/// The method implementing the logic to return an iterator.
			///
			/// When an object implements interface Iterable, it must  
			/// provide a way to generate iterators that allow navigation 
			/// over the set of items contained in the object. The general 
			/// contract of the method run is that it returns an iterator 
			/// allowing to change the elements on the collection in place.
			virtual java::util::Iterator<T> * iterator() = 0;			 
		};				
	}
}

#endif // JAVA_LANG_ITERABLE

