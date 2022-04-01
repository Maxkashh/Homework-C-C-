cmake_minimum_required(VERSION 3.0.0)
project(v1)

add_subdirectory(vec_lib)

message("VEC_LIB_INCLUDE_DIRS = ${VEC_LIB_INCLUDE_DIRS}")
message("VEC_LIB_LIBRARIES = ${VEC_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

target_include_directories(${PROJECT_NAME} PUBLIC ${VEC_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${VEC_LIB_LIBRARIES})

add_subdirectory(tests)