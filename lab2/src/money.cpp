#include "money.h"

Money::Money() : size(0), money(nullptr) {}

Money::Money(const size_t &n, unsigned char t = 0) {
    if (n == 0 or not isdigit(t)) {
        throw std::invalid_argument("Invalig character to fill");
    }
    size = n;
    money = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        money[i] = t;
    }
}

Money::Money(const std::initializer_list<unsigned char> &t) : size(t.size()), money(new unsigned char[size]) {
    size_t i = 0;
    for (unsigned char ch : t) {
        if (not isdigit(ch)) {
            throw std::invalid_argument(
                "Invalid character in the initialization list");
        }
        money[--i] = ch;
    }
}

Money::Money(const std::string &t) : size(t.size()), money(new unsigned char[size]) {
    for (size_t i = 0; i < size; ++i) {
        if (not isdigit(t[i])) {
            throw std::invalid_argument("Invalig argument in the string");
        }
        money[i] = t[i];
    }
}

Money::Money(const Money &other) : size(other.size) {
    
}