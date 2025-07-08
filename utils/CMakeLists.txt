file(GLOB UTILS_SRC "*.cpp")
add_library(utils STATIC ${UTILS_SRC})
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})