#ifndef ORG_DIHEDRON_LOG_WRITER
#define ORG_DIHEDRON_LOG_WRITER

#include <java/lang/Object.h>

namespace org {
	namespace dihedron {
		namespace log {
			template <typename T>
			class Writer : public java::lang::Interface {
			public: 
				/// The Writer Interface object.
				static const Interface klass;

				virtual Writer & operator <<(String const & string) = 0;
/*				
				virtual Writer & operator <<(jboolean value) = 0;
				virtual Writer & operator <<(jbyte value) = 0;
				virtual Writer & operator <<(jshort value) = 0;
				virtual Writer & operator <<(jint value) = 0;
				virtual Writer & operator <<(jlong value) = 0;
				template <typename T> virtual Writer & operator <<(T const & t) = 0;
				*/
			};
		}
	}
}

#endif // ORG_DIHEDRON_LOG_WRITER



/*
#ifndef TRACE_HXX
#define TRACE_HXX

#include <rt/common.hxx>

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <rt/buffer.hxx>
#include <rt/tmacros.hxx>
#include <rt/string.hxx>
#include <rt/lock.hxx>

namespace org {
    namespace dihedron {
		
		class Trace : public Object {
		public: 
			/// The Trace Class object.
			static const Class klass;

            typedef enum _modifier { 
				endl = 0, 
				endp 
			} Modifier;

            typedef enum _verbosity { 
				dbg = 0, 
				inf, 
				wrn, 
				err, 
				ftl, 
				cfg, 
				tst, 
				out, 
				nul 
			} Verbosity;

            class LIBRT_SERVICE writer {
            public:
				writer() { }
                virtual ~writer() { }
                virtual writer & operator <<(txt::string const & str) = 0;                            
                virtual writer & operator <<(wchar_t const * str) = 0;
                virtual writer & operator <<(DWORD dw) = 0;
                virtual writer & operator <<(void * ptr) = 0;
                virtual writer & operator <<(modifier mod) = 0;
			protected:
				sys::lock	lock_;
            };
			


		};
    
	/*
        class LIBRT_SERVICE trace {
        public:

            typedef enum _modifier { endl = 0, endp } modifier;
            typedef enum _verbosity { dbg = 0, inf, wrn, err, ftl, cfg, tst, out, nul } verbosity;
			typedef enum _channel {console = 0, file, debugger } channel;

			#define DEFAULT_LEVEL   rt::diag::trace::dbg

            class LIBRT_SERVICE writer {
            public:
				writer() { }
                virtual ~writer() { }
                virtual writer & operator <<(txt::string const & str) = 0;                            
                virtual writer & operator <<(wchar_t const * str) = 0;
                virtual writer & operator <<(DWORD dw) = 0;
                virtual writer & operator <<(void * ptr) = 0;
                virtual writer & operator <<(modifier mod) = 0;
			protected:
				sys::lock	lock_;
            };

			class LIBRT_SERVICE autoconfig {
			public:

				autoconfig(wchar_t const * filename = 0);
				~autoconfig();

				void init(channel wc = console, verbosity v = DEFAULT_LEVEL, wchar_t const * filename = 0); 

				wchar_t const * filename() const { return filename_; }
				void filename(wchar_t const * filename) { if(filename) { wcscpy(filename_, filename); } }

				writer & writer() const { return *writer_; }
				void writer(channel wc);

				verbosity current_level() const { return (verbosity)InterlockedExchange((long *)&verbosity_, verbosity_); }
				void current_level(verbosity v) { InterlockedExchange((long *)&verbosity_, (long)v); }
				
			private:
				wchar_t filename_[MAX_PATH];
				trace::writer  * writer_;  								
				verbosity		 verbosity_;
			};

			static autoconfig & global_config() { return config_; }

            trace(txt::string const & method);
            virtual ~trace();

            trace & operator <<(modifier mod);
            trace & operator <<(verbosity lvl);
            trace & operator <<(txt::string const & str);
            trace & operator <<(wchar_t const * str);
            trace & operator <<(DWORD dw);
            trace & operator <<(void * ptr);
            trace & operator <<(rt::buffer<rt::byte> const & buf);
        private:
            verbosity			current_;
            txt::string			method_;

			static autoconfig	config_;

		    friend class writer;
        };        

    #if _MSC_VER > 1200
        #define TRC(x)          rt::diag::trace trc(__TFUNCTION__);
    #else
	    #define TRC(x)          rt::diag::trace trc(x);
    #endif
        #define T_DBG           trc << rt::diag::trace::dbg
        #define T_INF           trc << rt::diag::trace::inf
        #define T_WRN           trc << rt::diag::trace::wrn
        #define T_ERR           trc << rt::diag::trace::err
        #define T_FTL           trc << rt::diag::trace::ftl
        #define T_CFG           trc << rt::diag::trace::cfg
        #define T_TST           trc << rt::diag::trace::tst
        #define T_OUT           trc << rt::diag::trace::out
        #define T_END           rt::diag::trace::endl
        #define T_PAR           trc << rt::diag::trace::endp

		#define T_INIT(x)		rt::diag::trace::global_config().init(x);

//		#define T_INIT1(x)	    rt::diag::trace::global_config().init(x);
//		#define T_INIT2(x,y)	rt::diag::trace::global_config().init(x, y);
//		#define T_INIT3(x,y,z)  rt::diag::trace::global_config().init(x, y, z);

        #define T_LVL(x)        rt::diag::trace::global_config().current_level(x);
		#define T_FILE(x)       rt::diag::trace::global_config().filename(x);
		#define T_CHL(x)        rt::diag::trace::global_config().writer(x);

        class LIBRT_SERVICE consolewriter : public trace::writer{
        public:
            consolewriter();
            virtual ~consolewriter();
            virtual trace::writer & operator <<(txt::string const & str);
            virtual trace::writer & operator <<(wchar_t const * str);
            virtual trace::writer & operator <<(DWORD dw);
            virtual trace::writer & operator <<(void * ptr);
            virtual trace::writer & operator <<(trace::modifier mod);
        private:
            std::wostream & stream_;
        };

        class LIBRT_SERVICE debuggerwriter : public trace::writer {
        public:
            debuggerwriter();
            virtual ~debuggerwriter();
            virtual trace::writer & operator <<(txt::string const & str);
            virtual trace::writer & operator <<(wchar_t const * str);
            virtual trace::writer & operator <<(DWORD dw);
            virtual trace::writer & operator <<(void * ptr);
            virtual trace::writer & operator <<(trace::modifier mod);
        private:
            txt::string buffer_;
        };

        class LIBRT_SERVICE filewriter : public trace::writer {
        public:
            filewriter(wchar_t const * filename);
            virtual ~filewriter();
            virtual trace::writer & operator <<(txt::string const & str);
            virtual trace::writer & operator <<(wchar_t const * str);
            virtual trace::writer & operator <<(DWORD dw);
            virtual trace::writer & operator <<(void * ptr);
            virtual trace::writer & operator <<(trace::modifier mod);
        private:
	        std::wofstream & stream_;
        };    
    }
}
*/

//#endif
