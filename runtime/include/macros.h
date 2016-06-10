#ifndef LIBJ_MACROS
#define LIBJ_JMACROS

/*
#ifndef CLASSDECL
#define CLASS(NAME)								\
	class NAME : public Object {				\
		static Class klass;						\
	public:										\
		virtual Class & getClass() const;		\
		virtual String toString() const;		\
	private:
#endif

#ifndef ENDCLASSDECL
#define ENDCLASSDECL							\
	}
#endif




#ifndef GETCLASSDEF
#   define  GETCLASSDEF			virtual Class & getClass() const;
#endif

#ifndef GETCLASSIMPL
#   define  GETCLASSIMPL(TYPE)	Class & TYPE::getClass() const { return TYPE::klass; }
#endif

#ifndef TOSTRINGDEF
#   define  TOSTRINGDEF			virtual String toString() const;
#endif

#ifndef TOSTRINGIMPL
#   define  TOSTRINGIMPL(TYPE)	String TYPE::toString() const { return getClass().getName() + "@" + hashCode(); }
#endif
*/

#define DBG 	std::cout << "[D] "
#define INF 	std::cout << "[I] "
#define WRN 	std::cout << "[W] "
#define ERR 	std::cout << "[E] "

#define ENDC    std::endl;

#endif /* LIBJ_MACROS */
