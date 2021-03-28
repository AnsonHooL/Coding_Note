cmake_minimum_required(VERSION 3.10)
project(offer)

set(CMAKE_CXX_STANDARD 14)



link_libraries(pthread)
add_executable(offer main.cpp)
add_executable(Product_Consumer algorithm/Producer_Consumer.cpp)
add_executable(spinlock algorithm/Spinlock.cpp)
add_executable(rwspinlock algorithm/readwritelock.cpp)
add_executable(Singleton algorithm/Singleton.cpp)
add_executable(threadpool algorithm/threadpool.cpp)
add_executable(tuple algorithm/Tuple.cpp)
add_executable(tmp algorithm/tmp.cpp)