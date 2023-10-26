set(CMAKE_CXX_STANDARD 17)

add_executable(
    lab2
    src/main.cpp
    src/money.cpp
    include/money.h
)

target_include_directories(lab2 PRIVATE include)
