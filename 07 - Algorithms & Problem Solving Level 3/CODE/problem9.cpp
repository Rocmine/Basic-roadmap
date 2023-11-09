/*
problem 9 :
write a program to fill two 3*3  matrix with random numbers
print it, then print the middle row and middle col .
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

void FillMatrixWithRandomNumber(int matrix[3][3], int l, int c, int minRandValue, int maxRandValue)
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

void printMiddleRow(int matrix[3][3], int l, int c)
{

    for (int i = 0; i < l; i++)
    {
        printf("%02d  ", matrix[l / 2][i]);
    }

    cout << endl;
}
void printMiddleColumn(int matrix[3][3], int l, int c)
{

    for (int j = 0; j < c; j++)
    {
        printf("%02d  ", matrix[j][l / 2]);
    }
    
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int matrix1[3][3];

    FillMatrixWithRandomNumber(matrix1, 3, 3, 0, 9);
    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);

    cout << "Middle Row of Matrix1 is:\n";
    printMiddleRow(matrix1, 3, 3);

    cout << "\nMiddle Col of Matrix1 is:\n";
    printMiddleColumn(matrix1, 3, 3);

    return 0;
}
