/*
problem 22 :
write a program to print Fibonacci Series of 10 : (using recursion )
*/

#include <iostream>
#include "myLib.h"
#include <ctime>
#include <iomanip>
#include <ctime>
using namespace std;

void printFibonacciSeriesOf10(int number = 0, int previous1 = 1, int previous2 = 1)
{
    // base case :
    if (number == 10)
        return;

    // recursion case :
    if (number == 0 || number == 1)
    {
        cout << previous1<<" ";
        printFibonacciSeriesOf10(++number, previous2, previous2);
    }

    else
    {
        cout << previous1 + previous2<<" ";
        printFibonacciSeriesOf10(++number, previous2, previous1 + previous2);
    }
}

int main()
{

    int arr[10];

    cout << "Fibonacci Series of 10 :\n";
    printFibonacciSeriesOf10(); 
}
