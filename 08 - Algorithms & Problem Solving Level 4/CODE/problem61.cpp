/*
problem 60 :
Write a program to read a tow periods
then count overlap days?
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

struct stPeriod
{

    stDate startDate;
    stDate endDate;
};
stPeriod readPeriod()
{
    stPeriod period;
    cout << "Enter the Start Day : \n\n";
    period.startDate = readDate();

    cout << "\nEnter the End Day : \n\n";
    period.endDate = readDate();

    return period;
}
bool isDate1EqualDate2(const stDate &date1, const stDate &date2)
{

    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

bool isDate1BeforeDate2(const stDate &date1, const stDate &date2)
{
    if (date1.year < date2.year || (date1.year == date2.year && date1.month < date2.month) ||
        (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isDate1AfterDate2(const stDate &date1, const stDate &date2)
{

    return isDate1EqualDate2(date1, date2) ? false : (isDate1BeforeDate2(date1, date2) ? false : true);
}
enum enCompareTwoDate
{
    eBefore = -1,
    eEqual,
    eAfter

};
enCompareTwoDate compareTwoDate(const stDate &date1, const stDate &date2)
{

    return isDate1EqualDate2(date1, date2) ? enCompareTwoDate::eEqual : (isDate1BeforeDate2(date1, date2) ? enCompareTwoDate::eBefore : enCompareTwoDate::eAfter);
}

bool isDateWithinPeriod(stPeriod period, stDate date)
{

    return (compareTwoDate(period.startDate, date) == enCompareTwoDate::eBefore || compareTwoDate(period.startDate, date) == enCompareTwoDate::eEqual) &&
           (compareTwoDate(period.endDate, date) == enCompareTwoDate::eAfter || compareTwoDate(period.endDate, date) == enCompareTwoDate::eEqual);
}
bool checkIfLastDaysInMonth(stDate date)
{
    return date.day == getMonthDaysInYear(date.year, date.month);
}

bool checkIfLastMonthInYear(short month)
{

    return month == 12;
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

bool isTwoPeriodsOverLap(const stPeriod &p1, const stPeriod &p2)
{

    bool p1OverlapP2 =
        (compareTwoDate(p1.startDate, p2.endDate) == enCompareTwoDate::eBefore || compareTwoDate(p1.startDate, p2.endDate) == enCompareTwoDate::eEqual) && (compareTwoDate(p1.endDate, p2.startDate) == enCompareTwoDate::eAfter || compareTwoDate(p1.endDate, p2.startDate) == enCompareTwoDate::eEqual);

    bool p2OverlapP1 =
        (compareTwoDate(p2.startDate, p1.endDate) == enCompareTwoDate::eBefore || compareTwoDate(p2.startDate, p1.endDate) == enCompareTwoDate::eEqual)

        && (compareTwoDate(p2.endDate, p1.startDate) == enCompareTwoDate::eAfter || compareTwoDate(p2.endDate, p1.startDate) == enCompareTwoDate::eEqual);

    if (p1OverlapP2 || p2OverlapP1)

        return true;

    return false;
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

    return includeToDay ? ++nbrDays : nbrDays;
}

int getLengthOfPeriod(stPeriod period, bool includeEndDate = false)
{

    return getDiffDaysFromTwoDate(period.startDate, period.endDate, includeEndDate);
}

int getNbrOverlapsDaysBetweenTwoPeriods(stPeriod period1, stPeriod period2)
{

    if (!isTwoPeriodsOverLap(period1, period2))
        return 0;

    int nbrOverlapsDays = 0;
    stPeriod allPeriod;
    allPeriod.startDate = compareTwoDate(period1.startDate, period2.startDate) == enCompareTwoDate::eBefore ? period1.startDate : period2.startDate;
    allPeriod.endDate = compareTwoDate(period1.endDate, period2.endDate) == enCompareTwoDate::eAfter ? period1.endDate : period2.endDate;

    for (stDate i = allPeriod.startDate; compareTwoDate(i, allPeriod.endDate) == enCompareTwoDate::eBefore || compareTwoDate(i, allPeriod.endDate) == enCompareTwoDate::eEqual; increaseDateByOneDay(i))
    {

        if (compareTwoDate(i, period1.endDate) == enCompareTwoDate::eAfter || compareTwoDate(i, period2.endDate) == enCompareTwoDate::eAfter)
            return nbrOverlapsDays;

        if (isDateWithinPeriod(period1, i) && isDateWithinPeriod(period2, i))
        {

            nbrOverlapsDays++;
        }
    }

    return nbrOverlapsDays;
}
int main()
{

    stPeriod p1, p2;

    cout << "\nEnter Period 1 :\n";
    p1 = readPeriod();

    cout << "\nEnter Period 2 :\n";
    p2 = readPeriod();

    cout << "\nOverlap Days Count is : " << getNbrOverlapsDaysBetweenTwoPeriods(p1, p2) << endl;
}