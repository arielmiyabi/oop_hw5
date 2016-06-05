#include <iostream>
#include "Complex.h"
#include "Rational.h"
using namespace std;
using namespace Rational_Kai;
namespace Complex_Hsuan
{

Complex::Complex()
{
    realNum=0;
    imaginaryNum=0;
}
//ComplexNum(Rational realNum);
Complex::Complex(Rational newImaginaryNum)
{
    realNum=0;
    imaginaryNum=newImaginaryNum;
}
Complex::Complex(Rational newRealNum, Rational newImaginaryNum)
{
    realNum=newRealNum;
    imaginaryNum=newImaginaryNum;
}
Rational Complex::getRealNum() const
{
    return realNum;
}
Rational Complex::getImaginaryNum() const
{
    return imaginaryNum;
}
const Complex operator +(const Complex&num1, const Complex&num2)
{
    Complex answer;
    answer.realNum=num1.realNum+num2.realNum;
    answer.imaginaryNum=num1.imaginaryNum+num2.imaginaryNum;
    return answer;
}
const Complex operator -(const Complex&num1, const Complex&num2)
{
    Complex answer;
    answer.realNum=num1.realNum-num2.realNum;
    answer.imaginaryNum=num1.imaginaryNum-num2.imaginaryNum;
    return answer;
}
const Complex operator *(const Complex&num1, const Complex&num2)
{
    Complex answer;
    answer.realNum=num1.realNum*num2.realNum-num1.imaginaryNum*num2.imaginaryNum;
    answer.imaginaryNum=num1.realNum*num1.imaginaryNum-num2.realNum*num2.imaginaryNum;
    return answer;
}
const Complex operator /(const Complex&num1, const Complex&num2)
{
    Complex answer;
    answer.realNum=(num1.realNum*num2.realNum+num1.imaginaryNum*num2.imaginaryNum)/(num2.realNum*num2.realNum+num2.imaginaryNum*num2.imaginaryNum);
    answer.imaginaryNum=(num1.realNum*num1.imaginaryNum+num2.realNum*num2.imaginaryNum)/(num2.realNum*num2.realNum+num2.imaginaryNum*num2.imaginaryNum);
    return answer;
}

/*Complex& Complex::operator =(const Complex&rightValue)
{
    realNum=rightValue.realNum;
    imaginaryNum=rightValue.imaginaryNum;
    return *this;
}
*/
const Complex operator -(const Complex&num1)
{
    return num1;
}
/*istream& operator >>(istream& input, Complex& num)
{
    Rational inputNum;
    istream >>inputNum;
    num.realNum=0;
    num.imaginaryNum=0;
    return input;
}*/

ostream& operator <<(ostream& out, const Complex& num)
{

    out << num.realNum <<" + "<< num.imaginaryNum <<"i"<<endl;
    return out;
}
}
