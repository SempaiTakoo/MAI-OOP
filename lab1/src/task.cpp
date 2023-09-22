
#include <iostream>
#include <string>

#define BIN_STRING_SIZE (32)

using namespace std;

string IntToBinaryString(unsigned number) {
    string binString(BIN_STRING_SIZE, '0');
    int binNumDigit = BIN_STRING_SIZE - 1;
    while (number >> 1) {
        binString[binNumDigit] = '0' + number % 2;
    }
    return binString;
}