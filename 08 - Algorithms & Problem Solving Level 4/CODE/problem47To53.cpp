
/**
 problem 46 to 53 :
 Write a program to read a date and make functions
as follows:
 . Overload the DayOfWeekOrder to take date structure
· IsEndOfWeek
· IsWeekEnd
· IsBusinessDay
· DaysUntilTheEndOfWeek
. DaysUntilTheEndOfMonth
· DaysUntilTheEndOfyear

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


short getToDayOrderInWeek(stDate date)
{

    short a = (14 - date.month) / 12;
    short m = date.month + 12 * a - 2;

    short d = (date.day + date.year + date.year / 4 - date.year / 100 + date.year / 400 + ((31 * m) / 12)) % 7;

    return d;
}
stDate getCurrentDate()
{
    stDate currentDate;
    // get the nombre of second from (January 1, 1970)  date
    time_t t1 = time(0);

    // convert it to a tm strucutre :
    tm *gm = gmtime(&t1);

    currentDate.day = gm->tm_mday;
    //  month of year from 0 to 11  (start from from 0 not 1 you need to add 1 in logging)
    currentDate.month = gm->tm_mon + 1;
    // year since 1900 (you need to add 1900 in logging)
    currentDate.year = 1900 + gm->tm_year;

    return currentDate;
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
bool IsEndOfTheWeek(stDate date)
{
    enDayOrder dayOrder = enDayOrder(getToDayOrderInWeek(date));
    return dayOrder == enDayOrder::sat;
}

bool IsWeekEnd(stDate date)
{

    enDayOrder dayOrder = enDayOrder(getToDayOrderInWeek(date));

    return dayOrder == enDayOrder::fri || dayOrder == enDayOrder::sat;
}

bool isBusinessDay(stDate date)
{

    enDayOrder dayOrder = enDayOrder(getToDayOrderInWeek(date));

    return !IsWeekEnd(date); 
}
short getDaysUntilEndOfWeek(stDate date)
{

    enDayOrder dayOrder = enDayOrder(getToDayOrderInWeek(date));
    return enDayOrder::sat - dayOrder;
}
short getDaysUntilEndOfMonth(stDate date)
{

    return getMonthDaysInYear(date.year, date.month) - date.day;
}
short getDaysUntilEndOfYear(stDate date)
{

    stDate finalDate;
    finalDate.year = date.year;
    finalDate.month = 12;
    finalDate.day = 31;
    return getDiffDaysFromTwoDate(date, finalDate);
}

int main()
{
    string arrDays[] = {"Sun", "Mon", "tues", "Wed", "Thurs", "Fri", "sat"};

    stDate currentDate = getCurrentDate();
    cout << "Today is " << arrDays[getToDayOrderInWeek(currentDate)] << " , " << convertDateToString(currentDate) << "\n\n";

    cout << "Is it End of week? \n";

    cout << (IsEndOfTheWeek(currentDate) ? "Yes it is  end of week  " : "No it is not end of week . ") << "\n\n";

    cout << "Is it Weekend? \n";
    cout << (IsWeekEnd(currentDate) ? "Yes it is a week end. " : "No it is not a week end. ") << "\n\n";

    cout << "Is it Business Day \n";
    cout << (isBusinessDay(currentDate) ? "Yes it is Business day. " : "No it is not Business day. ") << "\n\n";

    cout << "Days until end of Week  : " << getDaysUntilEndOfWeek(currentDate) << " Day(s)\n";
    cout << "Days until end of Month : " << getDaysUntilEndOfMonth(currentDate) << " Day(s)\n";
    cout << "Days until end of Year  : " << getDaysUntilEndOfYear(currentDate) << " Day(s)\n";

    return 0;
}