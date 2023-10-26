#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>

class Money {
public:
    Money();                                                // Default constructor
    size_t GetSize() const;
    unsigned char *GetMoney() const;

    Money(const size_t &n, unsigned char ch);               // Fill constructor
    Money(const std::initializer_list<unsigned char> &t);   // Initializer list constructor
    Money(const std::string &t);                            // Copy string constructor
    Money(const Money &other);                              // Copy constructor
    Money(Money &&other) noexcept;                          // Move constructor

    void Print();

    Money operator=(const Money &other);                    // Assignment operator
    Money operator+(const Money &other) const;              // Addition operator
    Money operator-(const Money &other) const;              // Substraction operator
    bool operator==(const Money &other) const;              // Equal operator
    bool operator!=(const Money &other) const;              // Not equal operator
    bool operator>(const Money &other) const;               // Less operator
    bool operator<(const Money &other) const;               // Greater operator

    virtual ~Money() noexcept;                              // Destructor

private:
    size_t size;
    unsigned char *money;
};
