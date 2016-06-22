#ifndef ORG_DIHEDRON_LOG_LEVEL
#define ORG_DIHEDRON_LOG_LEVEL

namespace org {
	namespace dihedron {
		namespace log {
			/// An enumeration of the available logging levels; no message
			/// below the current logging threshold will be written out.
            typedef enum { 
				dbg = 0, 	///< The finest grain logging level.
				inf, 		///< The level for informational messages.
				wrn, 		///< The level for warning messages.
				err, 		///< The level for recoverable errors.
				ftl, 		///< The level for fatal, unrecoverable errors.
				cfg, 		///< The informational messages about configuration.
				nul 		///< The level to prevent all logging activity.
			} Level;

			/// The global logging threshold; nothing below this
			/// level will be written out; it is initialised at
			// VM initialisation (see VM.cc).
			static Level Threshold;
		}
	}
}


#endif // ORG_DIHEDRON_LOG_LEVEL

