cmake_minimum_required(VERSION 3.27.4) #it means that is required cmake version of 3.27.4
project(HelloProject VERSION 0.1.0) #let's the project name be HelloProject

####################################
# Tests
######################################

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  hello_test
  src/hello_test.cpp
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

####################################
# Project
######################################

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
