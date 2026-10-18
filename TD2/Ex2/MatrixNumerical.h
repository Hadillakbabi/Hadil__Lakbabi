#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"
#include <cmath>
#include <type_traits>

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
    static_assert(is_arithmetic<T>::value,
                  "T doit etre un type numerique");

public:
    MatrixNumerical();
    MatrixNumerical(size_t r, size_t c);

    double getDeterminant() const;
    MatrixNumerical<double> getInverse() const;

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& m) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& m) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& m) const;

    MatrixNumerical<double> operator/(const MatrixNumerical<T>& m) const;

    static MatrixNumerical<T> getIdentity(int n);
};

template <typename T>
MatrixNumerical<T> getCoFactor(
    const MatrixNumerical<T>& m, size_t p, size_t q
);

#include "MatrixNumerical.cpp"

#endif