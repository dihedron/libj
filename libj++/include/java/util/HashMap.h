/*
 * HashMap.h
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#ifndef JAVA_UTIL_HASHMAP
#define JAVA_UTIL_HASHMAP

#include <java/util/AbstractMap.h>
#include <java/lang/Cloneable.h>
#include <java/io/Serializable.h>

#include <unordered_map>
#include <memory>

namespace java {
	namespace util {
		/// A pure virtual class implementing the Map interface.
		template<typename K, typename V>		
		class HashMap : extends AbstractMap<K, V>, implements java::io::Serializable, implements java::lang::Cloneable {
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
			virtual ~HashMap() { }

			/// Returns the object's class.
			/// 
			/// Returns the object's class object.
			/// \return the object's class object.
			inline virtual java::lang::Class const & getClass() const {
				return HashMap::klass(); 
			}			

			/// Removes all of the mappings from this map.
			///
			/// Removes all of the mappings from this map; this operation is
			/// optional and may not be implemented.
			virtual void clear() { 
				map_.clear();
			}

			/// Returns whether the map is empty.
			///
			/// Returns true if this map contains no key-value mappings.
			/// \return whether the map is empty.
			virtual jboolean isEmpty() const { 
				return map_.empty(); 
			}

			/// Returns the number of entries in this map.
			///
			/// Returns the number of key-value mappings in this map.
			/// \return the number of key-value mappings in this map.
			virtual jint size() const { 
				return map_.size(); 
			}			

			/// Returns the value corresponding to the given key, if any.
			///
			/// Returns the pointer to the value to which the specified key is 
			/// mapped, or nullptr if this map contains no mapping for the key.
			/// The value can be modified in place even if the Map object is
			/// constant, conforming to Java semantics.
			/// \param the key to look up.
			/// \return a pointer to the value if found, nullptr otherwise.
			virtual V * get(K const & key) { 
				std::shared_ptr<V> value(map_[key]);
				return value.get(); 
			}
			
			/// Associates the specified value with the specified key in this map.
			///
			/// Associates the specified value with the specified key in this map;
			/// if a value was already registered under the given key, it is replaced
			/// and the previous value is returned; this operation is optional.
			/// \param key the key under which to store the value.
			/// \param value the value to store; it can be nullptr.
			/// \return the previous value, or nullptr.
			virtual V * put(K const & key, V const & value) {
				std::shared_ptr<V> previous(map_[key]);
				map_[key] = std::shared_ptr<V>(new V(value)); 
				return previous.get(); 
			}

			/// Copies the other's map entries into this.
			///
			/// Copies all of the mappings from the specified map to this map;
			/// this operation is optional.
			/// \param map the map to merge with this one.			
			//virtual void putAll(Map<typename K, typename V> const & map) { }

			/// Removes the mapping under the given key, if any.
			///
			/// Removes the mapping for a key from this map if it is present;
			/// this operatios is optional.
			/// \param the key of the mapping to remove.
			/// \return the vaòue associated with the given mapping, or nullptr.
			virtual V * remove(K const & key) {
				std::shared_ptr<V> previous(map_[key]);
				map_.erase(key);
				return previous.get(); 
			}

			/// Returns true if this map contains a mapping for the specified key.
			///
			/// Returns true if this map contains a mapping for the specified key;
			/// more formally, returns whether the key is not null and there is
			/// a mapping for the given value.
			/// \param key the key to be looked for in the map.
			/// \return true if this map contains a mapping for the given key.
			virtual jboolean containsKey(K const & key) const { 
				return map_.count(key) > 0; 
			}

			/// Returns true if this map maps one or more keys to the specified value.
			///
			/// Returns true if this map maps one or more keys to the specified value;
			/// the same value can be mapped to multiple keys.
			/// \param value the value to be looked under the map's keys.
			/// \return true if this map maps one or more keys to the given value.
			virtual jboolean containsValue(V const & value) const {
				jboolean found = false;
				for(auto& entry : map_) {					
    				std::cout << entry.first << ": " << entry.second << std::endl;
				} 
				return false; 
			}

			// TODO: Returns a Set view of the keys contained in this map.
			// Set<K> keySet()

			// TODO: Returns a Collection view of the values contained in this map.
			// Collection<V> values()	
			
		private:
			std::unordered_map<K, std::shared_ptr<V>> map_;				
		};				
	

		using namespace lang;

		template<typename K, typename V>
		Class const & HashMap<K, V>::klass() {
			static const Class klass("java.util.HashMap", &AbstractMap<K, V>::klass(), { &Serializable::klass(), &Cloneable::klass() });
			return klass;
		}
	} 
}

#endif // JAVA_UTIL_HASHMAP

