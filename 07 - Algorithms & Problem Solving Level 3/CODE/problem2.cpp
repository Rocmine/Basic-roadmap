/*
problem 2 :
write a program to fill a 3*3 matrix with random numbers :
then print each row sum 
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
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

void PrintSumOfMatrixRows(int matrix[3][3], int l, int c)
{

    cout << "\n";
    int sumOfRow = 0;
    for (int i = 0; i < l; i++)
    {
        sumOfRow = 0;
        for (int j = 0; j < c; j++)
        {
            sumOfRow += matrix[i][j];
        }

        cout << "Row " << i << " Sum = " << sumOfRow << "\n";
    }
}

int main()
{
    srand(time(NULL));

    int matrix[3][3];

    cout << " fill the matrix with random numbers : \n";

    FillMatrixWithRandomNumber(matrix, 3, 3, 0, 100);

    printMatrix(matrix, 3, 3);

    cout << "the following  are the sum of each row in the matrix \n";
    PrintSumOfMatrixRows(matrix, 3, 3);

    return 0;
}
