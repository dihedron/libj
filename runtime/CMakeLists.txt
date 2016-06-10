
CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

# Set the version number; this will be automatically inserted 
# by CMake into the config.h.in file, to generate config.h
set (LIBJPP_VERSION_MAJOR 1)
set (LIBJPP_VERSION_MINOR 0)

 
# Configure the header file used to pass some of the CMake 
# settings to the source code
configure_file (
	"${CMAKE_CURRENT_SOURCE_DIR}/config.h.in"
	"${CMAKE_CURRENT_BINARY_DIR}/config.h"
)

# Add the binary tree to the search path for include files
# so that we will find the CMake-generated config.h; this 
# is only useful if we're going to include it from the
# runtime source files, so it is commented by default
#include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# Recursively look up source and header files in the 
# current directory
file(GLOB_RECURSE LIBJPP_SRCS "*.cc")
file(GLOB_RECURSE LIBJPP_HDRS "*.h")

# Build the library using the aforementioned sources and headers
add_library(j++ ${LIBJPP_SRCS} ${LIBJPP_HDRS})

