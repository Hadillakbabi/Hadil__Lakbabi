#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
    
private:
    double re;
    double im;

public:

    Complex2D();
    Complex2D(double re ,double im);
    Complex2D(double a);
    Complex2D(const Complex2D& num);
    void set_re(double nre);
    double get_re()const;
    void set_im(double nim);
    double get_im()const;
    Complex2D operator+(const Complex2D num2);
    Complex2D operator-(const Complex2D num2);
    Complex2D operator*(const Complex2D num2);
    Complex2D operator/(const Complex2D num2);
    bool operator<(const Complex2D num2);
    bool operator>(const Complex2D num2);
};

#endif