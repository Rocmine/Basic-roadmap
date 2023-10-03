

// problem 19:
/*
write a program to calculate circle area through diameter  then  print it on the screen :
the use should enter :  d
area =(π × d^2)/4
*/

#include <iostream>

// include iomanip for using  set the number of decimal  digit by 2 :
#include <iomanip>
// include math library for using  pow function:
#include <cmath>
// ignore the using of std::
using namespace std;

void getValue(float &d)
{
    cout << "enter the  the diameter :";
    cin >> d;

    if (cin.fail() || d < 0)
        throw runtime_error("invalid diameter value :");
}

float getAria(const float d = 0)
{
    const float p = 3.141592654;
    float aria = (p * pow(d, 2)) / 4;
    return aria;
}

void PrintAria(const float aria)
{

    cout << "the aria of this circle is :" << fixed << setprecision(2) << aria << endl;
}

int main()
{

    float d;

    // get number  from user:
    try
    {

        getValue(d);

        const float aria = getAria(d);
        PrintAria(aria);
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}