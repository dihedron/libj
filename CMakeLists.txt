cmake_minimum_required (VERSION 3.4)

project (j++ CXX)

set (CMAKE_CXX_STANDARD 11)

# Header files are available under the root (the CMake-
# populated config.h)  and under runtime/include, where
# class definitions can be found
include_directories (
	"${PROJECT_SOURCE_DIR}/runtime"
	"${PROJECT_SOURCE_DIR}/runtime/include"
	"${PROJECT_BINARY_DIR}/runtime"
)

# The "runtime" subproject implements the actual J++
# runtime, as libj++
add_subdirectory (runtime)  

# Add the executable, which is only a driver to test
# libj++ capabilities (against which it is linked)
add_executable(driver main.cc)
target_link_libraries (driver j++)