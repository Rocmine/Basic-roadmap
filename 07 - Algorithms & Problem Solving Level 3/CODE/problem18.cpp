/*
problem 18 :
write a program to print the intersected numbers in two given matrices


*/

#include <iostream>
#include "myLib.h"
#include <ctime>
#include <iomanip>
#include <ctime>
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

enum enIsExist
{
    no,
    yes
};

enIsExist checkIfNumberIsExistInMatrix(int matrix[3][3], int l, int c, int searchedNumber)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == searchedNumber)
                return enIsExist::yes;
        }
    }

    return enIsExist::no;
}

void printIntersectedValuesBetween2Matrices(int matrix1[3][3], int matrix2[3][3], int l, int c)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (checkIfNumberIsExistInMatrix(matrix2, l, c, matrix1[i][j]) == enIsExist::yes)
                cout << matrix1[i][j] << "  ";
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

int main()
{
    srand(time(NULL));
    int matrix1[3][3], matrix2[3][3];

    cout << "matrix 1:";
    FillMatrixWithRandomNumber(matrix1, 3, 3, 0, 100);
    printMatrix(matrix1, 3, 3);

    cout << "matrix 2:";
    FillMatrixWithRandomNumber(matrix2, 3, 3, 0, 100);
    printMatrix(matrix2, 3, 3);

    cout << "Intersected Numbers are :";
    printIntersectedValuesBetween2Matrices(matrix1, matrix2, 3, 3);

    return 0;
}