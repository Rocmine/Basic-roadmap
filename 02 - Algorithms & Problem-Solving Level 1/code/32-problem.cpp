
// problem 32
/*
write a program to ask the user to enter :
number
.m
then print the  , number ^m
*/

#include <iostream>
#include <cmath>
using namespace std;

void isValid();
int setValues(int &number, int &m)
{
    cout << "enter  number  :";

    cin >> number;
    cin.ignore();
    isValid();
    cout << "enter M :";
    cin >> m;
    isValid();
    if (m < 0)
        throw string("M should be grater than or equal 0");

    return number;
}

void isValid()
{
    if (cin.fail())
        throw runtime_error("invalid number :");
}

int powCopy(int a, int b)
{   
    if(b==0) return 0 ; 
    int res = a;
    for (int i = 1; i < b; i++)
    {
        res *= a;
    }
    return res;
}

int main()
{

    try
    {

        int number, m;
        setValues(number, m);
        cout << powCopy(number, m);
    }
    catch (runtime_error e)
    {

        cout << "Error: " << e.what() << endl;
    }
}
