cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(LinuxTrafficSignals)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(src/hdrs)

add_executable(lts 
			   src/core/main.cpp 
			   src/transform/SequenceLogic.cpp)

target_link_libraries(lts ${CURSES_LIBRARIES})
