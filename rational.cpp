#include <iostream>
#include <stdlib.h>

#include "bigint.h"
#include "rational.h"

using namespace BigInt_Yo;
using namespace std;


namespace Rational_Kai
{
Rational::Rational()
{
    numerator=0;
    denominator=1;
}
Rational::Rational(BigInt integervalue)
{
    numerator=integervalue;
    denominator=1;
}
Rational::Rational(BigInt numeratorvalue,BigInt denominatorvalue)
{
    numerator=numeratorvalue;
    denominator=denominatorvalue;
    /*if((numerator>0&&denominator<0)||(numerator<0&&denominator<0))
    {
        numerator[0]*=-1;
        denominator[0]*=-1;
    }*/
}

const Rational operator +(const Rational& fraction1 , const Rational& fraction2)//addition
{
    BigInt temp1_num,temp2_num,temp_den;
    if(fraction1.getdenominator() != fraction2.getdenominator())
    {
        temp1_num=fraction1.getnumerator()*fraction2.getdenominator();
        temp2_num=fraction2.getnumerator()*fraction1.getdenominator();
        temp_den=fraction1.getdenominator()*fraction2.getdenominator();
    }
    else
    {
        temp1_num=fraction1.getnumerator();
        temp2_num=fraction2.getnumerator();
        temp_den=fraction1.getdenominator();
    }
    BigInt tempnum(temp1_num+temp2_num);
    return Rational(tempnum,temp_den);
}

const Rational operator -(const Rational& fraction1 , const Rational& fraction2)//subtraction
{
    BigInt temp1_num,temp2_num,temp_den;
    if(fraction1.getdenominator() != fraction2.getdenominator())
    {
        temp1_num=fraction1.getnumerator()*fraction2.getdenominator();
        temp2_num=fraction2.getnumerator()*fraction1.getdenominator();
        temp_den=fraction1.getdenominator()*fraction2.getdenominator();

    }
    else
    {
        temp1_num=fraction1.getnumerator();
        temp2_num=fraction2.getnumerator();
        temp_den=fraction1.getdenominator();
    }
    BigInt tempnum(temp1_num-temp2_num);
    return Rational(tempnum,temp_den);
}

const Rational operator -(const Rational& fraction)//negation
{
    BigInt temp_num(fraction.getnumerator()*-1);
    BigInt temp_den(fraction.getdenominator());
    return Rational(temp_num,temp_den);
}

const Rational operator *(const Rational& fraction1 , const Rational& fraction2)//multiplication
{
    BigInt temp_num,temp_den;
    temp_num=fraction1.numerator*fraction2.numerator;
    temp_den=fraction1.denominator*fraction2.denominator;
    return Rational(temp_num,temp_den);
}

const Rational operator /(const Rational& fraction1 , const Rational& fraction2)//division
{
    BigInt temp_num,temp_den;
    temp_num=fraction1.numerator*fraction2.denominator;
    temp_den=fraction1.denominator*fraction2.numerator;
    return Rational(temp_num,temp_den);
}

istream &operator>>(istream& in,Rational& fraction1)
{
    while(1)//enter the first number
    {
        cout<<"choose which type of number you want enter to be the first number\n"<<"(1)default (2)fraction (3)integer\n";
        int choice;
        in>>choice;
        if(choice==1)
        {
            fraction1=Rational();
            break;
        }
        else if(choice==2)
        {
            cout<<"enter the numerator : \n";
            BigInt numeratorvalue,denominatorvalue;
            in>>numeratorvalue;
            while(1)//denominator can't be 0
            {
                cout<<"enter the denominator : \n";
                in>>denominatorvalue;
                if(denominatorvalue==0)
                    cout<<"denominator can't be 0\n"<<"please enter again\n";
                else
                    break;
            }
            fraction1=Rational(numeratorvalue,denominatorvalue);
            break;
        }
        else if(choice==3)
        {
            cout<<"enter the integer : \n";
            BigInt integervalue;
            in>>integervalue;
            fraction1=Rational(integervalue);
            break;
        }
        else
            cout<<"wrong order , please enter again\n";
    }
    return in;
}

ostream &operator<<(ostream& out,const Rational& fraction)//cout
{
    BigInt temp,num1(fraction.numerator),num2(fraction.denominator);
    BigInt answer;
    /*if (num1<0)
        num1*=-1;
    if (num2<0)
        num2*=-1;*/
    //cout<<num1<<" "<<num2<<endl;
    while (num1%num2!=0)
    {
        temp=num1%num2;
        num1=num2;
        num2=temp;
        //cout<<num1<<" "<<num2<<endl;
    }
    answer=num2;
    //cout<<"gcd="<<num2<<endl;
    num1=num1/answer;
    num2=num2/answer;
    if(num2==BigInt(0))
        out<<"error";
    else if(num2==BigInt(1))
        out<<fraction.numerator<<" ";
    else if(num1==BigInt(0))
        out<<"0 ";
    else
    out<<num1<<"/"<<num2;
    return out;
}

bool Rational::operator==(const Rational& fraction)
{
    return (this->numerator*fraction.denominator)==(this->denominator*fraction.numerator);
}

bool Rational::operator<(const Rational& fraction)
{
    return (this->numerator*fraction.denominator)<(this->denominator*fraction.numerator);
}

bool Rational::operator<=(const Rational& fraction)
{
    return (this->numerator*fraction.denominator)<=(this->denominator*fraction.numerator);
}

bool Rational::operator>(const Rational& fraction)
{
    return (this->numerator*fraction.denominator)>(this->denominator*fraction.numerator);
}

bool Rational::operator>=(const Rational& fraction)
{
    return (this->numerator*fraction.denominator)>=(this->denominator*fraction.numerator);
}

/*int& Rational::operator[](int index)
{
    if(index==0)
        return numerator;
    else if(index==1)
        return denominator;
}*/

BigInt Rational::getnumerator() const
{
    return numerator;
}

BigInt Rational::getdenominator() const
{
    return denominator;
}

}
