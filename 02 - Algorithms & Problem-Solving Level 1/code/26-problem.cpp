#include <iostream>
using namespace std;

// problem 26 :
/*
write a program to print numbers from 1 to n
*/

int getNumber()
{
    int number = 0;
    cout << "enter a number  :";
    cin >> number;

    return number;
}

void isValid(int number)
{
    if (cin.fail())
        throw runtime_error("invalid number :");
    if (number < 0 || number > 50000)
        throw string("you should enter a number between 0 and  50000");
}

void printToN(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
    }
}

int main()
{

    try
    {
        int number = getNumber();
        isValid(number);
        printToN(number);
    }
    catch (runtime_error e)
    {
        cerr << "Error " << e.what() << endl;
    }
    catch (string msg)
    {
        cout << msg << endl;
    }

    return 0;
}