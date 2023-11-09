/*
problem 6 :
write a program to fill a 3*3 matrix with ordered numbers :
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

int main()
{

    int matrix[3][3];

    cout << "the following is a 3*3  ordered matrix :\n";
    FillMatrixWithOrderedValues(matrix, 3, 3);

    printMatrix(matrix, 3, 3);

    return 0;
}
