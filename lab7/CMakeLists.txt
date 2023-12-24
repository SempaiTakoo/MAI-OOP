set(CMAKE_CXX_STANDARD 20)

add_executable(
    lab5
    src/main.cpp
    include/errant_knight.h
    include/npc.h
    include/observer.h
    include/slaver.h
    include/squirrel.h
    src/errant_knight.cpp
    src/npc.cpp
    src/slaver.cpp
    src/squirrel.cpp
)

target_include_directories(lab7 PRIVATE include)
