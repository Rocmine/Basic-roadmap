#include<iostream>
using namespace std; 

//problem 22 : 

/*
write  a program to calculate circle area inscribed in an isosceles triangle : then print it on the screen :
the user should enter  :  a b 

the aria =  (π * b^2)/4.0* (2*a-b)/(2*a+b)

*/


#include <iostream>

// include iomanip for using  set the number of decimal  digit by 2 :
#include <iomanip>

// include math library for using  pow function:
#include <cmath>

// ignore the using of std::
using namespace std;

void getValues(float &side, float &base)
{
    cout << "enter the  the side :";
    cin >> side;
    cin.ignore();

    if (cin.fail() || side < 0)
        throw runtime_error("invalid side value :");

    cout << "entre the base ";
    cin >> base;

    if (cin.fail() || base < 0)
        throw runtime_error("invalid base value");
}

float getAria(const float side = 0, const float base = 0)
{
   const float p = 3.141592654;
    float aria = (p * pow(base,2)/4.0)* ((2*side-base)/float(2*side+base));
 
    return aria;
}

void PrintAria(const float aria)
{

    cout << "the aria of this circle is :" << fixed << setprecision(2) << aria << endl;
}

int main()
{

    float side, base;

    // get number  from user:
    try
    {

        getValues(side, base);

        const float aria = getAria(side, base);
        PrintAria(aria);
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}