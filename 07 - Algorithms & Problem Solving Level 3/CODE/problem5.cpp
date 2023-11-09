/*
problem 5 :
write a program to fill a 3*3 matrix with random numbers :
then sum each col in another array and print them:
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

int getSumOfCol(int arr[][3], int c, int l)
{
    int sum = 0;
    for (int i = 0; i < l; i++)
        sum += arr[i][c];
    return sum;
}

int *FillArrayWithSumOfMatrixCol(int matrix[3][3], int l, int c)
{

    int *sumArr = new int[3];
    for (int i = 0; i < l; i++)
    {
        sumArr[i] = getSumOfCol(matrix, i, l);
    }

    return sumArr;
}

void printMatrixSums(int arr[], int size)
{
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Col " << i << " Sum = " << arr[i] << "\n";
    }
    cout << "\n";
}
int main()
{
    srand(time(NULL));

    int matrix[3][3];

    cout << " fill the matrix with random numbers : \n";

    FillMatrixWithRandomNumber(matrix, 3, 3, 0, 100);

    printMatrix(matrix, 3, 3);

    cout << "the following  are the sum of each col in the matrix \n";

    int *arr = new int[3];
    arr = FillArrayWithSumOfMatrixCol(matrix, 3, 3);
    printMatrixSums(arr, 3);

    return 0;
}
