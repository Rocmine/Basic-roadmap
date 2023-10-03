#include <iostream>
using namespace std;
int main()
{

    int a, b;

    cout << "enter the first number A?";
    cin >> a;
    cout << "enter the second number B?";
    cin >> b;

    cout << a << " == " << b << " is " << (a == b) << "\n";
    cout << a << " != " << b << " is " << (a != b) << "\n";
    cout << a << " > " << b << " is " << (a > b) << "\n";
    cout << a << " < " << b << " is " << (a < b) << "\n";
    cout << a << " >= " << b << " is " << (a >= b) << "\n";
    cout << a << " <= " << b << " is " << (a <= b) << "\n";
    return 0;
}