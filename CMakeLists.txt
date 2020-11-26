cmake_minimum_required(VERSION 3.10)
project(offer)

set(CMAKE_CXX_STANDARD 14)

link_libraries( pthread)
add_executable(offer main.cpp)
add_executable(Product_Consumer algorithm/Producer_Consumer.cpp)

