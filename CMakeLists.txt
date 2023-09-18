cmake_minimum_required(VERSION 3.27.4)
project(HelloProject VERSION 0.1.0)

configure_file(src/HelloConfig.h.in HelloConfig.h)

add_subdirectory(src/MathFunctions)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/src/MathFunctions")

add_executable(HelloProject src/main.cpp)

target_link_libraries(HelloProject MathFunctions)

#add binary tree to search path that allows to find HelloConfig.h 
#to find it inside main.cpp file
target_include_directories(HelloProject PUBLIC 
                        "${PROJECT_BINARY_DIR}"
                        ${EXTRA_INCLUDES}
                        )
