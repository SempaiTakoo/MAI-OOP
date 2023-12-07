#include "list.h"

ListFigure::ListFigure() : size{0}, data{nullptr} {}

ListFigure::~ListFigure() {
    if (data != nullptr) {
        for (int i = 0; i < size; i++) {
            delete data[i];
        }
        delete[] data;
        size = 0;
    }
}

ListFigure::ListFigure(const std::initializer_list<Figure *>& figList) {
    data = new Figure *[figList.size()];
    size_t i = figList.size() - 1;
    size = 0;
    for (Figure *f : figList) {
        data[i--] = f;
        size++;
    }
}

void ListFigure::push(Figure *fig) {
    ListFigure buf;
    buf.data = new Figure *[size + 1];
    for (int i = 0; i < size; i++) {
        buf.data[i] = data[i];
    }
    delete[] data;
    buf.data[size] = fig;
    size++;
    data = buf.data;
}

ListFigure::operator double() {
    double res = 0;
    for (int i = 0; i < size; i++) {
        res += double(*data[i]);
    }
    return res;
}

void ListFigure::deleteFigure(int i) {
    ListFigure buf;
    buf.data = new Figure *[size - 1];
    int k = 0;
    for (int j = 0; j < size; j++) {
        if (i == j) {
            k = 1;
            continue;
        }
        buf.data[j - k] = data[j];
    }
    delete[] data;
    size--;
    data = buf.data;
}
