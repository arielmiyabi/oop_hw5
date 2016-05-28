//¦¿©v¯§ 403410023 ¸ê¤u¤G

#include <iostream>
#include <cstring>
#include <stdio.h>

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

    const friend BigInt operator +(const BigInt &a, const BigInt &b); //operator plus overloading
    //precondition : a and b are BigInt type object.
    //postcondition : return the result of a + b.

    const friend BigInt operator -(const BigInt &a, const BigInt &b); //operator minus overloading
    //precondition : a and b are BigInt type object.
    //postcondition : return the result of a - b.

    friend ostream& operator <<(ostream& outputstream, const BigInt &a); //cout overloading
    //precondition : outputstream is a ostream type object. a is a BigInt type object.
    //postcondition : cout the bigInteger of a.

private:
    char* bigInteger; //points to a dynamic array
    int length; //the length of an array bigInteger points to
};

int main()
{
    while(1)
    {
        char optionChar1, optionChar2;
        string num1, num2;
        int smallnum1, smallnum2;
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
        return *this;
    }
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
    BigInt adderNumber;
    adderNumber.bigInteger = new char[maxLength+2-countOfZero];
    for(n = countOfZero;n<=maxLength;n++)
    {
        adderNumber.bigInteger[m++] = addNumber[n];
    }
    adderNumber.bigInteger[m] = '\0';

    return adderNumber;
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
        BigInt minuserNumber;
        minuserNumber.bigInteger = new char[maxLength+1-countOfZero];
        for(n = countOfZero;n<maxLength;n++)
        {
            minuserNumber.bigInteger[m++] = minusNumber[n];
        }
        minuserNumber.bigInteger[m] = '\0';
        return minuserNumber;
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
        BigInt minuserNumber;
        minuserNumber.bigInteger = new char[maxLength+2-countOfZero];
        minuserNumber.bigInteger[m++] = '-';
        for(n = countOfZero;n<maxLength;n++)
        {
            minuserNumber.bigInteger[m++] = minusNumber[n];
        }
        minuserNumber.bigInteger[m] = '\0';
        return minuserNumber;
    }
}
