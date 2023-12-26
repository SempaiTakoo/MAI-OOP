set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "g++-12")

set(
    HEADERS
    include/npc.h
    include/factory.h
    include/errant_knight.h
    include/slaver.h
    include/squirrel.h
    include/observer.h
    include/visitors.h
)

set(
    SOURCES
    src/npc.cpp
    src/factory.cpp
    src/errant_knight.cpp
    src/slaver.cpp
    src/squirrel.cpp
    src/observer.cpp
    src/visitors.cpp
)

add_executable(
    lab6
    src/main.cpp
)

target_include_directories(lab6 PRIVATE include)
