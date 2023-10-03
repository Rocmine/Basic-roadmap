#include <iostream>
using namespace std;

//  done 😁 26 27 28 29 30 32 37 46 50 :

int ReadIntNumberInRange(int From, int To)
{

    int Number = 0;
    do
    {
        cout << "Enter a Number  in Range from" << From << " to " << To << "\n";
        cin >> Number;
        system("cls");

    } while (Number < From || Number > To);
}
int main()
{

    cout << "Your Number is:" << ReadIntNumberInRange(10, 50);

    return 0;
}