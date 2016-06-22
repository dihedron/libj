/*
#include <rt/trace.hxx>


namespace rt {
    namespace diag {

		trace::autoconfig trace::config_;

		trace::autoconfig::autoconfig(wchar_t const * filename) : writer_(0) {
			memset(filename_, 0, sizeof(filename_));
			if(filename != 0 && wcslen(filename) > 0) {
				wcsncpy(filename_, filename, (sizeof(filename_) / sizeof(wchar_t) ) - 1);
			} else {
				// figure out what the trace file will be named
                GetModuleFileNameW(0, filename_, sizeof(filename_) / sizeof(wchar_t));

                // look for the '.' before the "exe" extension, replace it with "txt"
                wchar_t * dot = wcsrchr(filename_, L'.');
                if(dot && (dot - filename_) < ((sizeof(filename_)/sizeof(wchar_t)) - 23)) {
					// prepare a time format string
					wchar_t buffer[32];
#if LIBRT_WITH_TIMESTAMPED_TRACE
					SYSTEMTIME st;
					GetSystemTime(&st);
					swprintf(buffer, L"-%4d%02d%02d@%02d.%02d.%02d.txt", 
						st.wYear, st.wMonth, st.wDay, 
						st.wHour, st.wMinute, st.wSecond);
#else 
					swprintf(buffer, L".txt"); 
#endif
					wcscpy(dot, buffer);
				} else {
                    dot++;   // advance past the '.'
                    if(wcslen(dot) >= 3) {
                        wcscpy(dot, L"log");
                    }
				}
				wprintf(L"autoinit: filename is >%s<\n", filename_);
			}
		}

		trace::autoconfig::~autoconfig() {
			if(writer_ != 0) {
				delete writer_;
			}
		}

		void trace::autoconfig::init(channel wc, verbosity v, wchar_t const * filename) {
			this->filename(filename);
			this->writer(wc);
			this->current_level(v);
		}

		void trace::autoconfig::writer(channel wc) {
			if(writer_ != 0) {
				delete writer_;
			}
			if(wc == console) {
				writer_ = new consolewriter();
			} else if(wc == file) {
				writer_ = new filewriter(filename_);
			} else if(wc == debugger) {
				writer_ = new debuggerwriter();
			}
		}

        consolewriter::consolewriter() :
            stream_(std::wcerr) {
        }

        consolewriter::~consolewriter() {
        }

        trace::writer & consolewriter::operator <<(trace::modifier mod) {
			switch(mod) {
			case trace::endl:
				__try {
					lock_.acquire();
					stream_ << std::endl;
					stream_.flush();
				} __finally {
					lock_.release();
				}
				break;
			case trace::endp:
				__try {
					lock_.acquire();				
					stream_ << std::endl << L"----------------------------" << std::endl;
					stream_.flush();
				} __finally {
					lock_.release();
				}
				break;
			}

            return *this;
        }

        trace::writer & consolewriter::operator <<(txt::string const & str) {
			__try {
				lock_.acquire();
	            stream_ << str;
			} __finally {
				lock_.release();
			}
            return *this;
        }

        trace::writer & consolewriter::operator <<(wchar_t const * str) { 
            return operator<<(rt::txt::string(str)); 
        }

        trace::writer & consolewriter::operator <<(DWORD dw) {
			__try {
				lock_.acquire();
				stream_ << dw;
			} __finally {
				lock_.release();
			}
            return *this;
        }

        trace::writer & consolewriter::operator <<(void * ptr) {
            wchar_t buffer[64];
			swprintf(buffer, L"[0x%08p]", ptr);
			__try {
				lock_.acquire();
				stream_ << buffer;
			} __finally {
				lock_.release();
			}
            return *this;
        }

        debuggerwriter::debuggerwriter() : 
            buffer_(L"") {
        }

        debuggerwriter::~debuggerwriter() {
            if(buffer_.length() > 0) {				
				OutputDebugStringW(buffer_.c_str());        
            }
        }

        trace::writer & debuggerwriter::operator <<(trace::modifier mod) {
            switch(mod) {
            case trace::endl:
                if(buffer_.length() > 0) {
					__try {
						lock_.acquire();
						OutputDebugStringW(buffer_.c_str());        
					} __finally {
						lock_.release();
					}
                }
                break;
            case trace::endp:
                if(buffer_.length() > 0) {
					__try {
						lock_.acquire();
						OutputDebugStringW(buffer_.c_str());
					} __finally {
						lock_.release();
					}
                }
                buffer_ = L"----------------------------";
				__try {
					lock_.acquire();
					OutputDebugStringW(buffer_.c_str());        
				} __finally {
					lock_.release();
				}
                break;
            }
            buffer_ = L"";
            return *this;
        }

        filewriter::filewriter(wchar_t const * filename) : 
            stream_(*(new std::wofstream)) {
	        if(filename != 0 && wcslen(filename) > 0) {
                char const * ascii = rt::txt::string::unicode_to_ascii(filename);
                if(ascii != 0) {
				    stream_.open(ascii, std::ios::out);
                    free((void *)ascii);
                }
	        }
        }

        filewriter::~filewriter() {
	        stream_.flush();
	        delete &stream_;
        }

        trace::writer & filewriter::operator <<(trace::modifier mod) {
            switch(mod) {
            case trace::endl:
				__try {
					lock_.acquire();
					stream_ << std::endl;
				} __finally {
					lock_.release();
				}
                break;
            case trace::endp:
				__try {
					lock_.acquire();
					stream_ << L"----------------------------" << std::endl;
				} __finally {
					lock_.release();
				}
                break;
            }
            return *this;
        }

        trace::writer & filewriter::operator <<(txt::string const & str) {
			__try {
				lock_.acquire();
				stream_ << str;
			} __finally {
				lock_.release();
			}
            return *this;
        }
        
        trace::writer & filewriter::operator <<(wchar_t const * str) { 
            return operator<<(rt::txt::string(str)); 
        }

        trace::writer & filewriter::operator <<(DWORD dw) {
			__try {
				lock_.acquire();
				stream_ << dw;
			} __finally {
				lock_.release();
			}
            return *this;
        }

        trace::writer & filewriter::operator <<(void * ptr) {
            wchar_t buffer[64];
            swprintf(buffer, L"[0x%08p]", ptr);
			__try {
				lock_.acquire();
				stream_ << buffer;
			} __finally {
				lock_.release();
			}
            return *this;
        }

        trace::writer & debuggerwriter::operator <<(txt::string const & str) {
            buffer_.concat(str);
            return *this;
        }

        trace::writer & debuggerwriter::operator <<(wchar_t const * str) {
            buffer_.concat(rt::txt::string(str));
            return *this;
        }

        trace::writer & debuggerwriter::operator <<(DWORD dw) {
            wchar_t buffer[64];
            swprintf(buffer, L"%lu", dw);
            buffer_.append(buffer);
            return *this;
        }

        trace::writer & debuggerwriter::operator <<(void * ptr) {
            wchar_t buffer[64];
            swprintf(buffer, L"[0x%08p]", ptr);
            buffer_.append(buffer);
            return *this;
        }

        trace::trace(txt::string const & method) : 
            current_(trace::nul), method_(method) {        

			if(trace::dbg >= config_.current_level()) {
				config_.writer() << L"[" << GetCurrentProcessId() << L":"<< GetCurrentThreadId() << L"]";
				config_.writer() << L" [+] ";
				config_.writer() << L">>> " << method_ << trace::endl;
            }
        }

        trace::~trace() {
			if(trace::dbg >= config_.current_level()) {  
				config_.writer() << L"[" << GetCurrentProcessId() << L":" << GetCurrentThreadId() << L"]";
				config_.writer() << L" [-] ";
				config_.writer() << L"<<< " << method_ << trace::endl;
            }
        }

        trace & trace::operator <<(modifier mod) {
            if(current_ >= config_.current_level()) {
                // write to the stream
                config_.writer() << mod;
            }
            return *this;
        }

        trace & trace::operator <<(verbosity lvl) {
            current_ = lvl;
			if(current_ >= config_.current_level()) {            
                config_.writer() << L"[" << GetCurrentProcessId() << L":" << GetCurrentThreadId() << L"]";
                switch(current_) {
                case trace::dbg:
                    config_.writer() << L" [D] ";
                    break;
                case trace::inf:
                    config_.writer() << L" [I] ";
                    break;
                case trace::wrn:
                    config_.writer() << L" [W] ";
                    break;
                case trace::err:
                    config_.writer() << L" [E] ";
                    break;
                case trace::ftl:
                    config_.writer() << L" [F] ";
                    break;
                case trace::cfg:
                    config_.writer() << L" [C] ";
                    break;
                case trace::tst:
                    config_.writer() << L" [T] * ";
                    break;
                case trace::out:
                    // config_.writer() << L" [O] ";
                    config_.writer() << L" ";
                    break;
                }            
            }
            return *this;
        }

        trace & trace::operator <<(txt::string const & str) {
            if( (current_ >= config_.current_level()) && (str.length() > 0) ) {        
                config_.writer() << str;
            }
            return *this;
        }

        trace & trace::operator <<(wchar_t const * str) { 
            return operator<<(rt::txt::string(str)); 
        }

        trace & trace::operator <<(DWORD dw) {
            if( current_ >= config_.current_level() ) {        
                config_.writer() << dw;
            }
            return *this;
        }

        trace & trace::operator <<(void * ptr) {
            if( current_ >= config_.current_level() ) {        
                config_.writer() << ptr;
            }
            return *this;
        }

        trace & trace::operator << (rt::buffer<rt::byte> const & buf) {
            if( current_ >= config_.current_level() ) {
				
                wchar_t tmp_w[1024];
                char    tmp_a[1024];

                swprintf(tmp_w, L"size: %d (step %d)", buf.size(), buf.step());

                config_.writer() << tmp_w << T_END;

                txt::string trace, bin, ascii;
                
                trace = L" > ";

                size_t max = buf.size() * sizeof(unsigned char);
                for(size_t i = 0; i < max; ++i) {
                    char * p = (char *)(unsigned char const *)buf;
                    unsigned char v = (unsigned char)*(p + i);
                    sprintf(tmp_a, "%02x", v);
                    bin.append(rt::txt::string(tmp_a)).append(L" ");
                    if( isdigit(v) || isalpha(v) || ispunct(v) ){
                        swprintf(tmp_w, L" %c", v);
                    } else {
                        swprintf(tmp_w, L" .");
                    }
                    ascii.append(tmp_w);
                    if((i + 1) % 8 == 0 && i != 0) {               
                        trace.append(bin).append(L" - ").append(ascii);
                        config_.writer() << trace << T_END;
                        trace = L" > ";
                        bin = L"";
                        ascii = L"";
                    } else if(i == max - 1) { // last loop
                        for(size_t j = 0; j < (8 - ((i + 1) % 8)); ++j) {
                            bin.append(L"   ");
                        }
                        trace.append(L" > ").append(bin).append(L" - ").append(ascii);
                    }
                }

                if(trace != L" > ") {
                    config_.writer() << trace << T_END;
                }
				
            }
            return *this;
        }
    }
}
*/
