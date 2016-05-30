#include <iostream>
using namespace std;

class Complex
{
public:
    Complex();
    //ComplexNum(int realNum);
    Complex(int newImaginaryNum);
    Complex(int newRealNum, int newImaginaryNum);
    int getRealNum() const;
    int getImaginaryNum() const;
    friend istream& operator >>(istream& input, Complex& num);
    friend ostream& operator <<(ostream& output, const Complex& num);
private:
    int realNum;
    int imaginaryNum;
};
