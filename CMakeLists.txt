cmake_minimum_required(VERSION 3.28)

project(tpu-processor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# TensorFlow Lite library location
set(TFLITE_DIR /opt/tensorflow)

# Include TensorFlow Lite headers
include_directories(${TFLITE_DIR})

# Path to TensorFlow Lite library
set(TFLITE_LIB ${TFLITE_DIR}/bazel-bin/tensorflow/lite/libtensorflowlite.so)

# Define executable and link TensorFlow Lite
add_executable(tpu-processor main.cpp
        detection.cpp
        detection.h
        model.cpp
        model.h
        device.cpp
        device.h)
target_link_libraries(tpu-processor ${TFLITE_LIB})

# Installation directories
include(GNUInstallDirs)
install(TARGETS tpu-processor
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
