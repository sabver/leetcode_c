cmake_minimum_required(VERSION 3.16)
project(LeetcodeSolutions)

set(CMAKE_CXX_STANDARD 17)
 
include(config/common_flags.cmake)

add_subdirectory(utils)
add_subdirectory(easy)
add_subdirectory(medium)
add_subdirectory(hard)
