cmake_minimum_required(VERSION 2.6)

PROJECT( imgwarp-opencv )
FIND_PACKAGE( OpenCV REQUIRED )

add_subdirectory(lib)
add_subdirectory(demo)
