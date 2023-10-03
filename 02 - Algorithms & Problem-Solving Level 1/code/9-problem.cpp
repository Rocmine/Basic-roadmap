// problem 9:
/*
write a program to ask the user to entre
.number 1 ,number 2 ,number 3
then print the sum of entered numbers
*/
#include <iostream>
using namespace std;

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;
    cout << "enter three number : ";
    cin >> num1 >> num2 >> num3;
    cout << num1 + num2 + num3<< endl;

    return 0;
}