#include <iostream>
#include "Rational.h"

using namespace std;

namespace ComplexNumber
{
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
    friend const Complex operator -(const Complex&num1);
    friend istream& operator >>(istream& input, Complex& num);
    friend ostream& operator <<(ostream& output, const Complex& num);
private:
    Rational realNum;
    Rational imaginaryNum;
};
}
