/*
problem 7: 
write a program to read a date, and print the day name of week :

a=(14-month)/12
m=month+12a -2
d=(day +y + y/4 -y/100 +y/400 + 31m/12) %7
0 for sunday
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
short calculateDayOfWeek(int year, short month, short day)
{
    short a = (14 - month) / 12;
    short m = month + 12 * a - 2;

    short d = (day + year + year / 4 - year / 100 + year / 400 + ((31 * m) / 12)) % 7;

    return d;
}

int main()
{

    try
    {
        string arrDays[] = {"Sunday", "Monday", "tuesday", "Wednesday", "Thursday", "Friday", "saturday"};
        int year = input::readIntegerNumber("\nenter a Year      :  ");
        short month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
        short day = input::readIntegerInRange(1, 31, "enter  a Day      :  ");

        int DayOrder = calculateDayOfWeek(year, month, day);
        cout << "\n\nDate :    " << day << "/" << month << "/" << year << "\n";
        cout << "Day order :" << DayOrder << "\n";
        cout << "Day Name :" << arrDays[DayOrder] << "\n";
    }
    catch (runtime_error &e)
    {
        cin.clear();
        system("cls");
        cerr << "Exception :" << e.what() << endl;
    }

    return 0;
}