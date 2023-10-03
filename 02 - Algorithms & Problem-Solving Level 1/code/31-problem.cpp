
// problem 31
/*
write a program to ask the user to enter :
number
then print the  , number^2 ,number^3 ,number^4
*/

#include <iostream>
#include <cmath>
using namespace std;

int getNumber()
{
    int number = 0;
    cout << "enter a number  :";
    cin >> number;

    return number;
}

void isValid()
{
    if (cin.fail())
        throw runtime_error("invalid number :");
}

void powPrinter(const int number)
{
    int a = number * number;
    int b = number * number * number;
    int c = number * number * number * number;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

int main()
{

    try
    {

        int number = getNumber();
        isValid();
        powPrinter(number);
    }
    catch (runtime_error e)
    {

        cout << "Error: " << e.what() << endl;
    }
}
