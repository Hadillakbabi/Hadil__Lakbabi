#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class MatrixBase {
protected:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();
    MatrixBase(size_t r, size_t c);

    void addElement(size_t i, size_t j, T value);
    T getElement(size_t i, size_t j) const;

    size_t getRows() const;
    size_t getCols() const;

    void display() const;
};

#include "MatrixBase.cpp"

#endif