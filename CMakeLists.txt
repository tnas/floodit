cmake_minimum_required(VERSION 2.6)
project(floodit)

add_executable(floodit 
		main.cpp
		core/flooditboard.cpp)

install(TARGETS floodit RUNTIME DESTINATION bin)

add_subdirectory(util)
add_subdirectory(core)
add_subdirectory(instances)