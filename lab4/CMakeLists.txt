set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "g++-12")

add_executable(
    lab4
    src/main.cpp
    include/point.h
    include/figure.h
    include/trapezoid.h
    include/rhombus.h
    include/pentagon.h
    include/list.h
)

target_include_directories(lab4 PRIVATE include)
