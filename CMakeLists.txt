cmake_minimum_required(VERSION 3.15)
project(clibfacedetection)

add_subdirectory(pybind11)
pybind11_add_module(clibfacedetection src/main.cpp src/facedetector.cpp)

add_subdirectory(libfacedetection)

include_directories(clibfacedetection
    src
    libfacedetection/src
)

target_link_libraries(clibfacedetection PRIVATE facedetection)
