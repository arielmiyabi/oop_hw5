#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

#include "bigint.h"

namespace BigInt_Yo
{
    ostream& operator <<(ostream& outputstream, const BigInt &a)
    {
        BigInt cpy_a(a);
        if(cpy_a.getSign()==0)
        {
            outputstream << "-" << cpy_a.getBigint() << endl;
        }
        else
        {
            outputstream << cpy_a.getBigint() << endl;
        }
        return outputstream;
    }

    istream& operator >>(istream& inputstream, BigInt& a)
    {
        string bigint;
        inputstream >> bigint;
        a = BigInt(bigint);
        return inputstream;
    }

    BigInt::BigInt()
    {
        sign = 1;
        bigInteger = NULL;
        length = 0;
    }

    /*BigInt::BigInt(char arr[])
    {
        int countOfZero = 0, n = 0, m = 0;
        if(arr[0]=='-')
        {
            n++;
        }
        while(arr[n]=='0')
        {
            countOfZero++;
            n++;
        }
        if(arr[0]=='-')
        {
            n++;
            m++;
            char arr2[strlen(arr)-countOfZero+1];
            arr2[0] = '-';
            for(n = countOfZero+1; n<strlen(arr); n++)
            {
                arr2[m++] = arr[n];
            }
            arr2[m] = '\0';
            length = strlen(arr2)-1;
            bigInteger = new char[length+2];
            for(n = 0; n<length+1; n++)
            {
                bigInteger[n] = arr2[n];
            }
            bigInteger[n] = '\0';
        }
        else
        {
            char arr2[strlen(arr)-countOfZero+1];
            for(n = countOfZero; n<strlen(arr); n++)
            {
                arr2[m++] = arr[n];
            }
            arr2[m] = '\0';
            length = strlen(arr2);
            bigInteger = new char[length+1];
            for(n = 0; n<length; n++)
            {
                bigInteger[n] = arr2[n];
            }
            bigInteger[n] = '\0';
        }
    }*/

    BigInt::BigInt(int integer)
    {
        if(integer<0)
        {
            sign = 0;
            char tmp[12];
            sprintf(tmp, "%d", integer);
            bigInteger = new char[strlen(tmp)];
            int n;
            for(n = 0; n<strlen(tmp)-1; n++)
            {
                bigInteger[n] = tmp[n+1];
            }
            bigInteger[n] = '\0';
            length = strlen(tmp)-1;
        }
        else
        {
            sign = 1;
            char tmp[11];
            sprintf(tmp, "%d", integer);
            bigInteger = new char[strlen(tmp)+1];
            int n;
            for(n = 0; n<strlen(tmp); n++)
            {
                bigInteger[n] = tmp[n];
            }
            bigInteger[n] = '\0';
            length = strlen(tmp);
        }
    }

    BigInt::BigInt(const BigInt &iniObj)
    {
        sign = iniObj.sign;
        length = iniObj.length;
        int n;
        bigInteger = new char[iniObj.length+1];
        for(n = 0;n<iniObj.length;n++)
        {
            bigInteger[n] = iniObj.bigInteger[n];
        }
        bigInteger[n] = '\0';
    }

    BigInt::BigInt(string stringOfNumber)
    {
        if(stringOfNumber.c_str()[0]=='-')
        {
            sign = 0;
            length = strlen(stringOfNumber.c_str())-1;
            bigInteger = new char[length+1];
            int n = 0;
            for(;n<length;n++)
            {
                bigInteger[n] = stringOfNumber.c_str()[n+1];
            }
            bigInteger[n] = '\0';
        }
        else
        {
            sign = 1;
            length = strlen(stringOfNumber.c_str());
            bigInteger = new char[length+1];
            int n = 0;
            for(;n<length;n++)
            {
                bigInteger[n] = stringOfNumber.c_str()[n];
            }
            bigInteger[n] = '\0';
        }
    }

    BigInt::~BigInt()
    {
        delete [] bigInteger;
        bigInteger = NULL;
    }

