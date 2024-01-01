
/**
problem 57 :
Write a program to read Datel & Date2,
and write a function to compare dates, it
should return:
-1 equal
0 equal
1 after
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
enum enCompareTwoDate{
 eBefore=-1,
eEqual,
 eAfter

};
enCompareTwoDate compareTwoDate(const stDate &date1, const stDate &date2)
{

    return isDate1EqualDate2(date1, date2) ? enCompareTwoDate::eEqual : (isDate1BeforeDate2(date1, date2) ? enCompareTwoDate::eBefore : enCompareTwoDate::eAfter);
}

int main()
{

    cout << "enter  Date 1  :\n";
    stDate date1 = readDate();
    cout << "\n";

    cout << "enter  Date 2  :\n";
    stDate date2 = readDate();
    cout << "\n";

    cout << "Compare Result : " << compareTwoDate(date1, date2) << endl;

    return 0;
}