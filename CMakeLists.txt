cmake_minimum_required(VERSION 3.10)

project(ImageEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ImageEditor main.cpp ImageEditor.cpp picture.cpp lodepng.cpp)

