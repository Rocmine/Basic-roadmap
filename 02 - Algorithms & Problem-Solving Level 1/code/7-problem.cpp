/*
write a program to ask the user to enter
.number

*/
#include <iostream>
using namespace std;
int main()
{
    int number;

    try
    {
        cout << "ente a number : ";
        cin >> number;
        if (cin.fail())
            throw runtime_error("invalid number");
        cout << "half of " << number << " is " << number / 2 << endl;
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}