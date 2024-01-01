/*
problem 58 :
Write a program to read Two Periods and
check if they overlap or not?
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

int main()
{

    stPeriod p1, p2;

    cout << "\nEnter Period 1 :\n";
    p1 = readPeriod();

    cout << "\nEnter Period 2 :\n";
    p2 = readPeriod();

    cout << (isTwoPeriodsOverLap(p1, p2) ? "Yes, Periods Overlap : " : "No, Periods Does not Overlap ") << endl;
}