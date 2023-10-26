#include <iostream>
#include "myLib.h";
using namespace std;

int main()
{

    int mark = 90;
    string result;
    cout << "using if  :";
    if (mark >= 50)
        result = "Pass";
    else
        result = "Fail";

    cout << result << endl;

    // using short hang if :
    cout << "using short hang if : ";
    result = (mark >= 50) ? "Pass" : "Fail";
    cout << result << endl;

    // write a programs to do the following:
    /*
    + program to check if the number is Positive or Negative
    + program to check if the number is Zero, Positive, or Negative. (used nested ternary operators );
    */
   
    // program 1  :
    cout << "\nProgram 1 : \n";
    int Number = input::readIntegerNumber();

    cout << (Number > 0 ? "Positive Number :  " : "Negative Number :")<<endl;

    // program 2 :
    cout << "\nProgram 2 : \n";
    cout << (Number > 0 ? "Positive Number :  " : (Number < 0 ? "Negative Number :" : "is Zero"))<<endl;
}