    int BigInt::getLength()
    {
        return length;
    }

    char* BigInt::getBigint()
    {
        return bigInteger;
    }

    int BigInt::getSign()
    {
        return sign;
    }

    /*int& Rational::operator [](int a)
    {
        if(a==0) return numerator;
        else if(a==1) return denominator;
        else{
            cout << "Illegal index." << endl;
            exit(1);
        }
    }*/

    bool operator !=(const BigInt& a, const BigInt& b)
    {
        BigInt cpy_a(a), cpy_b(b);
        if(cpy_a.getSign()==0||cpy_b.getSign()==1)
        {
            if(cpy_a.getSign()==cpy_b.getSign())
            {
                if(cpy_a.getLength()==cpy_b.getLength())
                {
                    if(strcmp(cpy_a.getBigint(), cpy_b.getBigint())!=0) return true;
                    else return false;
                }
                else return true;
            }
            else return true;
        }
        if(cpy_a.getLength()==cpy_b.getLength())
        {
            if(strcmp(cpy_a.getBigint(), cpy_b.getBigint())!=0) return true;
            else return false;
        }
        else return true;
    }

    bool operator ==(const BigInt& a, const BigInt& b)
    {
        BigInt cpy_a(a), cpy_b(b);
        if(cpy_a.getSign()==0||cpy_b.getSign()==0)
        {
            if(cpy_a.getSign()==cpy_b.getSign())
            {
                if(cpy_a.getLength()==cpy_b.getLength())
                {
                    if(strcmp(cpy_a.getBigint(), cpy_b.getBigint())==0) return true;
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        if((cpy_a.getLength()==cpy_b.getLength())&&(strcmp(cpy_a.getBigint(), cpy_b.getBigint())==0)) return true;
        else return false;
    }

    bool operator >=(const BigInt& a, const BigInt& b)
    {
        BigInt cpy_a(a), cpy_b(b);
        if(cpy_a.getSign()==0||cpy_b.getSign()==0)
        {
            if(cpy_a.getSign()==1&&cpy_b.getSign()==0) return true;
            else if(cpy_a.getSign()==0&&cpy_b.getSign()==1) return false;
            else
            {
                if(cpy_a.getLength()<cpy_b.getLength()) return true;
                else if(cpy_a.getLength()==cpy_b.getLength())
                {
                    if(strcmp(cpy_a.getBigint(), cpy_b.getBigint())<=0) return true;
                    else return false;
                }
                else return false;
            }
        }
        if(cpy_a.getLength()>cpy_b.getLength()) return true;
        else if((cpy_a.getLength()==cpy_b.getLength())&&(strcmp(cpy_a.getBigint(), cpy_b.getBigint())>=0)) return true;
        else return false;
    }

    bool operator >(const BigInt& a, const BigInt& b)
    {
        BigInt cpy_a(a), cpy_b(b);
        if(cpy_a.getSign()==0||cpy_b.getSign()==0)
        {
            if(cpy_a.getSign()==1&&cpy_b.getSign()==0) return true;
            else if(cpy_a.getSign()==0&&cpy_b.getSign()==1) return false;
            else
            {
                if(cpy_a.getLength()<cpy_b.getLength()) return true;
                else if(cpy_a.getLength()==cpy_b.getLength())
                {
                    if(strcmp(cpy_a.getBigint(), cpy_b.getBigint())<0) return true;
                    else return false;
                }
                else return false;
            }
        }
        if(cpy_a.getLength()>cpy_b.getLength()) return true;
        else if((cpy_a.getLength()==cpy_b.getLength())&&(strcmp(cpy_a.getBigint(), cpy_b.getBigint())>0)) return true;
        else return false;
    }

    bool operator <=(const BigInt& a, const BigInt& b)
    {
        BigInt cpy_a(a), cpy_b(b);
        if(cpy_a.getSign()==0||cpy_b.getSign()==0)
        {
            if(cpy_a.getSign()==1&&cpy_b.getSign()==0) return false;
            else if(cpy_a.getSign()==0&&cpy_b.getSign()==1) return true;
            else
            {
                if(cpy_a.getLength()<cpy_b.getLength()) return false;
                else if(cpy_a.getLength()==cpy_b.getLength())
                {
                    if(strcmp(cpy_a.getBigint(), cpy_b.getBigint())>=0) return true;
                    else return false;
                }
                else return true;
            }
        }
        if(cpy_a.getLength()<cpy_b.getLength()) return true;
        else if((cpy_a.getLength()==cpy_b.getLength())&&(strcmp(cpy_a.getBigint(), cpy_b.getBigint())<=0)) return true;
        else return false;
    }
    bool operator <(const BigInt& a, const BigInt& b)
    {
        BigInt cpy_a(a), cpy_b(b);
        if(cpy_a.getSign()==0||cpy_b.getSign()==0)
        {
            if(cpy_a.getSign()==1&&cpy_b.getSign()==0) return false;
            else if(cpy_a.getSign()==0&&cpy_b.getSign()==1) return true;
            else
            {
                if(cpy_a.getLength()<cpy_b.getLength()) return false;
                else if(cpy_a.getLength()==cpy_b.getLength())
                {
                    if(strcmp(cpy_a.getBigint(), cpy_b.getBigint())>0) return true;
                    else return false;
                }
                else return true;
            }
        }
        if(cpy_a.getLength()<cpy_b.getLength()) return true;
        else if((cpy_a.getLength()==cpy_b.getLength())&&(strcmp(cpy_a.getBigint(), cpy_b.getBigint())<0)) return true;
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
            sign = rtSide.sign;
            return *this;
        }
    }

    const BigInt operator %(const BigInt &a, const BigInt &b)
    {
        BigInt zero(0);
        if(b==zero)
        {
            cout << "is wrong!\n";
            exit(0);
        }
        BigInt q = a/b, r;
        r = a-(q*b);
        return BigInt(r);
    }

    const BigInt operator /(const BigInt &a, const BigInt &b)
    {
        BigInt zero(0);
        if(b==zero)
        {
            cout << "is wrong!\n";
            exit(0);
        }
        BigInt result(0);
        int j, bit, ide = 0;
        BigInt cpy_a(a), cpy_b(b);
        if(cpy_a.getSign()==0&&cpy_b.getSign()==1)
        {
            cpy_a.sign = 1;
            ide = 1;
        }
        else if(cpy_a.getSign()==1&&cpy_b.getSign()==0)
        {
            cpy_b.sign = 1;
            ide = 2;
        }
        else if(cpy_a.getSign()==0&&cpy_b.getSign()==0)
        {
            cpy_a.sign = 1;
            cpy_b.sign = 1;
            ide = 3;
        }
        while(cpy_a>zero)
        {
            if(cpy_a<cpy_b)
            {
                if(ide==1||ide==2)
                {
                    char negResult[result.getLength()+2];
                    negResult[0] = '-';
                    for(j = 0; j<result.getLength(); j++)
                    {
                        negResult[j+1] = result.getBigint()[j];
                    }
                    negResult[j+1] = '\0';
                    if(negResult[0]=='-'&&negResult[1]=='0') return BigInt(0);
                    string finalResult = negResult;
                    return BigInt(finalResult);
                }
                return BigInt(result);
            }
            char tmp_a[cpy_b.getLength()+2];
            int i;
            memset(tmp_a, '0', cpy_b.getLength()+1);
            tmp_a[cpy_b.getLength()+1] = '\0';
            for(i = 0;i<cpy_b.getLength();i++)
            {
                tmp_a[1+i] = cpy_a.getBigint()[i];
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
            if(strcmp(tmp2_a, cpy_b.getBigint())<0)
            {
                for(i = 0;i<=cpy_b.getLength();i++)
                {
                    tmp_a[i] = cpy_a.getBigint()[i];
                    bit = i;
                }
                BigInt tmpOfA(tmp_a);
                for(i = 9;i>=0;i--)
                {
                    BigInt tmpi(i), ixb(tmpi*cpy_b);
                    if(ixb<=tmpOfA)
                    {
                        int tmpbit;
                        bit = cpy_a.getLength()-bit-1;
                        tmpbit = bit;
                        BigInt pow10(1), q = tmpi*cpy_b, ten(10);
                        while(bit--)
                        {
                            pow10 = pow10*ten;
                        }
                        cpy_a = cpy_a-(q*pow10);
                        result = result + (pow10*tmpi);
                        break;
                    }
                }
            }
            else
            {
                BigInt tmpOfA(tmp2_a);
                for(i = 9;i>=0;i--)
                {
                    BigInt tmpi(i), ixb(tmpi*cpy_b);
                    if(ixb<=tmpOfA)
                    {
                        int tmpbit;
                        bit = cpy_a.getLength()-bit-1;
                        tmpbit = bit;
                        BigInt pow10(1), q = tmpi*cpy_b, ten(10);
                        while(bit--)
                        {
                            pow10 = pow10*ten;
                        }
                        cpy_a = cpy_a-(q*pow10);
                        result = result + (pow10*tmpi);
                        break;
                    }
                }
            }
        }
        if(ide==1||ide==2)
        {
            char negResult[result.getLength()+2];
            negResult[0] = '-';
            for(j = 0; j<result.getLength(); j++)
            {
                negResult[j+1] = result.getBigint()[j];
            }
            negResult[j+1] = '\0';
            if(negResult[0]=='-'&&negResult[1]=='0') return BigInt(0);
            string finalResult = negResult;
            return BigInt(finalResult);
        }
        return BigInt(result);
    }

    const BigInt operator *(const BigInt &a, const BigInt &b)
    {
        BigInt cpy_a(a), cpy_b(b);
        int *multi = new int[cpy_a.getLength()+cpy_b.getLength()];
        int i, j, k, tempk, l, ide = 0;
        if(cpy_a.getSign()==0&&cpy_b.getSign()==1)
        {
            cpy_a.sign = 1;
            ide = 1;
        }
        else if(cpy_a.getSign()==1&&cpy_b.getSign()==0)
        {
            cpy_b.sign = 1;
            ide = 2;
        }
        else if(cpy_a.getSign()==0&&cpy_b.getSign()==0)
        {
            cpy_a.sign = 1;
            cpy_b.sign = 1;
            ide = 3;
        }
        for(j = 0;j<cpy_a.getLength()+cpy_b.getLength();j++)
        {
            multi[j] = 0;
        }
        int *cpya = new int [cpy_a.getLength()];
        for(j = 0;j<cpy_a.getLength();j++)
        {
            cpya[j] = cpy_a.getBigint()[j]-'0';
        }
        int *cpyb = new int [cpy_b.getLength()];
        for(j = 0;j<cpy_b.getLength();j++)
        {
            cpyb[j] = cpy_b.getBigint()[j]-'0';
        }
        k = cpy_a.getLength()+cpy_b.getLength()-1;
        tempk = k;
        for(i = cpy_b.getLength()-1;i>=0;i--)
        {
            for(j = cpy_a.getLength()-1;j>=0;j--, tempk--)
            {
                multi[tempk] = cpya[j]*cpyb[i]+multi[tempk];
            }
            for(l = cpy_a.getLength()+cpy_b.getLength()-1;l>0;l--)
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
        if(countOfZero==cpy_a.getLength()+cpy_b.getLength())
        {
            return BigInt(0);
        }
        char multiNumber[cpy_a.getLength()+cpy_b.getLength()-countOfZero];
        for(n = countOfZero;n<cpy_a.getLength()+cpy_b.getLength();n++)
        {
            multiNumber[m++] = multi[n]+'0';
        }
        delete [] multi;
        delete [] cpya;
        delete [] cpyb;
        multi = NULL;
        cpya = NULL;
        cpyb = NULL;
        multiNumber[m] = '\0';
        if(ide==1||ide==2)
        {
            char negMulti[strlen(multiNumber)+2];
            negMulti[0]='-';
            for(j = 0; j<strlen(multiNumber); j++)
            {
                negMulti[j+1] = multiNumber[j];
            }
            negMulti[j+1] = '\0';
            if(multiNumber[0]=='-'&&multiNumber[1]=='0') return BigInt(0);
            string returnNumber = negMulti;
            return BigInt(returnNumber);
        }
        string returnNumber = multiNumber;
        return BigInt(returnNumber);
    }

    const BigInt operator +(const BigInt &a, const BigInt &b)
    {
        BigInt cpy_a(a), cpy_b(b);
        int m, n, j, maxLength = (cpy_a.getLength()>=cpy_b.getLength()?cpy_a.getLength():cpy_b.getLength());
        if(cpy_a.getSign()==0&&cpy_b.getSign()==1)
        {
            cpy_a.sign = 1;
            return BigInt(cpy_b-cpy_a);
        }
        else if(cpy_a.getSign()==1&&cpy_b.getSign()==0)
        {
            cpy_b.sign = 1;
            return BigInt(cpy_a-cpy_b);
        }
        else if(cpy_a.getSign()==0&&cpy_b.getSign()==0)
        {
            cpy_a.sign = 1;
            cpy_b.sign = 1;
            return BigInt(-(cpy_a+cpy_b));
        }
        char *cpyNumber, *addNumber;
        addNumber = new char[maxLength+2];
        memset(addNumber, '0', maxLength+1);
        addNumber[maxLength+1] = '\0';
        cpyNumber = new char[maxLength+1];
        if(maxLength==cpy_a.getLength())
        {
            n = strlen(cpy_b.getBigint())-1;
            memset(cpyNumber, '0', maxLength);
            cpyNumber[maxLength] = '\0';
            for(m=maxLength-1;m>=cpy_a.getLength()-cpy_b.getLength();m--)
            {
                cpyNumber[m] = cpy_b.getBigint()[n--];
            }
            n=maxLength;
            for(m=maxLength-1;m>=0;m--)
            {
                if(((cpy_a.getBigint()[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))>=0&&((cpy_a.getBigint()[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))<=9)
                {
                    addNumber[n--] = ((cpy_a.getBigint()[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))+'0';
                }
                else
                {
                    addNumber[n--] = ((cpy_a.getBigint()[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))-10+'0';
                    addNumber[n] = '1';
                }
            }
        }
        else
        {
            n = strlen(cpy_a.getBigint())-1;
            memset(cpyNumber, '0', maxLength);
            cpyNumber[maxLength] = '\0';
            for(m=maxLength-1;m>=cpy_b.getLength()-cpy_a.getLength();m--)
            {
                cpyNumber[m] = cpy_a.getBigint()[n--];
            }
            n=maxLength;
            for(m=maxLength-1;m>=0;m--)
            {
                if(((cpy_b.getBigint()[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))>=0&&((cpy_b.getBigint()[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))<=9)
                {
                    addNumber[n--] = ((cpy_b.getBigint()[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))+'0';
                }
                else
                {
                    addNumber[n--] = ((cpy_b.getBigint()[m]-'0')+(cpyNumber[m]-'0')+(addNumber[n]-'0'))-10+'0';
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
        delete [] addNumber;
        delete [] cpyNumber;
        addNumber = NULL;
        cpyNumber = NULL;
        adderNumber[m] = '\0';
        string returnNumber = adderNumber;
        return BigInt(returnNumber);
    }

    const BigInt operator -(const BigInt &a, const BigInt &b)
    {
        BigInt cpy_a(a), cpy_b(b);
        int ide, m, n, j, maxLength = (cpy_a.getLength()>=cpy_b.getLength()?cpy_a.getLength():cpy_b.getLength());
        if(cpy_a.getSign()==0&&cpy_b.getSign()==1)
        {
            cpy_a.sign = 1;
            return BigInt(-(cpy_a+cpy_b));
        }
        else if(cpy_a.getSign()==1&&cpy_b.getSign()==0)
        {
            cpy_b.sign = 1;
            return BigInt(cpy_a+cpy_b);
        }
        else if(cpy_a.getSign()==0&&cpy_b.getSign()==0)
        {
            cpy_a.sign = 1;
            cpy_b.sign = 1;
            return BigInt(cpy_b-cpy_a);
        }
        char *cpyNumber, *minusNumber;
        minusNumber = new char[maxLength+1];
        memset(minusNumber, '0', maxLength);
        minusNumber[maxLength] = '\0';
        cpyNumber = new char[maxLength+1];
        if(cpy_a.getLength()==cpy_b.getLength()){
            ide = strcmp(cpy_a.getBigint(), cpy_b.getBigint());
        }
        else if(maxLength==cpy_a.getLength()){
            ide = 1;
        }
        else{
            ide = -1;
        }
        if(ide!=-1)
        {
            n = strlen(cpy_b.getBigint())-1;
            memset(cpyNumber, '0', maxLength);
            cpyNumber[maxLength] = '\0';
            for(m=maxLength-1;m>=cpy_a.getLength()-cpy_b.getLength();m--)
            {
                cpyNumber[m] = cpy_b.getBigint()[n--];
            }
            n=maxLength-1;
            for(m=maxLength-1;m>=0;m--)
            {
                if(((cpy_a.getBigint()[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))>=0&&((cpy_a.getBigint()[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))<=9)
                {
                    minusNumber[n--] = ((cpy_a.getBigint()[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))+'0';
                }
                else
                {
                    minusNumber[n--] = ((cpy_a.getBigint()[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))+10+'0';
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
            delete [] minusNumber;
            delete [] cpyNumber;
            minusNumber = NULL;
            cpyNumber = NULL;
            string returnNumber = minuserNumber;
            return BigInt(returnNumber);
        }
        else
        {
            n = strlen(cpy_a.getBigint())-1;
            memset(cpyNumber, '0', maxLength);
            cpyNumber[maxLength] = '\0';
            for(m=maxLength-1;m>=cpy_b.getLength()-cpy_a.getLength();m--)
            {
                cpyNumber[m] = cpy_a.getBigint()[n--];
            }
            n=maxLength-1;
            for(m=maxLength-1;m>=0;m--)
            {
                if(((cpy_b.getBigint()[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))>=0&&((cpy_b.getBigint()[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))<=9)
                {
                    minusNumber[n--] = ((cpy_b.getBigint()[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))+'0';
                }
                else
                {
                    minusNumber[n--] = ((cpy_b.getBigint()[m]-'0')-(cpyNumber[m]-'0')-(minusNumber[n]-'0'))+10+'0';
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
            delete [] minusNumber;
            delete [] cpyNumber;
            minusNumber = NULL;
            cpyNumber = NULL;
            string returnNumber = minuserNumber;
            return BigInt(returnNumber);
        }
    }

    const BigInt operator -(const BigInt &a)
    {
        BigInt cpy_a(a);
        if(cpy_a.sign==0)
        {
            cpy_a.sign = 1;
        }
        else
        {
            cpy_a.sign = 0;
        }
        return BigInt(cpy_a);
    }

    const BigInt factorial(string factor)
    {
        int l = strlen(factor.c_str());
        char cpytmp[l], cpy[l-1];
        strcpy(cpytmp, factor.c_str());
        int i = 0, j = 1;
        for(;i<l-1;i++)
        {
            cpy[i] = cpytmp[i];
        }
        i = atoi(cpy);
        BigInt tmp(1), result(1);
        for(;j<=i;j++)
        {
            BigInt tmp(j);
            result = result * tmp;
        }
        return BigInt(result);
    }
}
