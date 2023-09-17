cmake_minimum_required(VERSION 3.27.4)
project(HelloProject VERSION 0.1.0)

#todo set standard of C++
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(src/HelloConfig.h.in HelloConfig.h)

add_executable(HelloProject src/main.cpp)

#add binary tree to search path that allows to find HelloConfig.h 
#to find it inside main.cpp file
target_include_directories(HelloProject PUBLIC 
                        "${PROJECT_BINARY_DIR}"
                        )
