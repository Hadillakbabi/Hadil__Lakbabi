#include <iostream>
#include "complex2D.h"

using namespace std;

int main() {

    //Test des constructeurs

    Complex2D z1;
    cout << "z1 = " << z1.get_re() << " + " << z1.get_im() << "i" << endl;

    Complex2D z2(2, 3);
    cout << "z2 = " << z2.get_re() << " + " << z2.get_im() << "i" << endl;

    Complex2D z3(5);
    cout << "z3 = " << z3.get_re() << " + " << z3.get_im() << "i" << endl;

    Complex2D z4(z2);
    cout << "z4 = " << z4.get_re() << " + " << z4.get_im() << "i" << endl;


    // Test setters
    z1.set_re(4);
    z1.set_im(2);

    cout << "\nApres modification de z1 :" << endl;
    cout << "z1 = " << z1.get_re() << " + " << z1.get_im() << "i" << endl;


    // Addition
    Complex2D somme = z1 + z2;

    cout << "\nz1 + z2 = "
         << somme.get_re() << " + "
         << somme.get_im() << "i" << endl;


    // Soustraction
    Complex2D difference = z1 - z2;

    cout << "z1 - z2 = "
         << difference.get_re() << " + "
         << difference.get_im() << "i" << endl;


    // Multiplication
    Complex2D produit = z1 * z2;

    cout << "z1 * z2 = "
         << produit.get_re() << " + "
         << produit.get_im() << "i" << endl;


    // Division
    Complex2D quotient = z1 / z2;

    cout << "z1 / z2 = "
         << quotient.get_re() << " + "
         << quotient.get_im() << "i" << endl;


    // Comparaison
    if (z1 < z2) {
        cout << "\nLe module de z1 est plus petit que celui de z2." << endl;
    }
    else if (z1 > z2) {
        cout << "\nLe module de z1 est plus grand que celui de z2." << endl;
    }
    else {
        cout << "\nz1 et z2 ont le meme module." << endl;
    }


    return 0;
}
