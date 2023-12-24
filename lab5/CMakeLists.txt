set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "g++-12")

add_executable(
    lab5
    src/main.cpp
    include/iterator.h
    include/const_iterator.h
    include/allocator.h
    include/stack.h
)

target_include_directories(lab5 PRIVATE include)
