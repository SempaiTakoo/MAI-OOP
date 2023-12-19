#include <lab5/include/allocator.h>

#include <iostream>
#include <list>

int main() {
    Allocator<int> allocator;
    std::list<int, allocator> l;

    return 0;
}
