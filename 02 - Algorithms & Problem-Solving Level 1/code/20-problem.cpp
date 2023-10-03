

// problem 20:
/*
write a program to calculate circle area  inscribed in a square  then  print it on the screen :
the use should enter :  A
area =(π × d^2)/4
*/

#include <iostream>

// include iomanip for using  set the number of decimal  digit by 2 :
#include <iomanip>
// include math library for using  pow function:
#include <cmath>
// ignore the using of std::
using namespace std;

void getValue(float &a)
{
    cout << "enter the  the side :";
    cin >> a;

    if (cin.fail() || a < 0)
        throw runtime_error("invalid side value :");
}

float getAria(const float a = 0)
{
    const float p = 3.141592654;
    float aria = (p * pow(a, 2)) / 4;
    return aria;
}

void PrintAria(const float aria)
{

    cout << "the aria of this circle is :" << fixed << setprecision(2) << aria << endl;
}

int main()
{

    float a;

    // get number  from user:
    try
    {

        getValue(a);

        const float aria = getAria(a);
        PrintAria(aria);
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}