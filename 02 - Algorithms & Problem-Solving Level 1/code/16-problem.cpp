

// problem 16 :
/*
write a program to calculate rectangle area through diagonal and side area of rectangle and print it on the screen :
the use should enter :  a d
area =a*√(d² + a²)
*/

#include <iostream>
// include math library for using print pow and sqrt :
#include <cmath>

// include iomanip for using  set the number of decimal  digit by 2 :
#include <iomanip>

// ignore the using of std::
using namespace std;

void getValues(float &side, float &diagonal)
{
    cout << "enter the  the side :";
    cin >> side;
    cin.ignore();

    if (cin.fail() || side < 0)
        throw runtime_error("invalid side value :");

    cout << "entre the diagonal ";
    cin >> diagonal;

    if (cin.fail() || diagonal < 0)
        throw runtime_error("invalid diagonal value");
}

float getAria(const float side = 0, const float diagonal = 0)
{

    // using the cmath library : area =a*√(d² - a²)
    float aria = side * sqrt(pow(diagonal, 2) - pow(side, 2));
    return aria;
}

void PrintAria(const float aria)
{

    cout << "the aria of this rectangle  is :" << fixed << setprecision(2) << aria << endl;
}

int main()
{

    float side, diagonal;

    // get number  from user:
    try
    {

        getValues(side, diagonal);
        const float aria = getAria(side, diagonal);
        PrintAria(aria);
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}