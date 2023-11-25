/*
 problem 3 :
 write a program to check id a year is a leap year or not :

 Note :
 all years : 
  ✔️which ware perfectly divisible by 4 are leap years except for century years (years ending with 00) 
  ✔️which are leap years only if they perfectly divisible by 400

  (%4 && !%100)|| (%400)

*/
#include <iostream>
#include <string>
#include "myLib.h"
using namespace std;

enum enIsLeapYear
{
    noLeap,
    isLeap
};

enIsLeapYear checkIfYearIsLeap(int year)
{

    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? enIsLeapYear::isLeap : enIsLeapYear::noLeap;
}

int main()
{

    string arrIsLeapYear[] = {"no it's not a leap Year ", "yes it's a Leap year "};
    int year = input::readIntegerNumber("enter the number : ");

    enIsLeapYear leapYearStatus = checkIfYearIsLeap(year);
    cout << arrIsLeapYear[leapYearStatus] << endl;

    return 0;
}
