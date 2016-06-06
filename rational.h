#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>
#include <cstdlib>

#include "bigint.h"

using namespace BigInt_Yo;
using namespace std;

namespace  Rational_Kai
{
class Rational
{
public:
    Rational();
    Rational(BigInt numeratorvalue);
    Rational(BigInt numeratorvalue,BigInt denominator);
    //BigInt gcd(const BigInt num1,const BigInt num2);
    BigInt getnumerator() const;
    BigInt getdenominator() const;
    friend istream &operator>>(istream &in,Rational &fraction);
    friend ostream &operator<<(ostream &out,const Rational &fraction);
    friend const Rational operator +(const Rational& fraction1 , const Rational& fraction2);
    friend const Rational operator -(const Rational& fraction1 , const Rational& fraction2);
    friend const Rational operator -(const Rational& fraction);
    friend const Rational operator *(const Rational& fraction1 , const Rational& fraction2);
    friend const Rational operator /(const Rational& fraction1 , const Rational& fraction2);
    friend const Rational operator ==(const Rational& fraction1 , const Rational& fraction2);
    bool operator==(const Rational& fraction);
    bool operator<(const Rational& fraction);
    bool operator<=(const Rational& fraction);
    bool operator>(const Rational& fraction);
    bool operator>=(const Rational& fraction);
    //int& operator[](int index);
private:
    BigInt numerator;
    BigInt denominator;
};
}
#endif // RATIONAL_H_INCLUDED
