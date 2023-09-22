#include <string>

#include "task.hpp"


#define BIN_STRING_SIZE (32)

std::string IntToBinaryString(unsigned number) {
    std::string binString(BIN_STRING_SIZE, '0');
    int binNumDigit = BIN_STRING_SIZE - 1;
    while (number >> 1) {
        binString[binNumDigit] = '0' + number % 2;
    }
    return binString;
}