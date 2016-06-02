/*************************/
/*Information Engineering*/
/*     second grade      */
/*     Liu Chung kai     */
/*       403410057       */
/*************************/
#include <iostream>
#include <stdlib.h>
#include "bigint.h"

using namespace std;

class  Rational
{
public:
    Rational();
    Rational(int numeratorvalue);
    Rational(int numeratorvalue, int denominator);
    int getnumerator() const;
    int getdenominator() const;
    friend istream &operator>>(istream &in,Rational &fraction);
    friend ostream &operator<<(ostream &out,Rational &fraction);
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
    int numerator;
    int denominator;
};
const Rational operator +(const Rational& fraction1 , const Rational& fraction2);
const Rational operator -(const Rational& fraction1 , const Rational& fraction2);
const Rational operator -(const Rational& fraction);

int main()
{
    Rational fraction1,fraction2;
    cin>>fraction1>>fraction2;
    system("cls");
    cout<<"result : \n"<<"First number = "<<fraction1<<"\nSecond number = "<<fraction2<<endl;
    Rational fraction3;
    fraction3=fraction1+fraction2;
    cout<<fraction1<<"+ "<<fraction2<<"= "<<fraction3<<endl;
    fraction3=fraction1-fraction2;
    cout<<fraction1<<"- "<<fraction2<<"= "<<fraction3<<endl;
    fraction3=fraction1*fraction2;
    cout<<fraction1<<"* "<<fraction2<<"= "<<fraction3<<endl;
    fraction3=fraction1/fraction2;
    cout<<fraction1<<"/ "<<fraction2<<"= "<<fraction3<<endl;
    fraction3=-fraction1;
    cout<<"- ( "<<fraction1<<") = "<<fraction3<<endl;
    fraction3=-fraction2;
    cout<<"- ( "<<fraction2<<") = "<<fraction3<<endl<<endl;

    bool x;
    x=(fraction1==fraction2);
    cout<<"If "<<fraction1<<"== "<<fraction2<<"?  "<<(x == 0 ? "False": "True")<<endl;
    x=(fraction1<fraction2);
    cout<<"If "<<fraction1<<"< "<<fraction2<<"?   "<<(x == 0 ? "False": "True")<<endl;
    x=(fraction1<=fraction2);
    cout<<"If "<<fraction1<<"<= "<<fraction2<<"?  "<<(x == 0 ? "False": "True")<<endl;
    x=(fraction1>fraction2);
    cout<<"If "<<fraction1<<"> "<<fraction2<<"?   "<<(x == 0 ? "False": "True")<<endl;
    x=(fraction1>=fraction2);
    cout<<"If "<<fraction1<<">= "<<fraction2<<"?  "<<(x == 0 ? "False": "True")<<endl;
    cout<<fraction1<<"numerator [0] = "<<fraction1[0]<<"  denomination [1] = "<<fraction1[1]<<endl;
    cout<<fraction2<<"numerator [0] = "<<fraction2[0]<<"  denomination [1] = "<<fraction2[1]<<endl;
    return 0;
}

Rational::Rational()
{
    numerator=0;
    denominator=1;
}
Rational::Rational(int integervalue)
{
    numerator=integervalue;
    denominator=1;
}
Rational::Rational(int numeratorvalue,int denominatorvalue)
{
    numerator=numeratorvalue;
    denominator=denominatorvalue;
    if((numerator>0&&denominator<0)||(numerator<0&&denominator<0))
    {
        numerator*=-1;
        denominator*=-1;
    }
}

const Rational operator +(const Rational& fraction1 , const Rational& fraction2)//addition
{
    int temp1_num,temp2_num,temp_den;
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
    int tempnum(temp1_num+temp2_num);
    return Rational(tempnum,temp_den);
}

const Rational operator -(const Rational& fraction1 , const Rational& fraction2)//subtraction
{
    int temp1_num,temp2_num,temp_den;
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
    int tempnum(temp1_num-temp2_num);
    return Rational(tempnum,temp_den);
}

const Rational operator -(const Rational& fraction)//negation
{
    int temp_num(fraction.getnumerator()*-1);
    int temp_den(fraction.getdenominator());
    return Rational(temp_num,temp_den);
}

const Rational operator *(const Rational& fraction1 , const Rational& fraction2)//multiplication
{
    int temp_num,temp_den;
    temp_num=fraction1.numerator*fraction2.numerator;
    temp_den=fraction1.denominator*fraction2.denominator;
    return Rational(temp_num,temp_den);
}

const Rational operator /(const Rational& fraction1 , const Rational& fraction2)//division
{
    int temp_num,temp_den;
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
            int numeratorvalue,denominatorvalue;
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
            int integervalue;
            in>>integervalue;
            fraction1=Rational(integervalue);
            break;
        }
        else
            cout<<"wrong order , please enter again\n";
    }
    return in;
}

ostream &operator<<(ostream& out,Rational& fraction)//cout
{
    for(int i=abs(fraction.numerator);i>1;i--)
    {
        if(fraction.denominator%i==0&&fraction.numerator%i==0)
        {
            fraction.numerator/=i;
            fraction.denominator/=i;
        }
    }
    if(fraction.denominator==0)
        out<<"error";
    else if(fraction.denominator==1)
        out<<fraction.numerator<<" ";
    else if(fraction.numerator==0)
        out<<"0 ";
    else
        out<<fraction.numerator<<"/"<<fraction.denominator<<" ";
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

int& Rational::operator[](int index)
{
    if(index==0)
        return numerator;
    else if(index==1)
        return denominator;
}

int Rational::getnumerator() const
{
    return numerator;
}

int Rational::getdenominator() const
{
    return denominator;
}
