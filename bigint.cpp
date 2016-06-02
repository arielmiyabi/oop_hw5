#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

#include "bigint.h"

using namespace BigInt_Yo;

ostream& operator <<(ostream& outputstream, const BigInt &a)
{
    outputstream << a.getBigint() << endl;
    return outputstream;
}

BigInt::BigInt()
{
    bigInteger = NULL;
    length = 0;
}

BigInt::BigInt(char arr[])
{
    int countOfZero = 0, n = 0, m = 0;
    while(arr[n]=='0')
    {
        countOfZero++;
        n++;
    }
    char arr2[strlen(arr)-countOfZero+1];
    for(n = countOfZero;n<strlen(arr);n++)
    {
        arr2[m++] = arr[n];
    }
    arr2[m] = '\0';
    length = strlen(arr2);
    bigInteger = new char[length+1];
    for(n = 0;n<length;n++){
        bigInteger[n] = arr2[n];
    }
    bigInteger[n] = '\0';
}

BigInt::BigInt(int integer)
{
    char tmp[11];
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

int BigInt::getLength() const
{
    return length;
}

char* BigInt::getBigint() const
{
    return bigInteger;
}

const bool operator !=(const BigInt& a, const BigInt& b)
{
    if(a.getLength()==b.getLength())
    {
        if(strcmp(a.getBigint(), b.getBigint())!=0) return true;
        else return false;
    }
    else return true;
}

const bool operator ==(const BigInt& a, const BigInt& b)
{
    if((a.getLength()==b.getLength())&&(strcmp(a.getBigint(), b.getBigint())==0)) return true;
    else return false;
}

const bool operator >=(const BigInt& a, const BigInt& b)
{
    if(a.getLength()>b.getLength()) return true;
    else if((a.getLength()==b.getLength())&&(strcmp(a.getBigint(), b.getBigint())>=0)) return true;
    else return false;
}

const bool operator >(const BigInt& a, const BigInt& b)
{
    if(a.getLength()>b.getLength()) return true;
    else if((a.getLength()==b.getLength())&&(strcmp(a.getBigint(), b.getBigint())>0)) return true;
    else return false;
}

const bool operator <=(const BigInt& a, const BigInt& b)
{
    if(a.getLength()<b.getLength()) return true;
    else if((a.getLength()==b.getLength())&&(strcmp(a.getBigint(), b.getBigint())<=0)) return true;
    else return false;
}
const bool operator <(const BigInt& a, const BigInt& b)
{
    if(a.getLength()<b.getLength()) return true;
    else if((a.getLength()==b.getLength())&&(strcmp(a.getBigint(), b.getBigint())<0)) return true;
    else return false;
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

const BigInt operator %(const BigInt &a, const BigInt &b)
{
    if(b==BigInt(0)) return BigInt("error.");
    BigInt cpy_a(a);
    while(cpy_a>=b)
    {
        char tmp_a[b.length+2];
        int i, bit;
        memset(tmp_a, '0', b.length+1);
        tmp_a[b.length+1] = '\0';
        for(i = 0;i<b.length;i++)
        {
            tmp_a[1+i] = cpy_a.bigInteger[i];
            bit = i;
        }
        int countOfZero = 0, n = 0, m = 0;
        while(tmp_a[n]=='0')
        {
            countOfZero++;
            n++;
        }
        char tmp2_a[strlen(tmp_a)-countOfZero+1];
        for(n = countOfZero;n<strlen(tmp_a);n++)
        {
            tmp2_a[m++] = tmp_a[n];
        }
        tmp2_a[m] = '\0';
        if(strcmp(tmp2_a, b.bigInteger)<0)
        {
            for(i = 0;i<=b.length;i++)
            {
                tmp_a[i] = cpy_a.bigInteger[i];
                bit = i;
            }
            BigInt tmpOfA(tmp_a);
            for(i = 9;i>=0;i--)
            {
                if(BigInt(i)*b<=tmpOfA)
                {
                    bit = cpy_a.length-bit-1;
                    BigInt pow10(1), q = BigInt(i)*b;
                    while(bit--)
                    {
                        pow10 = pow10*BigInt(10);
                    }
                    cpy_a = cpy_a-(q*pow10);
                    break;
                }
            }
        }
        else
        {
            BigInt tmpOfA(tmp2_a);
            for(i = 9;i>=0;i--)
            {
                if(BigInt(i)*b<=tmpOfA)
                {
                    bit = cpy_a.length-bit-1;
                    BigInt pow10(1), q = BigInt(i)*b;
                    while(bit--)
                    {
                        pow10 = pow10*BigInt(10);
                    }
                    cpy_a = cpy_a-(q*pow10);
                    break;
                }
            }
        }
    }
    return BigInt(cpy_a);
}

const BigInt operator /(const BigInt &a, const BigInt &b)
{
    if(b==BigInt(0)) return BigInt("error.");
    BigInt result(0);
    int j, bit;
    BigInt cpy_a(a);
    while(cpy_a!=BigInt(0))
    {
        char tmp_a[b.length+2];
        int i;
        memset(tmp_a, '0', b.length+1);
        tmp_a[b.length+1] = '\0';
        for(i = 0;i<b.length;i++)
        {
            tmp_a[1+i] = cpy_a.bigInteger[i];
            bit = i;
        }
        int countOfZero = 0, n = 0, m = 0;
        while(tmp_a[n]=='0')
        {
            countOfZero++;
            n++;
        }
        char tmp2_a[strlen(tmp_a)-countOfZero+1];
        for(n = countOfZero;n<strlen(tmp_a);n++)
        {
            tmp2_a[m++] = tmp_a[n];
        }
        tmp2_a[m] = '\0';
        if(strcmp(tmp2_a, b.bigInteger)<0)
        {
            for(i = 0;i<=b.length;i++)
            {
                tmp_a[i] = cpy_a.bigInteger[i];
                bit = i;
            }
            BigInt tmpOfA(tmp_a);
            for(i = 9;i>=0;i--)
            {
                if(BigInt(i)*b<=tmpOfA)
                {
                    int tmpbit;
                    bit = cpy_a.length-bit-1;
                    tmpbit = bit;
                    BigInt pow10(1), q = BigInt(i)*b;
                    while(bit--)
                    {
                        pow10 = pow10*BigInt(10);
                    }
                    cpy_a = cpy_a-(q*pow10);
                    result = result + (pow10*BigInt(i));
                    break;
                }
            }
        }
        else
        {
            BigInt tmpOfA(tmp2_a);
            for(i = 9;i>=0;i--)
            {
                if(BigInt(i)*b<=tmpOfA)
                {
                    int tmpbit;
                    bit = cpy_a.length-bit-1;
                    tmpbit = bit;
                    BigInt pow10(1), q = BigInt(i)*b;
                    while(bit--)
                    {
                        pow10 = pow10*BigInt(10);
                    }
                    cpy_a = cpy_a-(q*pow10);
                    result = result + (pow10*BigInt(i));
                    break;
                }
            }
        }
    }
    return BigInt(result);
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
        //cout << result << endl;
    }
    cout<<result;
}
