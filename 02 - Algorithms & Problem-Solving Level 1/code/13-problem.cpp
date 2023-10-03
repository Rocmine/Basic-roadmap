

// problem 13:
/*
write a program to aks the user to enter 3 numbers :
.a
.b
.c
then print the max of them
*/
#include <iostream>
using namespace std;

int main()
{

    int num1 = 0, num2 = 0, num3 = 0;
    cout << "entre three numbers : ";
    cin >> num1 >> num2 >> num3;

    int max = num1;
    if (max < num2)
        max = num2;
    if (max < num3)
        max = num3;

    cout << "the max is " << max << endl;
    return 0;
}