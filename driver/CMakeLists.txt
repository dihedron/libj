
# Find the Threads package; this also sets the
# CMAKE_THREAD_LIBS_INIT variable   
find_package (Threads REQUIRED)

# Add the linker option to link against the pthread library
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

# Add the executable, which is only a driver to test
# libj++ capabilities (against which it is linked)
add_executable(driver main.cc)

target_link_libraries (driver j++ ${CMAKE_THREAD_LIBS_INIT})
