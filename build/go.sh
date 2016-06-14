#!/bin/bash

if [ $# -ne 1 ]; then
	cat <<HEREDOC
usage:
	./go.sh <option>
where <option> can be any of
	-b|--build|build		performs a build (make)
	-c|--clean|clean		cleans up the build (make clean)
	-d|--debug|debug		initialises/refreshes a debug configuration
	-r|--release|release	initialises/refreshes a release configuration
	-p|--purge|purge		purges any configuration done so far
HEREDOC
exit 1
fi

case "$1" in
	build|-b|--build)
		make
		;;
	clean|-c|--clean)
		make clean
		;;
	debug|-d|--debug)
		cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
		;;
	release|-r|--release)
		cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
		;;
	purge|-p|--purge)
		rm -rf CMakeCache.txt cmake_install.cmake Makefile CMakeFiles/ libj++/ driver/
		;;
esac
