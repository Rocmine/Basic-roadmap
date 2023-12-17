/*
problem 16:
Write a program to read date and  make a function
to increase date by one day.

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

short getMonthDaysInYear(short year, short month)
{
    int numberOfDays[] = {0, 31, checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numberOfDays[month];
}

struct stDate
{
    short year;
    short month;
    short day;
};

bool checkIfLastDaysInMonth(stDate date)
{
    return date.day == getMonthDaysInYear(date.year, date.month);
}

bool checkIfLastMonthInYear(short month)
{

    return month == 12;
}

bool checkIfValidDay(stDate date){

return date.day <=getMonthDaysInYear(date.year,date.month);

}
stDate readDate()
{
    stDate date;

    date.day = input::readIntegerInRange(1, 31, "enter  a day   :  ");
    date.month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
    date.year = input::readIntegerNumber("enter a Year      :  ");
 if( !checkIfValidDay(date)) date.day=getMonthDaysInYear(date.year,date.month);
    return date;
}

string convertDateToString(stDate date)
{

    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

void increaseDateByOneDay(stDate &date)
{

    if (checkIfLastDaysInMonth(date))
    {

        if (checkIfLastMonthInYear(date.month))
        {
            date.year++;
            date.day = 1;
            date.month = 1;
        }
        else
        {
            date.month++;
            date.day = 1;
        }
    }
    else
    {
        cout<<"hi\n";
        date.day++;
    }
}
int main()
{
    stDate date = readDate();
    cout << endl;

     increaseDateByOneDay(date);

    cout << convertDateToString(date) << endl;
//  test update 
    return 0;
}