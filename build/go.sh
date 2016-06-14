#!/bin/bash

if [  "$1" == "-b" -o "$1" == "--build" -o "$1" == "build" ]; then
	make
elif [  "$1" == "-c" -o "$1" == "--clean" -o "$1" == "--clean"]; then
	make clean
elif [  "$1" == "-d" -o "$1" == "--debug" -o "$1" == "debug" ]; then
	cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
elif [  "$1" == "-r" -o "$1" == "--release" -o "$1" == "release" ]; then
	cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
elif [  "$1" == "-p" -o "$1" == "--purge" -o "$1" == "purge" ]; then
	rm -rf CMakeCache.txt cmake_install.cmake Makefile CMakeFiles/ libj++/ driver/  
elif [ "$#" -ne 1 ]; then

	cat <<HEREDOC
usage:
    ./go.sh <option>
where <option> can be any of
    -b|--build    performs a build (make)
    -c|--clean    cleans up the build (make clean)
    -d|--debug    initialises/refreshes a debug configuration
    -r|--release  initialises/refreshes a release configuration
    -p|--purge    purges any configuration done so far

HEREDOC
    
fi
