#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int ReadNumber(string UserText)
{
    int num = 0;

    cout << UserText;
    cin >> num;

    return num;
}

int GetAbsOfNumber(int Number)
{

    return Number >= 0 ? Number : -Number;
}

int main()
{

    int Number = ReadNumber("Enter A Number :");

    cout << "My abs Result : " << GetAbsOfNumber(Number) << endl;
    cout << "C++ abs Result : " << abs(Number) << endl;

    return 0;
}