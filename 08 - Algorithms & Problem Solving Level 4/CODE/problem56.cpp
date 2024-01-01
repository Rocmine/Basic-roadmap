
/**
problem 56 :
Write a program to read Date1 & Date2,
and check if Date1 is after Date2 or not.
*/

#include <iostream>
#include <string>
#include <cmath>
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

bool checkIfValidDay(stDate date)
{

    return date.day <= getMonthDaysInYear(date.year, date.month);
}
stDate readDate()
{
    stDate date;

    date.day = input::readIntegerInRange(1, 31, "enter  a day   :  ");
    date.month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
    date.year = input::readIntegerNumber("enter a Year      :  ");
    if (!checkIfValidDay(date))
        date.day = getMonthDaysInYear(date.year, date.month);
    return date;
}

string convertDateToString(stDate date)
{

    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

short getToDayOrderInWeek(stDate date)
{

    short a = (14 - date.month) / 12;
    short m = date.month + 12 * a - 2;

    short d = (date.day + date.year + date.year / 4 - date.year / 100 + date.year / 400 + ((31 * m) / 12)) % 7;

    return d;
}

enum enDayOrder
{
    sun,
    mon,
    tues,
    wed,
    thus,
    fri,
    sat
};
bool IsWeekEnd(stDate date)
{

    enDayOrder dayOrder = enDayOrder(getToDayOrderInWeek(date));

    return dayOrder == enDayOrder::fri || dayOrder == enDayOrder::sat;
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

        date.day++;
    }
}
int getNbrDaysFromDate(stDate date)
{

    short days = 0;
    for (int i = 1; i < date.month; i++)
    {

        days += getMonthDaysInYear(date.year, i);
    }

    days += date.day;

    return days;
}
int yearToDays(int year)
{

    return checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 366 : 365;
}

float getAvgDaysBetweenTowYear(int year1, int year2)
{

    if (year1 == year2)
        return 0;

    int maxYear = year1 > year2 ? year1 : year2;
    int minYear = year1 < year2 ? year1 : year2;
    float avgDays = 0;

    for (int i = minYear; i <= maxYear; i++)
    {

        avgDays += yearToDays(i);
    }

    avgDays /= (maxYear * 1.0 - minYear) + 1;

    return avgDays;
}

int getDiffDaysFromTwoDate(stDate date1, stDate date2, bool includeToDay = false)
{

    int nbrDays = (round((date2.year - date1.year) * getAvgDaysBetweenTowYear(date2.year, date1.year)) + getNbrDaysFromDate(date2) - getNbrDaysFromDate(date1));

    return includeToDay ?  ++nbrDays : nbrDays;
}


bool isDate1AfterDate2(stDate date1, stDate date2)
{

     return  getDiffDaysFromTwoDate(date2, date1) >= 0 ;
}

int main()
{

    cout << "enter  Date 1  :\n";
    stDate date1 = readDate();
    cout << "\n";

    cout << "enter  Date 2  :\n";
    stDate date2 = readDate();
    cout << "\n";

    cout << (isDate1AfterDate2(date1, date2) ? "Yes, Date1 is After Date2" : "No, Date1 is not after  Date1 ") << endl;

    return 0;
}