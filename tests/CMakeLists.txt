cmake_minimum_required(VERSION 3.14)
project(test_fib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
find_package(Threads REQUIRED)

file(GLOB SOURCES *.cpp)
add_subdirectory("/usr/src/gtest" ${CMAKE_BINARY_DIR}/gtest)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${FIB_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${FIB_LIB_LIBRARIES} gtest gtest_main)
