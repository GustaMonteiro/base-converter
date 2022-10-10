cmake_minimum_required(VERSION 3.1)

project (bin2dec "C")

file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

add_executable(${CMAKE_PROJECT_NAME} ${sources}) 

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
