// problem 10:
/*
write a program to ask the user to entre
.mark 1 ,mark 2 ,mark 3
then print the  average of entered marks
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float num1 = 0, num2 = 0, num3 = 0;
    cout << "enter three number : ";
    cin >> num1 >> num2 >> num3;
    cout << fixed << setprecision(2) << ((num1 + num2 + num3) / 3) << endl;

    return 0;
}