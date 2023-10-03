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

int MyCeil(float Number)
{

    float FloatDigit = Number * 10;
    FloatDigit = int(FloatDigit) % 10;

    return FloatDigit > 0 ? Number + 1 : Number;
}

int main()
{

    float Number = ReadNumber("Enter A Number :");

    cout << "My Ceil Result : " << MyCeil(Number) << endl;
    cout << "C++ Ceil Result : " << ceil(Number) << endl;

    return 0;
}