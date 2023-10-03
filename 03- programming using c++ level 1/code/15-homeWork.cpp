// lesson 34 :

#include <iostream>
using namespace std;

void mySumProcedure()
{

    int Num1, Num2;
    cout << "enter the first number  : ";
    cin >> Num1;

    cout << "enter the second number :";
    cin >> Num2;

    cout << "------------\n";
    cout << Num1 + Num2 << endl;
}

int mySumFunction()
{
    int Num1, Num2;
    cout << "enter the first number  : ";
    cin >> Num1;

    cout << "enter the second number :";
    cin >> Num2;
    cout << "------------\n";
    return Num1 + Num2;
}

int main()
{

    cout << "Procedure : \n";
    mySumProcedure();

    cout << "Function  \n";
    cout << mySumFunction() << endl;

    return 0;
}