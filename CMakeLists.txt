cmake_minimum_required(VERSION 2.8)

project(subtitle_time_shifter)
set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
