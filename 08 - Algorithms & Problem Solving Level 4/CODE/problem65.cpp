/*
problem 65 :
Write a program to read Date and write a
function to format that date.A
*/

#include <iostream>
#include <string>
#include <cmath>
#include "myLib.h"
#include <iomanip>
#include <cctype>
#include <vector>
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

string convertDateToString(stDate date)
{

    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}
enum enFormDate
{
    eDMYSlash,
    eYMDSlash,
    eDMYDash,
    eYMDDash,

};

string getFormattedDate(stDate date, enFormDate formNumber = enFormDate::eDMYSlash)
{

    if (formNumber == enFormDate::eDMYSlash)
        return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
    if (formNumber == enFormDate::eYMDSlash)
        return to_string(date.year) + "/" + to_string(date.month) + "/" + to_string(date.day);
    if (formNumber == enFormDate::eDMYDash)
        return to_string(date.day) + "-" + to_string(date.month) + "-" + to_string(date.year);
    if (formNumber == enFormDate::eYMDDash)
        return to_string(date.year) + "/" + to_string(date.month) + "/" + to_string(date.day);
}

bool isAValidDate(stDate date)
{

    return ((checkIfValidDay(date)) && (date.month <= 12 && date.month >= 1));
}

vector<string> getSplitStringWordToVector(string str, string delim = "/")
{
    vector<string> vstr;
    short counter = 0;
    short pos = 0;
    string word;

    while ((pos = str.find(delim)) != string::npos)
    {

        vstr.push_back(str.substr(0, pos));

        str.erase(0, pos + delim.length());
    }

    // counts the last word :
    if (str != "")
        vstr.push_back(str);

    return vstr;
}

stDate convertStringToDate(string strDate)
{

    stDate date;

    vector<string> vDate = getSplitStringWordToVector(strDate);

    date.day = stoi(vDate[0]);
    date.month = stoi(vDate[1]);
    date.year = stoi(vDate[2]);

    if (!isAValidDate(date))
    {
        date.day = 0;
        date.month = 0;
        date.year = 0;
    }
    cout << "Date : " << convertDateToString(date) << "\n";

    return date;
}
int main()
{

    cout << "enter  the date info : \n";

    string strDate = input::readString("enter the date : ");

    stDate date = convertStringToDate(strDate);

    cout << getFormattedDate(date, enFormDate::eDMYSlash) << "\n\n";
    cout << getFormattedDate(date, enFormDate::eYMDSlash) << "\n\n";
    cout << getFormattedDate(date, enFormDate::eDMYDash) << "\n\n";
    cout << getFormattedDate(date, enFormDate::eYMDDash) << "\n\n";

    return 0;
}
