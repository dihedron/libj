 /*
 * Throwable.cc
 * Copyright (C) 2016 Andrea Funto' <dihedron.dev@gmail.com>
 * See LICENSE for details and terms of use.
 */

#include <java/lang/Throwable.h>
#include <java/lang/Class.h>

namespace java {
	namespace lang {

		const Class Throwable::klass("java.lang.Throwable", Object::klass, { java::io::Serializable::name });

		Throwable::Throwable() 
			: message_("")
			, cause_(nullptr) {

		}

		Throwable::Throwable(Throwable const & other)
			: message_(other.message_)
			, cause_(nullptr) {
			if(other.cause_ != nullptr) {
				this->cause_= new Throwable(*other.cause_);
			}
		}

		Throwable::Throwable(String const & message) 
			: message_(message)
			, cause_(nullptr) { 			
		}

		Throwable::Throwable(String const & message, Throwable const & cause)
			: message_(message)
			, cause_(new Throwable(cause)) {			
		}

		Throwable::~Throwable() {
			finalize();
		}

		Throwable & Throwable::operator=(Throwable const & other) {
			if(this != &other) {
				finalize();
				message_ = other.message_;
				if(other.cause_ != nullptr) {
					cause_ = new Throwable(*other.cause_);
				}
			}
			return *this;
		}

		String Throwable::toString() const {
			return getClass().getName() + ": " + getLocalizedMessage();
		}		
	}
}