cmake_minimum_required(VERSION 3.16)

project(tpu-processor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tpu-processor main.cpp
    README.md)

include(GNUInstallDirs)
install(TARGETS tpu-processor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
