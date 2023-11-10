/*
problem 16 :
write a program to check if the matrix is Sparce or not

sparse : matrix where the  number of 0 more than other numbers

------------
 x 0 0
 0 x 0
 0 0 x
-----------
*/

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

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

enum enIsSparse
{
    no,
    yes
};
enIsSparse checkIfMatrixIsSparseOrNot(int matrix[3][3], int l, int c)
{

    int FrequencyOfOtherNumbers = 0;
    int FrequencyOfZero = countFrequencyOfNumberInMatrix(matrix, 3, 3, 0);

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] != 0)
                FrequencyOfOtherNumbers++;
        }
    }

    return FrequencyOfZero >= FrequencyOfOtherNumbers ? enIsSparse::yes : enIsSparse::no;
}
#include <iostream>
#include "myLib.h"
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{

    int matrix1[3][3] = {{0, 0, 12}, {0, 0, 1}, {0, 0, 9}};
    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);

    cout << (checkIfMatrixIsSparseOrNot(matrix1, 3, 3) == enIsSparse::yes ? "Yes : It is Sparse " : "No : It's  not Sparse ") << endl;
}
