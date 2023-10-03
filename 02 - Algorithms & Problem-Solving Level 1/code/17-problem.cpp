

// problem 17 :
/*
write a program to calculate triangle area then  print it on the screen :
the use should enter :  a h
area =1/2 * a *h
*/

#include <iostream>

// include iomanip for using  set the number of decimal  digit by 2 :
#include <iomanip>

// ignore the using of std::
using namespace std;

void getValues(float &side, float &hight)
{
    cout << "enter the  the side :";
    cin >> side;
    cin.ignore();

    if (cin.fail() || side < 0)
        throw runtime_error("invalid side value :");

    cout << "entre the hight ";
    cin >> hight;

    if (cin.fail() || hight < 0)
        throw runtime_error("invalid hight value");
}

float getAria(const float side = 0, const float hight = 0)
{

    float aria = 1 / 2.0 * side * hight;
   
    return aria;
}

void PrintAria(const float aria)
{

    cout << "the aria of this triangle  is :" << fixed << setprecision(2) << aria << endl;
}

int main()
{

    float side, hight;

    // get number  from user:
    try
    {

        getValues(side, hight);

        const float aria = getAria(side, hight);
        PrintAria(aria);
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}