cmake_minimum_required(VERSION 3.3)
project(case3_CreditCard)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES testCard.cpp CreditCard.cpp CreditCard.h)
add_executable(case3_CreditCard ${SOURCE_FILES} )