/*
problem 18:
write a program calculate you age in days
*/

#include <iostream>
#include <string>
#include <cmath>
#include "myLib.h"
#include <iomanip>
#include <ctime>
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

    int nbrDays = abs(round((date1.year - date2.year) * getAvgDaysBetweenTowYear(date1.year, date2.year)) + getNbrDaysFromDate(date1) - getNbrDaysFromDate(date2));
    includeToDay ? ++nbrDays : nbrDays;
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

int main()
{

    cout << "Enter Your Date of birth :\n";
    stDate date1 = readDate();
    cout << endl;

    int ageInDays = getDiffDaysFromTwoDate(date1, getCurrentDate(), true);

    cout << "Your age is : " << ageInDays << endl;

    return 0;
}