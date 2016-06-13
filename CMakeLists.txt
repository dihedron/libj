cmake_minimum_required (VERSION 3.4)

project (j++ CXX)

set (CMAKE_CXX_STANDARD 11)

# Header files are available under the root (the CMake-
# populated config.h)  and under runtime/include, where
# class definitions can be found
include_directories (
	"${PROJECT_SOURCE_DIR}/libj++"
	"${PROJECT_SOURCE_DIR}/libj++/include"
	"${PROJECT_BINARY_DIR}/libj++"
)

# The "libj++" subproject implements the actual J++
# runtime, as a shared object called libj++
add_subdirectory (libj++)

# The "driver" subproject implements anm executable
# that runs some of the tests against the libj++ library
add_subdirectory (driver)


