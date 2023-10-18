#pragma once

#include <string>
#include <stdexcept>

class Money {
public:
    Money();
    Money(const size_t &n, unsigned char t = 0);
    Money(const std::initializer_list< unsigned char> &t);
    Money(const std::string &t);
    Money(const Money &other);
    Money(Money &&other) noexcept;
    virtual ~Money() noexcept;

private:
    size_t size;
    unsigned char *money;
};