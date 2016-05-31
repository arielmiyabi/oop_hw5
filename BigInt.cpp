#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class BigInt
{
public:
    BigInt(); //default constructor
    //postcondition : the private member pointer bigInteger points to NULL. the private member length sets to 0.

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

    BigInt& operator =(const BigInt &rtSide); //assignment overloading
    //precondition : rtSide is a BigInt type object.
    //postcondition : assign the object rtSide to calling object.

    friend const BigInt operator +(const BigInt &a, const BigInt &b); //operator plus overloading
    //precondition : a and b are BigInt type object.
    //postcondition : return the result of a + b.

    friend const BigInt operator -(const BigInt &a, const BigInt &b); //operator minus overloading
    //precondition : a and b are BigInt type object.
    //postcondition : return the result of a - b.

    friend const BigInt operator *(const BigInt &a, const BigInt &b);

    friend const BigInt operator /(const BigInt &a, const BigInt &b);

    friend ostream& operator <<(ostream& outputstream, const BigInt &a); //cout overloading
    //precondition : outputstream is a ostream type object. a is a BigInt type object.
    //postcondition : cout the bigInteger of a.

    friend const BigInt factorial(string factor);

private:
    char* bigInteger; //points to a dynamic array
    int length; //the length of an array bigInteger points to
};

const BigInt factorial(string factor);

int main()
{
    /*string test1;
    cin >> test1;
    BigInt test(test1);
    cout << test << "\n";*/
    while(1)
    {
        char optionChar1, optionChar2;
        string num1, num2;
        int smallnum1, smallnum2;
        /*cout << "factorial : ";
        cin >> num1;
        BigInt tmpnum(num1);
        char tmpnum1[strlen(num1.c_str())+1];
        strcpy(tmpnum1, num1.c_str());
        if(tmpnum1[strlen(num1.c_str())-1]=='!')
        {
            factorial(num1);
        }*/
        cout << "First number is less than or equal to 2,147,483,647(y/n) : ";
        cin >> optionChar1;
        cout << "Second number is less than or equal to 2,147,483,647(y/n) : ";
        cin >> optionChar2;
        if(optionChar1=='y'&&optionChar2=='y')
        {
            cout << "\nInput two integers.\n\n"
                 << "First number : ";
            cin >> smallnum1;
            cout << "Second number : ";
            cin >> smallnum2;
            BigInt *number1 = new BigInt(smallnum1);
            BigInt *number2 = new BigInt(smallnum2);
            BigInt number3;
            number3 = *number1+*number2;
            cout << *number1 << " + " << *number2 << " = " << number3 << endl;
            number3 = *number1-*number2;
            cout << *number1 << " - " << *number2 << " = " << number3 << endl;
            number3 = (*number1)*(*number2);
            cout << *number1 << " * " << *number2 << " = " << number3 << endl;
            number3 = (*number1)/(*number2);
            cout << *number1 << " / " << *number2 << " = " << number3 << endl;
        }
        else if(optionChar1=='y'&&optionChar2=='n')
        {
            cout << "\nInput two integers.\n\n"
                 << "First number : ";
            cin >> smallnum1;
            cout << "Second number : ";
            cin >> num2;
            BigInt *number1 = new BigInt(smallnum1);
            BigInt number2(num2), number3(number2);
            number3 = *number1+number2;
            cout << *number1 << " + " << number2 << " = " << number3 << endl;
            number3 = *number1-number2;
            cout << *number1 << " - " << number2 << " = " << number3 << endl;
            number3 = (*number1)*number2;
            cout << *number1 << " * " << number2 << " = " << number3 << endl;
            number3 = (*number1)/number2;
            cout << *number1 << " / " << number2 << " = " << number3 << endl;
        }
        else if(optionChar1=='n'&&optionChar2=='y')
        {
            cout << "\nInput two integers.\n\n"
                 << "First number : ";
            cin >> num1;
            cout << "Second number : ";
            cin >> smallnum2;
            BigInt *number2 = new BigInt(smallnum2);
            BigInt number1(num1), number3(number1);
            number3 = number1+*number2;
            cout << number1 << " + " << *number2 << " = " << number3 << endl;
            number3 = number1-*number2;
            cout << number1 << " - " << *number2 << " = " << number3 << endl;
            number3 = number1*(*number2);
            cout << number1 << " * " << *number2 << " = " << number3 << endl;
            number3 = number1/(*number2);
            cout << number1 << " / " << *number2 << " = " << number3 << endl;
        }
        else
        {
            cout << "\nInput two integers.\n\n"
                 << "First number : ";
            cin >> num1;
            cout << "Second number : ";
            cin >> num2;
            BigInt number1(num1), number2(num2), number3(number1);
            number3 = number1+number2;
            cout << number1 << " + " << number2 << " = " << number3 << endl;
            number3 = number1-number2;
            cout << number1 << " - " << number2 << " = " << number3 << endl;
            number3 = number1*number2;
            cout << number1 << " * " << number2 << " = " << number3 << endl;
            number3 = number1/number2;
            cout << number1 << " / " << number2 << " = " << number3 << endl;
        }
        cout << "\nContinue?(y/n) : ";
        cin >> optionChar1;
        if(optionChar1=='n'||optionChar1=='N') break;
    }
    return 0;
}

