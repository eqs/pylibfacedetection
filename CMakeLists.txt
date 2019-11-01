cmake_minimum_required(VERSION 3.15)
project(libfacedetection_wrapper)

add_subdirectory(pybind11)
pybind11_add_module(libfacedetection_wrapper src/main.cpp)
