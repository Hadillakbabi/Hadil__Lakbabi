#include "MatrixNumerical.h"

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>() {
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t r, size_t c)
    : MatrixBase<T>(r, c) {
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(
    const MatrixNumerical<T>& m) const {

    if (this->rows != m.getRows() || this->cols != m.getCols()) {
        throw invalid_argument("Dimensions incompatibles");
    }

    MatrixNumerical<T> result(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.addElement(i, j,
                this->data[i][j] + m.getElement(i, j));
        }
    }

    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(
    const MatrixNumerical<T>& m) const {

    if (this->rows != m.getRows() || this->cols != m.getCols()) {
        throw invalid_argument("Dimensions incompatibles");
    }

    MatrixNumerical<T> result(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.addElement(i, j,
                this->data[i][j] - m.getElement(i, j));
        }
    }

    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(
    const MatrixNumerical<T>& m) const {

    if (this->cols != m.getRows()) {
        throw invalid_argument("Dimensions incompatibles");
    }

    MatrixNumerical<T> result(this->rows, m.getCols());

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < m.getCols(); j++) {
            T sum = T{};

            for (size_t k = 0; k < this->cols; k++) {
                sum += this->data[i][k] * m.getElement(k, j);
            }

            result.addElement(i, j, sum);
        }
    }

    return result;
}

template <typename T>
MatrixNumerical<T> getCoFactor(
    const MatrixNumerical<T>& m, size_t p, size_t q) {

    size_t n = m.getRows();
    MatrixNumerical<T> result(n - 1, n - 1);

    size_t r = 0;

    for (size_t i = 0; i < n; i++) {
        if (i == p) {
            continue;
        }

        size_t c = 0;

        for (size_t j = 0; j < n; j++) {
            if (j == q) {
                continue;
            }

            result.addElement(r, c, m.getElement(i, j));
            c++;
        }

        r++;
    }

    return result;
}

template <typename T>
double MatrixNumerical<T>::getDeterminant() const {

    if (this->rows != this->cols || this->rows == 0) {
        throw invalid_argument("Matrice non carree ou vide");
    }

    if (this->rows == 1) {
        return this->data[0][0];
    }

    double det = 0;

    for (size_t j = 0; j < this->cols; j++) {
        MatrixNumerical<T> sub = getCoFactor(*this, 0, j);

        double signe = (j % 2 == 0) ? 1.0 : -1.0;

        det += signe * this->data[0][j]
                     * sub.getDeterminant();
    }

    return det;
}

template <typename T>
MatrixNumerical<double> MatrixNumerical<T>::getInverse() const {

    if (this->rows != this->cols || this->rows == 0) {
        throw invalid_argument("Matrice non carree ou vide");
    }

    double det = getDeterminant();

    if (abs(det) < 1e-12) {
        throw invalid_argument("Matrice non inversible");
    }

    size_t n = this->rows;
    MatrixNumerical<double> inverse(n, n);

    if (n == 1) {
        inverse.addElement(0, 0, 1.0 / det);
        return inverse;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {

            MatrixNumerical<T> sub = getCoFactor(*this, i, j);

            double signe = ((i + j) % 2 == 0) ? 1.0 : -1.0;
            double valeur = signe * sub.getDeterminant() / det;

            inverse.addElement(j, i, valeur);
        }
    }

    return inverse;
}

template <typename T>
MatrixNumerical<double> MatrixNumerical<T>::operator/(
    const MatrixNumerical<T>& m) const {

    MatrixNumerical<double> inverse = m.getInverse();

    if (this->cols != inverse.getRows()) {
        throw invalid_argument("Dimensions incompatibles");
    }

    MatrixNumerical<double> result(this->rows, inverse.getCols());

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < inverse.getCols(); j++) {

            double sum = 0;

            for (size_t k = 0; k < this->cols; k++) {
                sum += this->data[i][k] * inverse.getElement(k, j);
            }

            result.addElement(i, j, sum);
        }
    }

    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int n) {

    if (n <= 0) {
        throw invalid_argument("Taille invalide");
    }

    MatrixNumerical<T> identity(n, n);

    for (int i = 0; i < n; i++) {
        identity.addElement(i, i, T{1});
    }

    return identity;
}