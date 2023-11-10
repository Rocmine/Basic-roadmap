/*
problem 20 :
write a program to check  it the matrix is Palindrome or not
*/

#include <iostream>
#include "myLib.h"
#include <ctime>
#include <iomanip>
#include <ctime>
using namespace std;

enum enIsPalindrome
{
    no,
    yes
};

enIsPalindrome checkIfMatrixIsPalindrome(int matrix[3][3], int l, int c)
{

    for (int i = 0; i < l; i++)
    {

        for (int jLeft = 0, jRight = c - 1; jLeft < c / 2; jLeft++, jRight--)
        {

            if (matrix[i][jLeft] != matrix[i][jRight])
                return enIsPalindrome::no;
        }
    }

    return enIsPalindrome::yes;
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
    int matrix1[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}}, matrix2[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 8}};

    cout << "matrix 1:";
    printMatrix(matrix1, 3, 3);

    cout << (checkIfMatrixIsPalindrome(matrix1, 3, 3) == enIsPalindrome::yes ? "Yes : Matrix is Palindrome" : "No: Matrix is not Palindrome") << endl;

    cout << "matrix 2:";
    printMatrix(matrix2, 3, 3);

    cout << (checkIfMatrixIsPalindrome(matrix2, 3, 3) == enIsPalindrome::yes ? "Yes : Matrix is Palindrome" : "No: Matrix is not Palindrome") << endl;

    return 0;
}
