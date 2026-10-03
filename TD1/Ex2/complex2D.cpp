# include <iostream>
# include <cmath>
# include "complex2D.h"

using namespace std;

Complex2D::Complex2D(){
    re = 0;
    im = 0;
}

Complex2D::Complex2D(double re ,double im){
    this -> re = re;
    this -> im = im;
}

Complex2D::Complex2D(double a){
    this -> re = a;
    this -> im = a;
}

Complex2D::Complex2D(const Complex2D& num){
    this->re = num.re;
    this->im = num.im;
}

double Complex2D::get_re()const{
    return re;
}

void Complex2D::set_re(double nre){
    re = nre;
}

double Complex2D::get_im()const{
    return im;
}

void Complex2D::set_im(double nim){
    im = nim;
}

Complex2D Complex2D::operator+(const Complex2D num2){
    Complex2D res;
    res.im = this->im + num2.im;
    res.re = this->re + num2.re;
    return res;
}

Complex2D Complex2D::operator-(const Complex2D num2){
    Complex2D res;
    res.im = this->im - num2.im;
    res.re = this->re - num2.re;
    return res;
}

Complex2D Complex2D::operator*(const Complex2D num2){
    Complex2D res;
    res.im = (this->re * num2.im)+(this->im * num2.re);
    res.re = (this->re * num2.re)-(this->im * num2.im);
    return res;
}

Complex2D Complex2D::operator/(const Complex2D num2){
    Complex2D res;
    double denom = num2.re*num2.re + num2.im*num2.im;
    if (denom == 0){
        cout << "impossible" << endl;
    }
    res = Complex2D();
    res.im = ((this->im*num2.re) - (this->re*num2.im)) / denom;
    res.re = ((this->re*num2.re) + (this->im*num2.im)) / denom;
    return res;
}

bool Complex2D::operator<(const Complex2D num2){
    double module1 = sqrt((this->re)*(this->re) + (this->im)*(this->im));
    double module2 = sqrt((num2.re)*(num2.re) + (num2.im)*(num2.im));
    return module1 < module2;
}

bool Complex2D::operator>(const Complex2D num2){
    double module1 = sqrt((this->re)*(this->re) + (this->im)*(this->im));
    double module2 = sqrt((num2.re)*(num2.re) + (num2.im)*(num2.im));
    return module1 > module2;
}