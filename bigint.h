#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

namespace BigInt_Yo
{
    class BigInt
    {
    public:
        BigInt(); //default constructor
        //postcondition : the private member pointer bigInteger points to NULL. the private member length sets to 0.

        //BigInt(char arr[]);

        BigInt(int integer); //constructor for integer
        //precondition : integer is an integer.
        //postcondition : the private member pointer bigInteger points to a dynamic array. the private member length sets to the length of integer.

        BigInt(const BigInt &iniObj); //copy constructor
        //precondition : iniObj is a BigInt type object.
        //postcondition : copy the iniObj to the calling object.

        BigInt(string stringOfNumber); //constructor for string
        //precondition : stringOfNumber is a string.
        //postcondition : the private member pointer bigInteger points to a dynamic array. the private member length sets to the length of stringOfNumber.

        ~BigInt(); //destructor
        //postcondition : delete the dynamic array that bigInteger points to, then points to NULL.

        int getLength();

        char* getBigint();

        int getSign();

        //int& operator [](int a);

        BigInt& operator =(const BigInt &rtSide); //assignment overloading
        //precondition : rtSide is a BigInt type object.
        //postcondition : assign the object rtSide to calling object.

        friend const BigInt operator +(const BigInt &a, const BigInt &b); //operator plus overloading
        //precondition : a and b are BigInt type object.
        //postcondition : return the result of a + b.

        friend const BigInt operator -(const BigInt &a, const BigInt &b); //operator minus overloading
        //precondition : a and b are BigInt type object.
        //postcondition : return the result of a - b.

        friend const BigInt operator -(const BigInt &a);

        friend const BigInt operator *(const BigInt &a, const BigInt &b);

        friend const BigInt operator /(const BigInt &a, const BigInt &b);

        friend const BigInt operator %(const BigInt &a, const BigInt &b);

        friend ostream& operator <<(ostream& outputstream, const BigInt &a); //cout overloading
        //precondition : outputstream is a ostream type object. a is a BigInt type object.
        //postcondition : cout the bigInteger of a.

        friend istream& operator >>(istream& inputstream, BigInt& a);

        const BigInt factorial(string factor);

        friend bool operator !=(const BigInt& a, const BigInt& b);

        friend bool operator ==(const BigInt& a, const BigInt& b);

        friend bool operator >=(const BigInt& a, const BigInt& b);

        friend bool operator >(const BigInt& a, const BigInt& b);

        friend bool operator <=(const BigInt& a, const BigInt& b);

        friend bool operator <(const BigInt& a, const BigInt& b);

    private:
        char* bigInteger; //points to a dynamic array
        int length; //the length of an array bigInteger points to
        int sign;
    };
}

#endif // BIGINT_H
