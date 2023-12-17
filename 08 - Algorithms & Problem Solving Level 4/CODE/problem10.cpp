/*
problem 10:
write a program to print total days from the beginning of year :

*/
#include <iostream>
#include <string>
#include "myLib.h"
#include <iomanip>
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

int getMonthDaysInYear(int year, int month)
{
    int numberOfDays[12] = {31, month == 2 && checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numberOfDays[month - 1];
}

int getNbrDaysFromDate(short day, short month, int year)
{

    short days = 0;
    for (int i = 1; i < month; i++)
    {

        days += getMonthDaysInYear(year, i);
    }

    days += day;

    return days;
}
int main()
{

    try
    {
        short day = input::readIntegerInRange(1, 31, "enter  a day   :  ");
        short month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
        int year = input::readIntegerNumber("\nenter a Year      :  ");
        cout << "Number of Days from the beginning of the year is : " << getNbrDaysFromDate(day, month, year) << endl;
    }
    catch (runtime_error &e)
    {

        cerr << "Exception : " << e.what() << endl;
    }


system("pause>0"); 
    return 0;
}
