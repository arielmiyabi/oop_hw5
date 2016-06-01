#include <iostream>
#include <stdlib.h>
#include <Bigint.h>

class  Rational
{
public:
    Rational();
    Rational(Bigint numeratorvalue);
    Rational(Bigint numeratorvalue, Bigint denominator);
    bigint getnumerator() const;
    int getdenominator() const;
    friend istream &operator>>(istream &in,Rational &fraction);
    friend ostream &operator<<(ostream &out,Rational &fraction);
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
    int& operator[](int index);
private:
    Bigint numerator;
    Bigint denominator;
};

