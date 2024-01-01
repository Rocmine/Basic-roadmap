
/*
problem 54 :
Write a program to read Vacation Period
DateFrom and Date To and make a function
to calculate the actual vacation days.

Note: Weekends are excluded.
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

    return includeToDay ? (nbrDays > 0 ? ++nbrDays : --nbrDays) : nbrDays;
}

int GetNumberOfVacationDaysFromTwoDate(stDate dateStart, stDate dateEnd)
{

    int numberOfVacationDays = 0;
    int diffDays = getDiffDaysFromTwoDate(dateStart, dateEnd);

    for (int i = 0; i < diffDays; i++)
    {

        if (!IsWeekEnd(dateStart))
            numberOfVacationDays++;

        increaseDateByOneDay(dateStart);
    }

    return numberOfVacationDays;
}

int main()
{

    string arrDays[] = {"Sun", "Mon", "tues", "Wed", "Thurs", "Fri", "sat"};
    cout << "Vacation Starts :\n";
    stDate dateStart = readDate();
    cout << "\n";

    cout << "\nVacation Ends :\n";
    stDate dateEnds = readDate();
    cout << "\n";

    cout << "Vacation From: " << arrDays[getToDayOrderInWeek(dateStart)] << " , " << convertDateToString(dateStart) << "\n";
    cout << "Vacation To: " << arrDays[getToDayOrderInWeek(dateEnds)] << " , " << convertDateToString(dateEnds) << "\n\n";

    cout << "Actual Vacation Days is : " << GetNumberOfVacationDaysFromTwoDate(dateStart, dateEnds) << endl;

    return 0; 
}