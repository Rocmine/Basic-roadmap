/*
problem 8 :
write a program to fill two 3*3  matrix with random numbers
and then multiply them into a 3rd matrix and print it .
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

void SetMultiplyOfTwoMatrix(int matrix1[3][3], int matrix2[3][3], int resultMatrix[3][3], int l, int c)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {

            resultMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}
int main()
{
    srand(time(NULL));

    int matrix1[3][3], matrix2[3][3], resultMatrix[3][3];

    printIntersectedValuesBetween2Matrices(matrix1, 3, 3, 0, 9);
    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);

    printIntersectedValuesBetween2Matrices(matrix2, 3, 3, 0, 9);
    cout << "matrix 2:";
    printMatrix(matrix2, 3, 3);

    SetMultiplyOfTwoMatrix(matrix1, matrix2, resultMatrix, 3, 3);
    cout << "Result:";
    printMatrix(resultMatrix, 3, 3);

    return 0;
}
