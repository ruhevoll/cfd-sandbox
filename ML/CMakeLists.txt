cmake_minimum_required(VERSION 3.28)
project(ML)

set(CMAKE_CXX_STANDARD 20)

add_executable(ML eigen_samples/linalg_eigen.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib/eigen-3.4.0)