ostream& operator <<(ostream& outputstream, const BigInt &a)
{
    outputstream << a.bigInteger;
    return outputstream;
}

BigInt::BigInt()
{
    bigInteger = NULL;
    length = 0;
}

BigInt::BigInt(int integer)
{
    char tmp[10];
    sprintf(tmp, "%d", integer);
    bigInteger = new char[strlen(tmp)+1];
    int n;
    for(n = 0;n<strlen(tmp);n++)
    {
        bigInteger[n] = tmp[n];
    }
    bigInteger[n] = '\0';
    length = strlen(tmp);
}

BigInt::BigInt(const BigInt &iniObj)
{
    int n;
    bigInteger = new char[strlen(iniObj.bigInteger)+1];
    for(n = 0;n<strlen(iniObj.bigInteger);n++)
    {
        bigInteger[n] = iniObj.bigInteger[n];
    }
    bigInteger[n] = '\0';
    length = strlen(iniObj.bigInteger);
}

BigInt::BigInt(string stringOfNumber)
{
    length = strlen(stringOfNumber.c_str());
    bigInteger = new char[length+1];
    int n = 0;
    for(;n<length;n++){
        bigInteger[n] = stringOfNumber.c_str()[n];
    }
    bigInteger[n] = '\0';
}

BigInt::~BigInt()
{
    delete [] bigInteger;
    bigInteger = NULL;
}

BigInt& BigInt::operator =(const BigInt &rtSide)
{
    if(this==&rtSide)
        return *this;
    else
    {
        int n;
        delete [] bigInteger;
        bigInteger = new char[strlen(rtSide.bigInteger)+1];
        for(n = 0;n<strlen(rtSide.bigInteger);n++)
        {
            bigInteger[n] = rtSide.bigInteger[n];
        }
        bigInteger[n] = '\0';
        length = rtSide.length;
        return *this;
    }
}

const BigInt operator /(const BigInt &a, const BigInt &b)
{
    BigInt q(1), tmp;
    tmp = b*q;
    while(strcmp(tmp.bigInteger, a.bigInteger)!=0)
    {
        q = q + BigInt(1);
        tmp = b*q;
    }
    return BigInt(q);
}

const BigInt operator *(const BigInt &a, const BigInt &b)
{
    int *multi = new int[a.length+b.length];
    int i, j, k, tempk, l;
    for(j = 0;j<a.length+b.length;j++)
    {
        multi[j] = 0;
    }
    int *cpya = new int [a.length];
    for(j = 0;j<a.length;j++)
    {
        cpya[j] = a.bigInteger[j]-'0';
    }
    int *cpyb = new int [b.length];
    for(j = 0;j<b.length;j++)
    {
        cpyb[j] = b.bigInteger[j]-'0';
    }
    k = a.length+b.length-1;
    tempk = k;
    for(i = b.length-1;i>=0;i--)
    {
        for(j = a.length-1;j>=0;j--, tempk--)
        {
            multi[tempk] = cpya[j]*cpyb[i]+multi[tempk];
        }
        for(l = a.length+b.length-1;l>0;l--)
        {
            multi[l-1] = multi[l]/10 + multi[l-1];
            multi[l] = multi[l]%10;
        }
        k--;
        tempk = k;
    }
    int countOfZero = 0, n = 0, m = 0;
    while(multi[n]==0)
    {
        countOfZero++;
        n++;
    }
    if(countOfZero==a.length+b.length)
    {
        return BigInt(0);
    }
    char multiNumber[a.length+b.length-countOfZero];
    for(n = countOfZero;n<a.length+b.length;n++)
    {
        multiNumber[m++] = multi[n]+'0';
    }
    multiNumber[m] = '\0';
    string returnNumber = multiNumber;
    return BigInt(returnNumber);
}

