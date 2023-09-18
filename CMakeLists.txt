cmake_minimum_required(VERSION 3.27.4)
project(HelloProject VERSION 0.1.0)

#todo set standard of C++
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(HelloConfig.h.in HelloConfig.h)

add_subdirectory(MathFunctions)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")


add_executable(HelloProject main.cpp)

target_link_libraries(HelloProject MathFunctions)

#add binary tree to search path that allows to find HelloConfig.h 
#to find it inside main.cpp file
target_include_directories(HelloProject PUBLIC 
                        "${PROJECT_BINARY_DIR}"
                        ${EXTRA_INCLUDES}
                        )
