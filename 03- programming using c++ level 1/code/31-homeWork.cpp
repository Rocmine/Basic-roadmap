#include <iostream>
using namespace std;

int main()
{

    // int sum=0;
    // int Number;
    // for (int i = 0; i < 5; i++)
    // {

    //     cout << "enter a Number :";
    //     cin >> Number;

    //     if (Number > 50)
    //         continue;

    //     sum += Number;
    // }
    // cout << "the sum is :" << sum << endl;

    try
    {
        int Number = 0;
        cout << "enter a number : ";
        cin >> Number;
        cin.ignore();
        if (cin.fail())
            throw runtime_error("invalid Number ");

        cout << "Valid Number :";
    }
    catch (runtime_error e)
    {

        cout << "Error : " << e.what() << endl;
    }

    return 0;
}