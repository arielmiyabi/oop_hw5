#include <iostream>
#include "Complex.h"
#include "bigint.h"
#include "Rational.h"
using namespace std;
using namespace BigInt_Yo;
using namespace Rational_Kai;
using namespace Complex_Hsuan;
int main()
{
    BigInt b1(10), b2(1), b3(8), b4(5), b5("100!"), b6("520!"), b7("128"), b8("320"), ans;
    //Rational a(b1, b2), b(b3, b4), c(b5, b6), d(b7, b8);

    cout<<"b1="<<b1<<endl;
    cout<<"b2="<<b2<<endl;
    cout<<"b3="<<b3<<endl;
    cout<<"b4="<<b4<<endl;
    cout<<"b5="<<b5<<endl;
    cout<<"b6="<<b6<<endl;
    cout<<"b7="<<b7<<endl;
    cout<<"b8="<<b8<<endl;

    ans=b1*b2;
    cout<<"ans="<<ans<<endl;
    ans=b1+b2;
    cout<<"ans="<<ans<<endl;
    ans=b1-b2;
    cout<<"ans="<<ans<<endl;
    cout<<"here\n";
    ans=b1/b2;
    //cout<<"success!!\n";
    cout<<"ans="<<ans<<endl;
/*    Rational a(1,6), b(1,6), c(1,6), d(1,5);
    cout << a << " " << b << " " << c << " " << d << endl;

    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    Complex c1(a, b), c2(c, d), ans2;


    cout<<"c1="<<c1<<"c2="<<c2<<"\n";
    ans2=c1+c2;
    cout<<c1<<endl<<c2<<endl;
    cout<<"c1+c2= "<<ans2<<endl;
*/

    return 0;
}
