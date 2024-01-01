/*
problem 20 to 32:
Write a program to read a date and make a functions
to increase date as follows:
. IncreaseDateByXDays
· IncreaseDateByOneWeek
. IncreaseDateByXWeeks
. IncreaseDateByOneMonth
. IncreaseDateByXMonths
. IncreaseDateByOneyear
. IncreaseDateByXYears
. IncreaseDateByXYearsFaster
. IncreaseDateByOneDecade
. IncreaseDateByXDecades
. IncreaseDateByXDecadesFaster
. IncreaseDateByOneCentury
. IncreaseDateByOneMillennium

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

void increaseDaysByXDays(stDate &date, int nbrDays)
{

    for (int i = 0; i < nbrDays; i++)
    {

        increaseDateByOneDay(date);
    }
}
void increaseDaysByOneWeek(stDate &date)
{

    increaseDaysByXDays(date, 7);
}

void increaseDaysByXWeeks(stDate &date, int nbrWeeks)
{
    for (int i = 0; i < nbrWeeks; i++)
    {
        increaseDaysByOneWeek(date);
    }
}

void increaseDaysByOneMonth(stDate &date)
{

    if (date.month == 12)
    {
        date.month = 1;
        date.year++;
    }
    else
    {
        date.month++;
    }

    int nbrDaysInMonth = getMonthDaysInYear(date.year, date.month);
    if (date.day > nbrDaysInMonth)
        date.day = nbrDaysInMonth;
}

void increaseDaysByXMonths(stDate &date, int nbrMonths)
{

    for (int i = 0; i < nbrMonths; i++)
    {

        increaseDaysByOneMonth(date);
    }
}

void increaseDaysByOneYear(stDate &date)
{

    date.year++;
}

void increaseDaysByXYears(stDate &date, int nbrYears)
{

    for (int i = 0; i < nbrYears; i++)
    {

        increaseDaysByOneYear(date);
    }
}

void increaseDaysByOneDecade(stDate &date)
{

    increaseDaysByXYears(date, 10);
}

void increaseDaysByXDecades(stDate &date, int nbrDecades)
{

    for (int i = 0; i < nbrDecades; i++)
    {

        increaseDaysByOneDecade(date);
    }
}
void increaseDaysByOneCentury(stDate &date)
{

    increaseDaysByXDecades(date, 10);
}

void increaseDaysByXCentury(stDate &date, int nbrCentury)
{

    for (int i = 0; i < nbrCentury; i++)
    {
        increaseDaysByOneCentury(date);
    }
}

void increaseDaysByOneMillennium(stDate &date)
{

    increaseDaysByXCentury(date, 10);
}

int main()
{

    stDate date = readDate();

    increaseDateByOneDay(date);
    cout << " 1- Adding one day is      : " << convertDateToString(date) << "\n ";

    increaseDaysByXDays(date, 10);
    cout << "2- Adding 10  day is      : " << convertDateToString(date) << "\n ";

    increaseDaysByOneWeek(date);
    cout << "3- Adding one week is     : " << convertDateToString(date) << "\n ";

    increaseDaysByXWeeks(date, 10);
    cout << "4- Adding 10 weeks is     : " << convertDateToString(date) << "\n ";

    increaseDaysByOneMonth(date);
    cout << "5- Adding One Month is    : " << convertDateToString(date) << "\n ";

    increaseDaysByXMonths(date, 5);
    cout << "6- Adding 5 Months  is    : " << convertDateToString(date) << "\n ";

    increaseDaysByOneYear(date);
    cout << "7- Adding one year is     : " << convertDateToString(date) << "\n ";

    increaseDaysByXYears(date, 10);
    cout << "8- Adding 10 years  is    : " << convertDateToString(date) << "\n ";

    increaseDaysByOneDecade(date);
    cout << "9- Adding one Decade is   : " << convertDateToString(date) << "\n ";

    increaseDaysByXDecades(date, 10);
    cout << "10- Adding 10 Decades is  : " << convertDateToString(date) << "\n ";

    increaseDaysByOneCentury(date);
    cout << "11- Adding one Century is : " << convertDateToString(date) << "\n ";

    increaseDaysByOneMillennium(date);
    cout << "12- Adding one Millennium is : " << convertDateToString(date) << "\n ";

    return 0;
}