cmake_minimum_required(VERSION 2.6)
project(floodit)

find_package(OpenMP)

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(COMPILER_FLAGS "-Wall -O3")

add_executable(floodit 
		main.cpp
		core/flooditboard.cpp
		strategies/flooditstrategy_greedy.cpp)

install(TARGETS floodit RUNTIME DESTINATION bin)

add_subdirectory(util)
add_subdirectory(core)
add_subdirectory(instances)
add_subdirectory(strategies)