cmake_minimum_required(VERSION 3.10)

project(force_sensing)
set(CMAKE_CXX_STANDARD 11)

# using C++11 
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread")
 
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include path: ${OpenCV_INCLUDE_DIRS}")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    /usr/local/include
    /usr/include 
    ${OpenCV_INCLUDE_DIR})

aux_source_directory(./src/ DIR_SRCS)

add_executable(force_sensing ${DIR_SRCS})
target_link_libraries(force_sensing 
${OpenCV_LIBS}
/usr/lib
/usr/local/lib)
