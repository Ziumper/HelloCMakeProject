add_library(MathFunctions MathFunctions.cpp)
target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
add_library(SqrtLibrary STATIC mysqrt.cpp)
target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
