#ifndef ORG_DIHEDRON_LOG_MODIFIER
#define ORG_DIHEDRON_LOG_MODIFIER

namespace org {
	namespace dihedron {
		namespace log {
			/// The enumeration of Trace modifiers; these provide a way 
			/// to output special character (sequences) to the trace stream.			
            typedef enum { 
				endl = 0, 	///< Causes a new line character to be written out.
				endp 		///< Causes a paragraph separator to be written out.
			} Modifier;
		}
	}
}


#endif // ORG_DIHEDRON_LOG_MODIFIER
