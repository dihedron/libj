/*
 * Iterator.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_UTIL_ITERATOR
#define JAVA_UTIL_ITERATOR

#include <java/lang/Object.h>

namespace java {
	namespace util {
		/// A pure virtual class implementing the Iterator interface.
		///
		/// Iterators replace Enumerations and have an expanded set of 
		/// features: they allow removal of elements from the underlying 
		/// collection, and have imprved method names.
		template<typename T>
		interface Iterator {
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

			/// Returns true if the iteration has more elements.
			///
			/// Returns true if the iteration has more elements.
			/// \reurn true if the iteration has more elements.
			virtual jboolean hasNext() = 0;

			/// Returns the next element in the iteration.
			///
			/// Returns the next element in the iteration.
			/// \returns the next element in the iteration.
			virtual T next() = 0;

			/// Removes the current element.
			///
			/// Removes from the underlying collection the last element 
			/// returned by this iterator (optional operation).			
			virtual void remove() = 0;
		};				
	}
}

#endif // JAVA_UTIL_ITERATOR

