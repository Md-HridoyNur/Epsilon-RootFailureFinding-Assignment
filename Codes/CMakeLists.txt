cmake_minimum_required(VERSION 3.10)

project(RootFailureFinding LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RootFindingFailure
    code/RootFindingFailure.cpp
)

target_compile_options(RootFindingFailure PRIVATE -Wall -Wextra -pedantic)

set_target_properties(RootFindingFailure PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
