/*
problem 10 :
write a program to fill two 3*3  matrix with random numbers
then write a function to sum all numbers in this matrix and print it
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
int main()
{
    srand(time(NULL));

    int matrix1[3][3];

    printIntersectedValuesBetween2Matrices(matrix1, 3, 3, 0, 9);
    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);

    cout << "sum of the matrix is :" << getSumOfMatrix(matrix1, 3, 3) << endl;

    return 0;
}
