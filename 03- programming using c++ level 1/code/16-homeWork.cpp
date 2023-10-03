#include <iostream>
using namespace std;

// lesson 42
int x = 20;
int y = 55;

void MyFunctionY()
{
    int y = 40;

    cout << "from function y = " << y << endl;
    y++;
}
// 12 40 50 44  20 55

void MyFunction()
{
    int x = 12;
    cout << "from function x = " << x << endl;
    x++;
}

int main()
{

    int x = 50;
    int y = 44;
    MyFunction();
    MyFunctionY();
    cout << "x from main : " << x << "\n";
    cout << "y from main " << y << "\n";
    cout << "x from global : " << ::x << "\n";
    cout << "y from global :" << ::y << endl;

    return 0;
}