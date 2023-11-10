/*
problem 4 :
write a program to fill a 3*3 matrix with random numbers :
then print each col sum :
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
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

int getSumOfCol(int arr[][3], int c, int l)
{
    int sum = 0;
    for (int i = 0; i < l; i++)
        sum += arr[i][c];
    return sum;
}

void printSumOfMatrixColumns(int matrix[3][3], int l, int c)
{

    for (int cIndex = 0; cIndex < c; cIndex++)
    {
        cout << "Col " << cIndex + 1 << " Sum = " << getSumOfCol(matrix, cIndex, l) << "\n";
    }
}

int main()
{
    srand(time(NULL));

    int matrix[3][3];

    cout << " fill the matrix with random numbers : \n";

    printIntersectedValuesBetween2Matrices(matrix, 3, 3, 0, 100);

    printMatrix(matrix, 3, 3);

    cout << "the following  are the sum of each col in the matrix \n";

    printSumOfMatrixColumns(matrix, 3, 3);

    return 0;
}
