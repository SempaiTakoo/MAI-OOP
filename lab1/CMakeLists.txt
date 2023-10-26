set(CMAKE_CXX_STANDARD 17)

add_executable(
    lab1
    src/main.cpp
    src/lab1.cpp
    include/lab1.h
)

target_include_directories(lab1 PRIVATE include)
