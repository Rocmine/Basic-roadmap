#include <iostream>
#include <cmath>
using namespace std;

// # 16  Rectangle  Relation = a*sqrt(pow(d,2)-pow(a,2));
struct stRectangle
{
    int a;
    int d;
};

stRectangle GetAriaRectangleInfo()
{
    stRectangle Rectangle;
    cout << "Enter the side  :";
    cin >> Rectangle.a;
    cout << "Enter the diagonal :";
    cin >> Rectangle.d;
    return Rectangle;
}

float CalculateRectangleAria(stRectangle Rectangle)
{
    return Rectangle.a * sqrt(pow(Rectangle.d, 2) - pow(Rectangle.a, 2));
}

void PrintAria(float Aria)
{
    cout << "The Aria is : " << Aria << "\n";
}

// #17 Triangle Aria  1/2base * h :
struct stTriangle
{
    int base;
    int h;
};

stTriangle GetAriaTriangleInfo()
{
    stTriangle Triangle;
    cout << "Enter the base  :";
    cin >> Triangle.base;
    cout << "Enter the height :";
    cin >> Triangle.h;
    return Triangle;
}

float CalculateTriangleAria(stTriangle Triangle)
{
    return 0.5 * Triangle.base * Triangle.h;
}

// #18  circle Aria  Relation=pi*pow(r,2);

float GetRadios()
{
    float Radios = 0;
    cout << "Enter the Radios :";
    cin >> Radios;
    return Radios;
}

float CalculateCircleAria(float Radios)
{
    const float pi = 3.141592653589793238;

    return pi * pow(Radios, 2);
}

// #19 Circle Aria  Relation = (pi*pow(D,2))/4:
float GetDiameter()
{
    float Diameter = 0;
    cout << "Enter the Diameter :";
    cin >> Diameter;
    return Diameter;
}

float CalculateCircleAriaDiameter(float Diameter)
{
    const float pi = 3.141592653589793238;

    return (pi * pow(Diameter, 2)) * 0.25;
}

// #20 circle Area Inscribed in a square :   Relation= pi*pow(a,2)*0.25 ;
float GetSquareSide()
{
    float SquareSide = 0;
    cout << "Enter the Side of the square :";
    cin >> SquareSide;
    return SquareSide;
}

float CalculateCircleAriaBySquareSide(float SquareSide)
{
    const float pi = 3.141592653589793238;

    return pi * pow(SquareSide, 2) * 0.25;
}

int main()
{
    // #16  :
    // PrintAria(CalculateRectangleAria(GetAriaRectangleInfo()));

    // #17  :
    // PrintAria(CalculateTriangleAria(GetAriaTriangleInfo()));

    // #18 :

    // PrintAria(CalculateCircleAria(GetRadios()));

    // #19 :

    //  PrintAria( CalculateCircleAriaDiameter(GetDiameter()));

    // #20 :
    PrintAria(CalculateCircleAriaBySquareSide(GetSquareSide()));

    return 0;
}