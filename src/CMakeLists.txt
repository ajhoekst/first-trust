cmake_minimum_required(VERSION 2.8)

include_directories(${trust_SOURCE_DIR}/inc)

add_executable(trust trust.cpp)
set_target_properties(trust PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${trust_SOURCE_DIR}/build")
