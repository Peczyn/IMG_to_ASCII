cmake_minimum_required(VERSION 3.27)
project(IMG_to_ASCII)

set(CMAKE_CXX_STANDARD 17)

add_executable(IMG_to_ASCII main.cpp)




find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( IMG_to_ASCII ${OpenCV_LIBS} )


