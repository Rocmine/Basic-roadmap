/*
problem 15 :
write a program to count  given number  in matrix
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

int countFrequencyOfNumberInMatrix(int matrix[3][3], int l, int c, int countedNumber)
{

    int countOfNumber = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == countedNumber)
                countOfNumber++;
        }
    }

    return countOfNumber;
}

int main()
{
    srand(time(NULL));

    int matrix1[3][3];

    printIntersectedValuesBetween2Matrices(matrix1, 3, 3, 0, 9);
    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);

    int countedNumber = input::readIntegerNumber("enter the number to count in matrix? ");

    cout << "Number " << countedNumber << " count in matrix is " << countFrequencyOfNumberInMatrix(matrix1, 3, 3, countedNumber) << endl;

    return 0;
}
