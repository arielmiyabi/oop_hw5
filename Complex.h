#include <iostream>
using namespace std;

#ifndef Complex_H
#define Complex_H
#include "Rational.h"

class Complex
{
public:
    Complex();
    //ComplexNum(Rational realNum);
    Complex(Rational newImaginaryNum);
    Complex(Rational newRealNum, Rational newImaginaryNum);
    Rational getRealNum() const;
    Rational getImaginaryNum() const;
    friend const Complex operator +(const Complex&num1, const Complex&num2);
    friend const Complex operator -(const Complex&num1, const Complex&num2);
    friend const Complex operator *(const Complex&num1, const Complex&num2);
    friend const Complex operator /(const Complex&num1, const Complex&num2);
    //Complex& Complex::operator =(const Complex&rightValue);
    friend const Complex operator -(const Complex&num1);
    //friend istream& operator >>(istream& input, Complex& num);
    friend ostream& operator <<(ostream& output, const Complex& num);
private:
    Rational realNum;
    Rational imaginaryNum;
};
#endif
