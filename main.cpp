/* 江宗祐 403410023 資工二 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int COL(10);

void generateMatrix(int matrixA[][COL],int matrixB[][COL]);
//pre:A&B are 2-D array.
//pos:generating integers from 0 to 255 to A&B.

void multiMatrix(int matrixA[][COL],int matrixB[][COL]);
//pre:A&B are 2-D array.
//pos:multiply A by B and put the result in A.

int multy(int matrixA[][COL],int matrixB[][COL],int row,int col);
//pre:A&B are 2-D array. row&col are the row&column of 2-D array for multiplication.
//pos:return the result of multiplication.

void outputMatrix(const int matrix[][COL]);
//pre:matrix is a 2-D array.
//pos:print out the 2-D array you put in.

void medianFilter(int matrixA[][COL],int matrixB[][COL]);
//pre:A&B are 2-D array.
//pos:filter A by find out the median and put the result in B.

int med(int matrixA[][COL],const int row,const int col);
//pre:A is a 2-D array. row is row in A. col is column in A.
//pos:find out the median from an array after sorting and return it.

int cmp(const void *a,const void *b);
//pre:*a&*b are the address of a&b.
//pos:return the value a-b.

int main()
{
    int A[10][10],B[10][10],row,col;
    generateMatrix(A,B);
    cout<<"A:"<<endl;
    outputMatrix(A);
    cout<<"B:"<<endl;
    outputMatrix(B);
    multiMatrix(A,B);
    cout<<"A by multiplication:"<<endl;
    outputMatrix(A);
    medianFilter(A,B);
    cout<<"B by median_filter:"<<endl;
    outputMatrix(B);
    return 0;
}

void generateMatrix(int matrixA[][COL],int matrixB[][COL])
{
    int m,n;
    srand((unsigned)time(NULL));
    for(m=0;m<10;m++){
        for(n=0;n<COL;n++){
            matrixA[m][n]=rand()%256;
            matrixB[m][n]=rand()%256;
        }
    }
}

void multiMatrix(int matrixA[][COL],int matrixB[][COL])
{
    int matrixC[10][COL];
    int m,n;
    for(m=0;m<10;m++){
        for(n=0;n<COL;n++){
            matrixC[m][n]=multy(matrixA,matrixB,m,n);
        }
    }
    for(m=0;m<10;m++){
        for(n=0;n<10;n++){
            matrixA[m][n]=matrixC[m][n];
        }
    }
}

int multy(int matrixA[][COL],int matrixB[][COL],int row,int col)
{
    int sum(0),n;
    for(n=0;n<COL;n++){
        sum+=(matrixA[row][n]*matrixB[n][col]);
    }
    return sum;
}

void outputMatrix(const int matrix[][COL])
{
    int m,n;
    for(m=0;m<10;m++){
        for(n=0;n<COL;n++){
            cout<<matrix[m][n]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void medianFilter(int matrixA[][COL],int matrixB[][COL])
{
    int m,n;
    for(m=0;m<10;m++){
        for(n=0;n<10;n++){
            matrixB[m][n]=med(matrixA,m,n);
        }
    }
}

int med(int matrixA[][COL],const int row,const int col)
{
    int m,n,C[9],cou(0);
    if(row==0){
        if(col==0){
            for(m=row;m<=row+1;m++){
                for(n=col;n<=col+1;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
        else if(col==9){
            for(m=row;m<=row+1;m++){
                for(n=col-1;n<=col;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
        else{
            for(m=row;m<=row+1;m++){
                for(n=col-1;n<=col+1;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
    }
    else if(row==9){
        if(col==0){
            for(m=row-1;m<=row;m++){
                for(n=col;n<=col+1;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
        else if(col==9){
            for(m=row-1;m<=row;m++){
                for(n=col-1;n<=col;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
        else{
            for(m=row-1;m<=row;m++){
                for(n=col-1;n<=col+1;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
    }
    else{
        if(col==0){
            for(m=row-1;m<=row+1;m++){
                for(n=col;n<=col+1;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
        else if(col==9){
            for(m=row-1;m<=row+1;m++){
                for(n=col-1;n<=col;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
        else{
            for(m=row-1;m<=row+1;m++){
                for(n=col-1;n<=col+1;n++){
                    C[cou++]=matrixA[m][n];
                }
            }
        }
    }
    for(m=0;m<cou;m++){
        qsort((void*)C,cou,sizeof(int),cmp);
    }
    if(cou%2!=0){
        return C[cou/2];
    }
    else{
        return (C[cou/2]+C[cou/2-1])/2;
    }
}

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
