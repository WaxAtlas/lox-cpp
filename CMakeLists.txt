cmake_minimum_required(VERSION 3.13)

project(lox-cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

add_executable(lox-cpp ${SOURCE_FILES})

target_link_libraries(lox-cpp PRIVATE ${READLINE_LIBRARIES})
