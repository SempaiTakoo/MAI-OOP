include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


set(CMAKE_CXX_STANDARD 17)

#add LAB1
add_executable(
    lab1_test
    lab1_test.cpp
    ../lab1/src/lab1.cpp
    ../lab1/include/lab1.h
)

target_link_libraries(lab1_test PRIVATE GTest::GTest)
target_include_directories(lab1_test PRIVATE ../lab1/include)

add_test(lab1_test lab1_test)

#add LAB2
add_executable(
    lab2_test
    lab2_test.cpp
    ../lab2/src/money.cpp
    ../lab2/include/money.h
)

target_link_libraries(lab2_test PRIVATE GTest::GTest)
target_include_directories(lab2_test PRIVATE ../lab2/include)

add_test(lab2_test lab2_test)

#add LAB3
add_executable(
    lab3_test
    lab3_test.cpp
    ../lab3/src/point.cpp
    ../lab3/src/figure.cpp
    ../lab3/src/trapezoid.cpp
    ../lab3/src/rhombus.cpp
    ../lab3/src/pentagon.cpp
    ../lab3/src/list.cpp
    ../lab3/include/point.h
    ../lab3/include/figure.h
    ../lab3/include/trapezoid.h
    ../lab3/include/rhombus.h
    ../lab3/include/pentagon.h
    ../lab3/include/list.h
)

target_link_libraries(lab3_test PRIVATE GTest::GTest)
target_include_directories(lab3_test PRIVATE ../lab3/include)

add_test(lab3_test lab3_test)

#add LAB5
add_executable(
    lab5_test
    lab5_test.cpp
    ../lab5/include/iterator.h
    ../lab5/include/const_iterator.h
    ../lab5/include/allocator.h
    ../lab5/include/stack.h
)

target_link_libraries(lab5_test PRIVATE GTest::GTest)
target_include_directories(lab5_test PRIVATE ../lab5/include)

add_test(lab5_test lab5_test)

#add LAB6
add_executable(
    lab6_test
    lab6_test.cpp
    ../lab6/src/npc.cpp
    ../lab6/src/factory.cpp
    ../lab6/src/errant_knight.cpp
    ../lab6/src/slaver.cpp
    ../lab6/src/squirrel.cpp
    ../lab6/src/observer.cpp
    ../lab6/src/visitors.cpp
    ../lab6/include/npc.h
    ../lab6/include/factory.h
    ../lab6/include/errant_knight.h
    ../lab6/include/slaver.h
    ../lab6/include/squirrel.h
    ../lab6/include/observer.h
    ../lab6/include/visitors.h
)

target_link_libraries(lab6_test PRIVATE GTest::GTest)
target_include_directories(lab6_test PRIVATE ../lab6/include)

add_test(lab6_test lab6_test)
