cmake_minimum_required(VERSION 3.27.4) #it means that is required cmake version of 3.27.4
project(HelloProject VERSION 0.1.0) #let's the project name be HelloProject


#####################################
# GLFW
####################################

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw-3.3.8)

####################################
# Project
######################################

configure_file(src/HelloConfig.h.in HelloConfig.h)

add_subdirectory(src/MathFunctions)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/src/MathFunctions")


add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE MathFunctions glfw)

target_link_options(${CMAKE_PROJECT_NAME} PRIVATE -mwindows)

#add binary tree to search path that allows to find HelloConfig.h 
#to find it inside main.cpp file
target_include_directories(HelloProject PUBLIC 
                        "${PROJECT_BINARY_DIR}"
                        ${EXTRA_INCLUDES}
                        )

                        
####################################
# Tests
######################################

add_subdirectory(external/googletest)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()
include(GoogleTest)

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# from list of files we'll create tests test_name.cpp -> test_name
foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_executable(${_test_name} ${_test_file})
    target_link_libraries(${_test_name} GTest::gtest_main)
    gtest_discover_tests(${_test_name})
endforeach()