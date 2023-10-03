#include <iostream>
#include <iomanip>
using namespace std;

// problem 36 :
/*
write a program to ask user to enter :
.number 1
.numer 2
.operation type :

then perform the calculation according to the operation as follows
"+"
"-"
"*"
"/"
*/

void setValues(float &num1, char &op, float &num2)
{

    cout << "enter the first number :";
    cin >> num1;
    cin.ignore();
    if (cin.fail())
        throw runtime_error("invalid number 1 value :");
    cout << "enter the operator : ";
    cin >> op;
    if (op != '+' && op != '-' && op != '*' && op != '/')
        throw string("invalid operator operator => ['+','-','*,'/']");
    cout << "enter the second number :";
    cin >> num2;
    if (cin.fail())
        throw runtime_error("invalid number 2 value");
}

void Evaluate(float num1 = 0, char op = 'I', float num2 = 0)
{

    switch (op)
    {
    case '+':
        cout << fixed << setprecision(2) << num1 + num2 << endl;
        break;

    case '-':
        cout << fixed << setprecision(2) << num1 - num2 << endl;
        break;

    case '*':
        cout << fixed << setprecision(2) << num1 * num2 << endl;
        break;

    case '/':
        cout << fixed << setprecision(2) << num1 / num2 << endl;
    }
}

int main()
{
    float num1, num2;
    char op;
    try
    {

        setValues(num1, op, num2);
        Evaluate(num1, op, num2);
    }
    catch (runtime_error e)
    {

        cerr << "Error :" << e.what() << endl;
    }
    catch (string msg)
    {
        cout << msg << endl;
    }

    return 0;
}