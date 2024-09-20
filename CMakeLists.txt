cmake_minimum_required(VERSION 3.5.0)
project(bmp-converter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/BmpConverter/BmpConverter.cpp 
    src/BmpConverter/BmpConverter.hpp
    src/BmpImage/BmpImage.hpp 
    src/main.cpp 
    )

add_executable(bmp-converter ${SOURCES})

