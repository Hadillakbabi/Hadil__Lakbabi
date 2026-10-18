#include "MatrixBase.h"

template <typename T>
MatrixBase<T>::MatrixBase() {
    rows = 0;
    cols = 0;
}

template <typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c) {
    rows = r;
    cols = c;
    data = vector<vector<T>>(r, vector<T>(c, T{}));
}

template <typename T>
void MatrixBase<T>::addElement(size_t i, size_t j, T value) {
    if (i >= rows || j >= cols) {
        throw out_of_range("Indice invalide");
    }

    data[i][j] = value;
}

template <typename T>
T MatrixBase<T>::getElement(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        throw out_of_range("Indice invalide");
    }

    return data[i][j];
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}

template <typename T>
void MatrixBase<T>::display() const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}