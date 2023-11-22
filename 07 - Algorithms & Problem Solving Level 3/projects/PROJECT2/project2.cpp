#include <iostream>
using namespace std;

int readInteger()
{
    int num = 0;
    cout << "enter a number : ";

    cin >> num;

    if (cin.fail())
        throw string("error invalid input : ");
    cout << "hello ";
    return num;
}

int main()
{
    try
    {
        readInteger();
        cout << 'H';
    }
    catch (const string& e)
    {
        cerr << "Error " << e << endl;
    }

    return 0;
}
