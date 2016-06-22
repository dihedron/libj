
message (STATUS "libj++: configuring the build...")

# Set the version number; this will be automatically inserted 
# by CMake into the config.h.in file, to generate config.h
set (LIBJPP_VERSION_MAJOR 0)
set (LIBJPP_VERSION_MINOR 0)
set (LIBJPP_VERSION_PATCH 1)
 
# Configure the header file used to pass some of the CMake 
# settings to the source code
configure_file (
	"${CMAKE_CURRENT_SOURCE_DIR}/include/VM.h.in"
#	"${CMAKE_CURRENT_BINARY_DIR}/VM.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/VM.h"
)

# Recursively look up source and header files in the 
# current directory
file(GLOB_RECURSE LIBJPP_SRCS "*.cc")
file(GLOB_RECURSE LIBJPP_HDRS "*.h")

# Build the library using the aforementioned sources and headers
add_library(j++ SHARED ${LIBJPP_SRCS} ${LIBJPP_HDRS})

message (STATUS "libj++: ... build configuration complete!")
