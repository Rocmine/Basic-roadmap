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

int MySqrt(float Number)
{

    return pow(Number, 0.5);
}

int main()
{

    float Number = ReadNumber("Enter A Number :");

    cout << "My Sqrt Result : " << MySqrt(Number) << endl;
    cout << "C++ Sqrt Result : " << sqrt(Number) << endl;

    return 0;
}