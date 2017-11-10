cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(${trust_SOURCE_DIR}/inc)

add_executable(trust trust.cpp game.cpp state.cpp)
set_target_properties(trust PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${trust_SOURCE_DIR}/build")
