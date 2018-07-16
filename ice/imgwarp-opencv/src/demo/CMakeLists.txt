cmake_minimum_required(VERSION 2.6)
project(demo)
FIND_PACKAGE( OpenCV REQUIRED )

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR}/lib ${CMAKE_CURRENT_SOURCE_DIR})

set(demo_SRCS main.cpp)
add_executable(demo ${demo_SRCS} ${helloworld_FORMS_HEADERS})
target_link_libraries(demo imgwarp-lib ${OpenCV_LIBS})
