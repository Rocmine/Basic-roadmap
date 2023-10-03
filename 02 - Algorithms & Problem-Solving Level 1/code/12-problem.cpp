#include <iostream>
using namespace std;

// problem 12 :
/*
write a program to ask the use to entre
.number 1
.number 2
then print the max number :
*/
int main()
{
    int num1, num2;
    cout << "entre tow numbers :";
    cin >> num1 >> num2;

    num1 > num2 ? cout << num1 : cout << num2;

    return 0;
}