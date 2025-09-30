cmake_minimum_required(VERSION 3.10)
project(Epsilon-RootFailureFinding)

add_executable(main RootFindingFailure.cpp)
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Codes)
