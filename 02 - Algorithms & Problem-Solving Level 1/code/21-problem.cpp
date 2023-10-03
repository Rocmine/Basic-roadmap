

// problem 21:
/*
write a program to calculate circle area  along  the circumference then  print it on the screen :
the use should enter :  l
area = l^2/4*π
*/

#include <iostream>

// include iomanip for using  set the number of decimal  digit by 2 :
#include <iomanip>
// include math library for using  pow function:
#include <cmath>
// ignore the using of std::
using namespace std;

void getValue(float &l)
{
    cout << "enter the  the circumference :";
    cin >> l;

    if (cin.fail() || l < 0)
        throw runtime_error("invalid circumference value :");
}

float getAria(const float l = 0)
{
    const float p = 3.141592654;
    float aria = pow(l,2)/(4*p);
    return aria;
}

void PrintAria(const float aria)
{

    cout << "the aria of this circle is :" << fixed << setprecision(2) << aria << endl;
}

int main()
{

    float l;

    // get number  from user:
    try
    {

        getValue(l);

        const float aria = getAria(l);
        PrintAria(aria);
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}