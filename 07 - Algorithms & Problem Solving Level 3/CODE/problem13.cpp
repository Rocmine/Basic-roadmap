/*
problem 13 :
write a program to check  if the matrix is identity or not  
------------
 1 0 0 
 0 1 0 
 0 0 1 
-----------
*/

#include <iostream>
#include "myLib.h"
#include <ctime>
#include <iomanip>
using namespace std;

int getRandomNumber(int min, int max)
{

    return rand() % max + min;
}

void printIntersectedValuesBetween2Matrices(int matrix[3][3], int l, int c, int minRandValue, int maxRandValue)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {

            matrix[i][j] = getRandomNumber(minRandValue, maxRandValue);
        }
    }
}

void printMatrix(int matrix[3][3], int l, int c)
{

    cout << "\n";
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {

            printf("%02d  ", matrix[i][j]);
        }
        cout << endl;
    }
    cout << "\n";
}

enum isScalar
{
    no,
    yes
};

isScalar checkIf2MatricesScalar(int matrix[3][3],int l, int c)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {

            if( (i==j &&  matrix[i][j] != 1) || (i!=j  && matrix[i][j]!=0) )
                return isScalar::no;
        }

    }
    
        return isScalar::yes;
}

int main()
{
    srand(time(NULL));

    int matrix1[3][3];

    printIntersectedValuesBetween2Matrices(matrix1, 3, 3, 0, 9);
    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);


 cout<<"matrices is "<<(checkIf2MatricesScalar(matrix1,3,3) == isScalar::yes ? "" :"not")<<" identity"<<endl; 
    return 0;
}

