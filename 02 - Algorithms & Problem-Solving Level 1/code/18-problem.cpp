

// problem 18 :
/*
write a program to calculate circle area then  print it on the screen :
the use should enter :  π × r2 
area = π × r2 
*/

#include <iostream>

// include iomanip for using  set the number of decimal  digit by 2 :
#include <iomanip>
// include math library for using  pow function:
#include <cmath>
// ignore the using of std::
using namespace std;

void getValue(float &r)
{
    cout << "enter the  the radius :";
    cin >> r;

    if (cin.fail() || r < 0)
        throw runtime_error("invalid radius value :");
}

float getAria(const float r=0)
{
  const float p=3.141592654; 
    float aria =p*pow(r,2);
    return aria;
}

void PrintAria(const float aria)
{

    cout << "the aria of this circle is :" << fixed << setprecision(2) << aria << endl;
}

int main()
{

    float r;

    // get number  from user:
    try
    {

        getValue(r);

        const float aria = getAria(r);
        PrintAria(aria);
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}