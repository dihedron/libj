

# Add the executable, which is only a driver to test
# libj++ capabilities (against which it is linked)
add_executable(driver main.cc)
target_link_libraries (driver j++)
