#include <iostream>
using namespace std;

class ComplexNum
{
public:
    ComplexNum();
    ComplexNum(int realNum);
    ComplexNum(int imaginaryNum);
    ComplexNum(int realNum, int imaginaryNum);
    int getRealNum();
    int getImaginaryNum();
    friend istream& operator >>(istream input, ComplexNum& num);
    friend ostream& operator <<(ostream output, const ComplexNum& num);
private:
    int realNum;
    int imaginaryNum
};
