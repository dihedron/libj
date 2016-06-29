
message (STATUS "driver: configuring the build...")

# Set as the preferred Threads library the pthreads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)

# Find the Threads package; this also sets the
# CMAKE_THREAD_LIBS_INIT variable   
find_package (Threads REQUIRED)

if(CMAKE_USE_PTHREADS_INIT)
	# The pthread library is available, add the linker 
	# option to link against it
	message (STATUS "driver: ... linking against POSIX threads (pthread)")
	set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")	
elseif(CMAKE_USE_WIN32_THREADS_INIT)
	# We are running on Windows, use the native library
	message (STATUS "Linking against Win32 threads")
	# ...
endif()


# Recursively look up source and header files in the 
# current directory
file(GLOB_RECURSE DRIVER_SRCS "*.cc")
file(GLOB_RECURSE DRIVER_HDRS "*.h")

# Add the executable, which is only a driver to test
# libj++ capabilities (against which it is linked)
#add_executable(driver main.cc)
add_executable(driver ${DRIVER_SRCS} ${DRIVER_HDRS})

target_link_libraries (driver j++ ${CMAKE_THREAD_LIBS_INIT})

message (STATUS "driver: ... build configuration complete!")
