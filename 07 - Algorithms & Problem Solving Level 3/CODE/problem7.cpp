/*
problem 7 :
write a program to fill a 3*3 matrix with ordered numbers :
and print it , then transpose matrix and print it :
*/

#include <iostream>
#include "myLib.h"
#include <ctime>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedValues(int matrix[3][3], int l, int c)
{

    for (int i = 0; i < l; i++)
    {

        for (int j = 0; j < c; j++)
            matrix[i][j] = i * 3 + j + 1;
    }
}
void printMatrix(int matrix[3][3], int l, int c)
{

    cout << "\n";
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

void swap(int &a, int &b)
{

    int temp = a;
    a = b;
    b = temp;
}

void transposeMatrix(int matrix[3][3], int l, int c)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = i; j < c; j++)
        {

            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{

    int matrix[3][3];

    cout << "the following is a 3*3  ordered matrix :\n";
    FillMatrixWithOrderedValues(matrix, 3, 3);

    printMatrix(matrix, 3, 3);
    transposeMatrix(matrix, 3, 3);
    cout << "the following is the  transpose matrix :\n";
    printMatrix(matrix, 3, 3);
    return 0;
}
