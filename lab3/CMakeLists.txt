set(CMAKE_CXX_STANDARD 17)

add_executable(
    lab3
    src/main.cpp
    src/point.cpp
    src/figure.cpp
    src/trapezoid.cpp
    src/rhombus.cpp
    src/pentagon.cpp
    src/list.cpp

    include/point.h
    include/figure.h
    include/trapezoid.h
    include/rhombus.h
    include/pentagon.h
    include/list.h
)

target_include_directories(lab3 PRIVATE include)
