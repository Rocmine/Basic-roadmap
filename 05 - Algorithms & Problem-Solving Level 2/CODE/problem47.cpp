#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string UserText)
{
    float num = 0;

    cout << UserText;
    cin >> num;

    return num;
}

int MyRound(float Number)
{
    return abs(int(Number * 10) % 10) >= 5 ? (Number > 0 ? Number + 1 : Number - 1) : Number;
}

int main()
{

    float Number = ReadNumber("Enter A Number :");

    cout << "My round Result : " << MyRound(Number) << endl;
    cout << "C++ round Result : " << round(Number) << endl;

    return 0;
}