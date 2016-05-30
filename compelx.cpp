#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex()
{
    realNum=0;
    imaginaryNum=0;
}
//ComplexNum(int realNum);
Complex::Complex(int newImaginaryNum)
{
    realNum=0;
    imaginaryNum=newImaginaryNum;
}
Complex::Complex(int newRealNum, int newImaginaryNum)
{
    realNum=newRealNum;
    imaginaryNum=newImaginaryNum;
}
int Complex::getRealNum() const
{
    return realNum;
}
int Complex::getImaginaryNum() const
{
    return imaginaryNum;
}
istream& operator >>(istream& input, Complex& num)
{
    return input;
}
ostream& operator <<(ostream& output, const Complex& num)
{
    output << num.realNum <<" + "<< num.imaginaryNum <<"i";
    return output;
}
