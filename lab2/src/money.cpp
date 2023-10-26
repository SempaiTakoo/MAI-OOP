#include "money.h"

Money::Money() : size(0), money(nullptr) {}

size_t Money::GetSize() const { return size; }

unsigned char *Money::GetMoney() const { return money; }

Money::Money(const size_t &n, unsigned char ch) {
    if (n == 0 or not isdigit(ch)) {
        throw std::invalid_argument("Invalig character to fill");
    }
    size = n;
    money = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        money[i] = ch;
    }
}

Money::Money(const std::initializer_list<unsigned char> &t)
    : size(t.size()), money(new unsigned char[size]) {
    int i{-1};
    for (unsigned char c : t) {
        if (!isdigit(c)) {
            throw std::invalid_argument("Invalig character in initializer list");
        }
        money[++i] = c;
    }
}

Money::Money(const std::string &t)
    : size(t.size()), money(new unsigned char[size]) {
    for (size_t i = 0; i < size; ++i) {
        if (not isdigit(t[i])) {
            throw std::invalid_argument("Invalig argument in the string");
        }
        money[i] = t[i];
    }
}

Money::Money(const Money &other)
    : size(other.size), money(new unsigned char[size]) {
    std::memcpy(money, other.money, size);
}

Money::Money(Money &&other) noexcept : size(other.size), money(other.money) {
    other.size = 0;
    other.money = nullptr;
}

void Money::Print() {
    for (size_t i = 0; i < size; ++i) {
        std::cout << money[i];
    }
    std::cout << std::endl;
}

Money Money::operator=(const Money &other) {
    if (&other == this) {
        return *this;
    }
    delete[] money;
    size = other.size;
    money = new unsigned char[size];
    std::memcpy(money, other.money, size);
    return *this;
}

Money Money::operator+(const Money &other) const {
    size_t resultSize = std::max(other.size, size);
    std::string result(resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1 = (i < size) ? money[i] : 0;
        int d2 = (i < other.size) ? other.money[i] : 0;
        int sum = (d1 - '0') + (d2 - '0') + carry;
        carry = sum / 10;
        result[i] = sum + '0';
    }
    if (carry > 0) {
        throw std::runtime_error(
            "Array overflow"
        );
    }
    return Money(result);
}

Money Money::operator-(const Money &other) const {
    size_t resultSize = std::max(other.size, size);
    std::string result(resultSize, '0');
    int borrow = 0;
    for (size_t i = 0; i < resultSize; i++)
    {
        int d1 = (i < size) ? money[i]: 0;
        int d2 = (i < other.size) ? other.money[i] : 0;

        int diff = d1 - d2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff + '0';
    }
    if (borrow > 0) {
        throw std::runtime_error(
            "Array overflow"
        );
    }
    return Money(result);
}

bool Money::operator==(const Money& other) const {
    if (&other == this) {
        return true;
    }
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (money[i] != other.money[i]) {
            return false;
        }
    }
    return true;
}

bool Money::operator!=(const Money &other) const {
    if (*this == other) {
        return false;
    }
    return true;
}

bool Money::operator<(const Money &other) const {
    if (&other == this) {
        return false;
    }
    if (size < other.size) {
        return true;
    }
    if (size > other.size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (money[i] < other.money[i]) {
            return true;
        }
        if (money[i] > other.money[i]) {
            return false;
        }
    }
    return false;
}

bool Money::operator>(const Money &other) const {
    if (&other == this) {
        return true;
    }
    if (size < other.size) {
        return false;
    }
    if (size > other.size) {
        return true;
    }
    for (size_t i = 0; i < size; ++i) {
        if (money[i] < other.money[i]) {
            return false;
        }
        if (money[i] > other.money[i]) {
            return true;
        }
    }
    return true;
}

Money::~Money() noexcept {
    delete money;
}
