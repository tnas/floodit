cmake_minimum_required(VERSION 2.6)
project(floodit)

add_executable(floodit main.cpp)

install(TARGETS floodit RUNTIME DESTINATION bin)

add_subdirectory(util)