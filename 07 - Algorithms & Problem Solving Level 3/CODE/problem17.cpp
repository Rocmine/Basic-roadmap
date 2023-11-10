/*
problem 17 :
write a program to check if a given a number exists in matrix or not


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

int main()
{

    int matrix1[3][3];
    FillMatrixWithRandomNumber(matrix1, 3, 3, 0, 100);
    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);

    int searchedNumber = input::readIntegerNumber("enter the number to look for in matrix? ");
    cout << (checkIfNumberIsExistInMatrix(matrix1, 3, 3, searchedNumber) == enIsExist::yes ? "Yes : It is there " : "No : It's  not there ") << endl;

    return 0;
}