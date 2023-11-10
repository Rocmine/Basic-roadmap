/*
problem 19 :
write a program to print the minumum and maximum numbers in matrix
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

void setMinAndMaxNumbersInMatrix(int matrix[3][3], int l, int c, int &min, int &max)
{

    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] > max)
                max = matrix[i][j];
            if (matrix[i][j] < min)
                min = matrix[i][j];
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
    int matrix1[3][3];

    cout << "matrix 1:";
    FillMatrixWithRandomNumber(matrix1, 3, 3, 0, 100);
    printMatrix(matrix1, 3, 3);

    int min, max;

    setMinAndMaxNumbersInMatrix(matrix1, 3, 3, min, max);

    cout << "the minimum Number is :" << min << endl;
    cout << "the maximum Number is :" << max << endl;
    return 0;
}