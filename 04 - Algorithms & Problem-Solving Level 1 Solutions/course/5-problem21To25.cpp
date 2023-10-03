#include <iostream>
#include <cmath>
using namespace std;

// #21 Circle Aria along the Circumference :  Relation=pow(l,2)*/(4*pi);
float GetCircumference()
{
    float l = 0;
    cout << "Enter the Circumference  : ";
    cin >> l;
    return l;
}

float CalculateCircleAriaByCircumference(float l)
{
    const float pi = 3.141592653589793238;

    return pow(l, 2) / (4 * pi);
}

void PrintAria(float Aria)
{
    cout << "The Aria is : " << Aria << "\n";
}

// #22 Circle Aria inscribed in an isosceles Triangle :  Relation= (pi* pow(b,2)*0.25)((2*a-b)/(2*a +b));
//  a:side of Triangle
//  b : base of Triangle
struct stCircle
{

    int a;
    int b;
};

stCircle GetCircleInfo()
{
    stCircle Circle;
    cout << "Enter the Triangle side : ";
    cin >> Circle.a;
    cout << "Enter the Triangle  bases  : ";
    cin >> Circle.b;
    return Circle;
}

float CalculateCircleAriaByInsCribedTriangle(stCircle Circle)
{
    const float pi = 3.141592653589793238;

    return ((pi * pow(Circle.b, 2) * 0.25) * ((2 * Circle.a - Circle.b) / (2.0 * Circle.a + Circle.b)));
}

// #23 :Circle Area Described around an Arbitrary Triangle :   Relation=(a+b+c)/2 :
struct stCircle23
{

    int a;
    int b;
    int c;
};

stCircle23 GetCircle23Info()
{
    stCircle23 Circle;
    cout << "Enter the Triangle left side : ";
    cin >> Circle.a;

    cout << "Enter the Triangle  bases  : ";
    cin >> Circle.b;

    cout << "Enter the Triangle right  side : ";
    cin >> Circle.c;
    return Circle;
}

float CalculateCircleAriaByArbitraryTriangle(stCircle23 Circle)
{
    const float pi = 3.141592653589793238;
    const float p = (Circle.a + Circle.b + Circle.c) / 2;
    return pi * pow((Circle.a * Circle.b * Circle.c) / (4 * sqrt(p * (p - Circle.a) * (p - Circle.b) * (p - Circle.c))), 2);
}

// #24: Generale Functions ReadAge  PrintResult ValidateNumberInRange

int ReadAge()
{
    int Age;

    cout << "Enter your Age : ";
    cin >> Age;
    return Age;
}

bool isValidNumberInRange(int Number, int From, int To)
{

    return (Number >= From && Number <= To);
}

void PrintResult(int Age)
{
    if (isValidNumberInRange(Age, 18, 45))
        cout << "Valid Age "
             << "\n";
    else
        cout << "Invalid Age \n";
}

// 25: ReadUntil Age Between 18 and 45 :

int ReadValidAge(int From, int To)
{
    int Age = 0;
    do
    {
        Age = ReadAge();

    } while (To > 45 || Age < From);
    return Age;
}
int main()
{

    // #21 :
    PrintAria(CalculateCircleAriaByCircumference(GetCircumference()));

    // #22 :
    PrintAria(CalculateCircleAriaByInsCribedTriangle(GetCircleInfo()));

    // #23 :
    PrintAria(CalculateCircleAriaByArbitraryTriangle(GetCircle23Info()));

    // #24:
    PrintResult(ReadAge());

    // #25 :
    PrintResult(ReadValidAge(18, 45));
    return 0;
}