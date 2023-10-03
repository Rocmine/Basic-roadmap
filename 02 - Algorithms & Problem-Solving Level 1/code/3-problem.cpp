

/*
write a program to ask the user to enter a number ,then print 'ODD' if its odd , or 'EVEN' if its even
*/

#include <iostream>

using namespace std;

int main()
{

    int number = 0;

    try
    {
        cout << "enter a number :";
        cin >> number;

        if (cin.fail())
            throw runtime_error("invalid user input :");

        number % 2 == 0 ? cout << "even" << endl : cout << "odd" << endl;
    }
    catch (runtime_error e)
    {
        // clear flag errors :
        cin.clear();
        // clear the buffer:
        cin.ignore();
        cout << "Error"
             << " invalid user input " << endl;
    }

    return 0;
}