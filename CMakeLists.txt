cmake_minimum_required(VERSION 3.10)
project(Epsilon-RootFailureFinding)

add_executable(failroot Codes/RootFindingFailure.cpp)
add_executable(fp Codes/FalsePosition.cpp)
add_executable(nr Codes/NewtonRaphson.cpp)

