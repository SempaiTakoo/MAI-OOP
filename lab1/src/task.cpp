#include <iostream>
#include <string>

#include "task.h"

#define BIN_STRING_SIZE (32)
#define MAX_VALUE (4294967295ULL) // 2^32 - 1


std::string IntToBinaryString(long long unsigned number) {
    if (number > MAX_VALUE) {
        return "Error: too big number";
    }
    std::string binString(BIN_STRING_SIZE, '0');
    int binNumDigit = BIN_STRING_SIZE - 1;
    do {
        binString[binNumDigit] = '0' + number % 2;
        --binNumDigit;
    } while (number /= 2);
    return binString;
}