const BigInt operator +(const BigInt &a, const BigInt &b)
{
    int m, n, maxLength = (a.length>=b.length?a.length:b.length);
    char *cpyNumber, *addNumber;
    addNumber = new char[maxLength+2];
    memset(addNumber, '0', maxLength+1);
    addNumber[maxLength+1] = '\0';
    cpyNumber = new char[maxLength+1];
    if(maxLength==a.length)
    {
        n = strlen(b.bigInteger)-1;
        memset(cpyNumber, '0', maxLength);
        cpyNumber[maxLength] = '\0';
        for(m=maxLength-1;m>=a.length-b.length;m--)
        {
            cpyNumber[m] = b.bigInteger[n--];
        }
        n=maxLength;
        for(m=maxLength-1;m>=0;m--)
        {
            if(((a.bigInteger[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))>=0&&((a.bigInteger[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))<=9)
            {
                addNumber[n--] = ((a.bigInteger[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))+'0';
            }
            else
            {
                addNumber[n--] = ((a.bigInteger[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))-10+'0';
                addNumber[n] = '1';
            }
        }
    }
    else
    {
        n = strlen(a.bigInteger)-1;
        memset(cpyNumber, '0', maxLength);
        cpyNumber[maxLength] = '\0';
        for(m=maxLength-1;m>=b.length-a.length;m--)
        {
            cpyNumber[m] = a.bigInteger[n--];
        }
        n=maxLength;
        for(m=maxLength-1;m>=0;m--)
        {
            if(((b.bigInteger[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))>=0&&((b.bigInteger[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))<=9)
            {
                addNumber[n--] = ((b.bigInteger[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))+'0';
            }
            else
            {
                addNumber[n--] = ((b.bigInteger[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))-10+'0';
                addNumber[n] = '1';
            }
        }
    }
    int countOfZero = 0;
    n = 0, m = 0;
    while(addNumber[n]=='0')
    {
        countOfZero++;
        n++;
    }
    char adderNumber[maxLength+1-countOfZero];
    for(n = countOfZero;n<=maxLength;n++)
    {
        adderNumber[m++] = addNumber[n];
    }
    adderNumber[m] = '\0';
    string returnNumber = adderNumber;
    return BigInt(returnNumber);
}

const BigInt operator -(const BigInt &a, const BigInt &b)
{
    int ide, m, n, maxLength = (a.length>=b.length?a.length:b.length);
    char *cpyNumber, *minusNumber;
    minusNumber = new char[maxLength+1];
    memset(minusNumber, '0', maxLength);
    minusNumber[maxLength] = '\0';
    cpyNumber = new char[maxLength+1];
    if(a.length==b.length){
        ide = strcmp(a.bigInteger, b.bigInteger);
    }
    else if(maxLength==a.length){
        ide = 1;
    }
    else{
        ide = -1;
    }
    if(ide!=-1)
    {
        n = strlen(b.bigInteger)-1;
        memset(cpyNumber, '0', maxLength);
        cpyNumber[maxLength] = '\0';
        for(m=maxLength-1;m>=a.length-b.length;m--)
        {
            cpyNumber[m] = b.bigInteger[n--];
        }
        n=maxLength-1;
        for(m=maxLength-1;m>=0;m--)
        {
            if(((a.bigInteger[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))>=0&&((a.bigInteger[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))<=9)
            {
                minusNumber[n--] = ((a.bigInteger[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))+'0';
            }
            else
            {
                minusNumber[n--] = ((a.bigInteger[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))+10+'0';
                minusNumber[n] = '1';
            }
        }
        int countOfZero = 0;
        n = 0, m = 0;
        while(minusNumber[n]=='0')
        {
            countOfZero++;
            n++;
        }
        if(countOfZero==maxLength)
        {
            return BigInt(0);
        }
        char minuserNumber[maxLength-countOfZero];
        for(n = countOfZero;n<maxLength;n++)
        {
            minuserNumber[m++] = minusNumber[n];
        }
        minuserNumber[m] = '\0';
        string returnNumber = minuserNumber;
        return BigInt(returnNumber);
    }
    else
    {
        n = strlen(a.bigInteger)-1;
        memset(cpyNumber, '0', maxLength);
        cpyNumber[maxLength] = '\0';
        for(m=maxLength-1;m>=b.length-a.length;m--)
        {
            cpyNumber[m] = a.bigInteger[n--];
        }
        n=maxLength-1;
        for(m=maxLength-1;m>=0;m--)
        {
            if(((b.bigInteger[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))>=0&&((b.bigInteger[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))<=9)
            {
                minusNumber[n--] = ((b.bigInteger[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))+'0';
            }
            else
            {
                minusNumber[n--] = ((b.bigInteger[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))+10+'0';
                minusNumber[n] = '1';
            }
        }
        int countOfZero = 0;
        n = 0, m = 0;
        while(minusNumber[n]=='0')
        {
            countOfZero++;
            n++;
        }
        char minuserNumber[maxLength+1-countOfZero];
        minuserNumber[m++] = '-';
        for(n = countOfZero;n<maxLength;n++)
        {
            minuserNumber[m++] = minusNumber[n];
        }
        minuserNumber[m] = '\0';
        string returnNumber = minuserNumber;
        return BigInt(returnNumber);
    }
}

const BigInt factorial(string factor)
{
    int l = strlen(factor.c_str());
    char cpytmp[l], cpy[l-1];
    strcpy(cpytmp, factor.c_str());
    int i = 0;
    for(;i<l-1;i++)
    {
        cpy[i] = cpytmp[i];
    }
    i = atoi(cpy);
    BigInt tmp(1), result(1);
    while(i--)
    {
        result = tmp*result;
        tmp = tmp + BigInt(1);
        cout << result << endl;
    }
}
