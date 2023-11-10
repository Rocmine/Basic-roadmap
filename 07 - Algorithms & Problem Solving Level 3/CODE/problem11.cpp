/*
problem 11 :
write a program to compare to matrices and check if they are equal or not :

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

enum isEqual
{
    no,
    yes
};
int getSumOfMatrix(int matrix[3][3], int l, int c)
{

    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {

            sum += matrix[i][j];
        }
    }

    return sum;
}

isEqual checkIf2MatricesEqual(int matrix1[3][3], int matrix2[3][3], int l, int c)
{

    getSumOfMatrix(matrix1, 3, 3) == getSumOfMatrix(matrix2, 3, 3) ? isEqual::yes : isEqual::no;
}

int main()
{
    srand(time(NULL));

    int matrix1[3][3], matrix2[3][3];

    printIntersectedValuesBetween2Matrices(matrix1, 3, 3, 0, 9);
    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);

    printIntersectedValuesBetween2Matrices(matrix2, 3, 3, 0, 9);
    cout << "matrix 2:";
    printMatrix(matrix2, 3, 3);

    cout << " matrices are " << (checkIf2MatricesEqual(matrix1, matrix2, 3, 3) == isEqual::yes ? "" : "not") << " equal" << endl;
    return 0;
}
