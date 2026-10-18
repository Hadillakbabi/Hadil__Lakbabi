#include <iostream>
#include "MatrixNumerical.h"

using namespace std;

int main() {

    MatrixNumerical<double> A(2, 2);
    MatrixNumerical<double> B(2, 2);

    A.addElement(0, 0, 2);
    A.addElement(0, 1, 1);
    A.addElement(1, 0, 1);
    A.addElement(1, 1, 1);

    B.addElement(0, 0, 1);
    B.addElement(0, 1, 2);
    B.addElement(1, 0, 3);
    B.addElement(1, 1, 4);

    cout << " MATRICE A " << endl;
    A.display();

    cout << "\n MATRICE B " << endl;
    B.display();

    cout << "\n DIMENSIONS " << endl;
    cout << "Lignes A : " << A.getRows() << endl;
    cout << "Colonnes A : " << A.getCols() << endl;

    cout << "\n GET ELEMENT " << endl;
    cout << "A[0][1] = " << A.getElement(0, 1) << endl;

    cout << "\n ADDITION " << endl;
    MatrixNumerical<double> C = A + B;
    C.display();

    cout << "\n SOUSTRACTION " << endl;
    MatrixNumerical<double> D = A - B;
    D.display();

    cout << "\n MULTIPLICATION " << endl;
    MatrixNumerical<double> E = A * B;
    E.display();

    cout << "\n DETERMINANT " << endl;
    cout << "Det(A) = " << A.getDeterminant() << endl;
    cout << "Det(B) = " << B.getDeterminant() << endl;

    cout << "\n INVERSE " << endl;
    MatrixNumerical<double> F = A.getInverse();
    F.display();

    cout << "\n DIVISION " << endl;
    MatrixNumerical<double> G = A / B;
    G.display();

    cout << "\n MATRICE IDENTITE " << endl;
    MatrixNumerical<double> I =
        MatrixNumerical<double>::getIdentity(3);
    I.display();

    cout << "\n CONSTRUCTEUR PAR DEFAUT " << endl;
    MatrixNumerical<int> M;
    cout << "Lignes : " << M.getRows() << endl;
    cout << "Colonnes : " << M.getCols() << endl;

    cout << "\n MATRICE INT " << endl;
    MatrixNumerical<int> N(2, 2);
    N.addElement(0, 0, 5);
    N.addElement(0, 1, 3);
    N.addElement(1, 0, 2);
    N.addElement(1, 1, 4);
    N.display();

    cout << "Det(N) = " << N.getDeterminant() << endl;

    return 0;
}