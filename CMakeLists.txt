cmake_minimum_required(VERSION 3.28)

project(tpu-processor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tpu-processor main.cpp)

# If linking stdc++ is needed, uncomment the line below
# target_link_libraries(tpu-processor stdc++)

include(GNUInstallDirs)
install(TARGETS tpu-processor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
