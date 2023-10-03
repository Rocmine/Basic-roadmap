#include<iostream>
using namespace std; 

//problem 23 : 

/*
write  a program to calculate circle area described around an arbitrary triangle  then print it on the screen :
the user should enter  :  a b 
p=(a+b+c)/2

the aria =  π(pow( (a*b*c)/4*sqrt( p*(p-a)*(p-b)*(p-c) ),2) )

*/


#include <iostream>

// include iomanip for using  set the number of decimal  digit by 2 :
#include <iomanip>

// include math library for using  pow function:
#include <cmath>

// ignore the using of std::
using namespace std;

void getValues(float &a, float &b, float &c)
{
    cout << "enter  the value of a :";
    cin >> a;
    cin.ignore();

    if (cin.fail() || a < 0)
        throw runtime_error("invalid a value :");

    cout << "enter  the value of a :";
    cin >> b;
    cin.ignore();
    if (cin.fail() || b< 0)
        throw runtime_error("invalid b value");

            cout << "enter  the value of c :";
              cin >> c;
      
    if (cin.fail() || c< 0) throw runtime_error("invalid c value");
}

float getAria(const float a = 0, const float b = 0, const float c=0)
{
   const float p = (a+b+c)/2;
  float  pi=3.141592654; 
  float area = pi * pow((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2);
    return area;
}

void PrintAria(const float aria)
{

    cout << "the area of this circle is :" << fixed << setprecision(2) << aria << endl;
}

int main()
{

    float a, b,c; 

    // get number  from user:
    try
    {

        getValues(a, b,c);

        const float area = getAria(a,b,c);
        PrintAria(area);
    }
    catch (runtime_error e)
    {

        cout << "Error " << e.what() << endl;
    }

    return 0;
}