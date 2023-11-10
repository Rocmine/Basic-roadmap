/*
problem 21 :
write a program to print Fibonacci Series of 10 :
*/

#include <iostream>
#include "myLib.h"
#include <ctime>
#include <iomanip>
#include <ctime>
using namespace std;

void setFibonacciSeriesOf10(int arr[10])
{

    arr[0] = arr[1] = 1;
    for (int i = 2; i < 10; i++)
    {
        arr[i] = arr[i - 2] + arr[i - 1];
    }
}

void printArray(int arr[], const int size)
{
    cout << endl;

    for (int i = 0; i < size; i++) cout<< arr[i] << " ";

    cout << endl;
}
int main()
{

    int arr[10];

    setFibonacciSeriesOf10(arr);
    cout << "Fibonacci Series of 10 :";
    printArray(arr, 10);
}
