cmake_minimum_required(VERSION 3.5)
set(CMAKE_BUILD_TYPE Release)
project(ModelicaExternalC)
add_library(ModelicaExternalC SHARED ModelicaUtilities.cpp)
