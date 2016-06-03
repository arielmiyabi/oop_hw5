#include <iostream>
#include "Complex.h"
//#include "BigInt.h"
#include "Rational.h"

using namespace std;
int main()
{
    //BigInt b1(1), b2(7), b3(8), b4(5), b5("100!"), b6("520!"), b7("128"), b8("320");
    //Rational a(b1, b2), b(b3, b4), c(b5, b6), d(b7, b8);
    Rational a(1,6), b(1,6), c(1,6), d(1,5);

    cout << a << " " << b << " " << c << " " << d << endl;

    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    Complex c1(a, b), c2(c, d), ans;


    cout<<"c1="<<c1<<"c2="<<c2<<"\n";
    ans=c1+c2;
    cout<<c1<<endl<<c2<<endl;
    cout<<"c1+c2= "<<ans<<endl;


    return 0;
}
