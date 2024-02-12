#pragma once

#include <iostream>
#include <iomanip>
#include "./input.h"
using namespace std;

class cDate
{
private:
    short days;
    short month;
    int year;

    // convert from  cDate to string function  :
    string getDateToString() const;

    enum enIsLeapYear
    {
        noLeap,
        isLeap
    };

    enIsLeapYear checkIfYearIsLeap(int year)
    {

        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? enIsLeapYear::isLeap : enIsLeapYear::noLeap;
    }

    int getMonthDaysInYear()
    {
        int numberOfDays[12] = {31, month == 2 && checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return numberOfDays[month - 1];
    }

    short calculateDayOfWeek(short dayOrder)
    {
        short a = (14 - month) / 12;
        short m = month + 12 * a - 2;

        short d = (dayOrder + year + year / 4 - year / 100 + year / 400 + ((31 * m) / 12)) % 7;

        return d;
    }

public:
    // constructor par default :
    cDate();

    //  parametrized constructor :
    cDate(int days, short month, short year);

    // copy constructor :
    cDate(const cDate &copy);

    // operator de saisir :
    friend istream &operator>>(istream &inp, cDate &date);

    // operator de affichage
    friend ostream &operator<<(ostream &out, const cDate &date);

    // operator de comparaison :
    friend bool operator>(const cDate &ob1, const cDate &ob2);
    friend bool operator<(const cDate &ob1, const cDate &ob2);
    friend bool operator==(const cDate &ob1, const cDate &ob2);
    friend bool operator>=(const cDate &ob1, const cDate &ob2);
    friend bool operator<=(const cDate &ob1, const cDate &ob2);

    static cDate getCurrentDate();
    // get current time info(str) :
    static string getCurrentTimeInfo();

    // set days :
    void setDays(const int &days);

    // get days :
    int getDays() const;

    void readDateFab()
    {
        bool isValidDate = false;
        do
        {

            days = input::readPositiveIntegerNumber("");
            month = input::readPositiveIntegerNumber("");
            year = input::readPositiveIntegerNumber("");
            isValidDate = days > 31 || days < 1 || month > 12 || month < 1

                          || *this > cDate::getCurrentDate();
            if (isValidDate)
                cout << "\n----[La date doit être inférieure ou égale à la date actuelle et valide : ] " << cDate::getCurrentTimeInfo() << "\n\nRentrer une autre fois [d/m/y] : ";

        } while (isValidDate);
    }
    void printMonthCalender()
    {
        string arrDays[] = {"Sunday", "Monday", "tuesday", "Wednesday", "Thursday", "Friday", "saturday"};
        string arrMonths[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        int daysInMonth = getMonthDaysInYear();
        int dayOrder = calculateDayOfWeek(1);

        cout << "\n\n_________________________________________" << arrMonths[month] << "_________________________________________\n\n";

        for (int i = 0; i <= 6; i++)
            cout << setw(12) << arrDays[i];
        cout << "\n";

        int i = 1;
        for (; i <= dayOrder; i++)
        {
            cout << right << setw(12) << "";
        }
        int dayCounter = 1;
        while (dayCounter <= daysInMonth)
        {

            cout << right << setw(12) << dayCounter++;
            if (i++ % 7 == 0)
                cout << "\n";
        }
        cout << "\n_______________________________________________________________________________________\n\n";
    }
    void printMonthCalender(int month)
    {
        string arrDays[] = {"Sunday", "Monday", "tuesday", "Wednesday", "Thursday", "Friday", "saturday"};
        string arrMonths[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        int daysInMonth = getMonthDaysInYear();
        int dayOrder = calculateDayOfWeek(1);

        cout << "\n_________________________________________" << arrMonths[month] << "_________________________________________\n\n";

        for (int i = 0; i <= 6; i++)
            cout << setw(12) << arrDays[i];
        cout << "\n";

        int i = 1;
        for (; i <= dayOrder; i++)
        {
            cout << right << setw(12) << "";
        }
        int dayCounter = 1;
        while (dayCounter <= daysInMonth)
        {

            cout << right << setw(12) << dayCounter++;
            if (i++ % 7 == 0)
                cout << "\n";
        }
        cout << "\n_______________________________________________________________________________________\n";
    }

    void printCalender()
    {
        cout << "\n_________________________________________________________________________________________\n";
        cout << "_____________________________________Calendar - " << year << "_____________________________________";
        cout << "\n\n_________________________________________________________________________________________";

        for (int month = 1; month <= 12; month++)
        {

            cout << "\n";
            printMonthCalender(month);
        }
    }
};

// /------------------- start cDate class -------------------------------------------

// convert from  cDate to string function  :
string cDate::getDateToString() const
{
    string stDay = to_string(days);
    string stMonth = to_string(month);
    string stYear = to_string(year);

    if (stDay.length() == 1)
        stDay = '0' + stDay;
    if (stMonth.length() == 1)
        stMonth = '0' + stMonth;

    return stDay + "/" + stMonth + "/" + stYear;
}

// constructor par default :
cDate::cDate()
{
    year = 0;
    month = 0;
    days = 0;
}

//  parametrized constructor :
cDate::cDate(int days, short month, short year)
{
    this->days = days;
    this->month = month;
    this->year = year;
}

// copy constructor :
cDate::cDate(const cDate &copy)
{
    this->days = copy.days;
    this->month = copy.month;
    this->year = copy.year;
}

// operator de saisir :
istream &operator>>(istream &inp, cDate &date)
{
    bool isValidDate = false;
    do
    {

        date.days = input::readPositiveIntegerNumber("", false);
        date.month = input::readPositiveIntegerNumber("", false);
        date.year = input::readPositiveIntegerNumber("", false);
        isValidDate = date.days > 31 || date.days < 1 || date.month > 12 || date.month < 1

                      || date < cDate::getCurrentDate();
        if (isValidDate)
            cout << "\n----[La date doit être supérieure ou égale à la date actuelle et valide : ] " << cDate::getCurrentTimeInfo() << "\n\nRentrer une autre fois [d/m/y] : ";

    } while (isValidDate);

    return inp;
}

// operator de affichage
ostream &operator<<(ostream &out, const cDate &date)
{

    cout << date.getDateToString() << endl;
    return out;
}

// operator de comparaison :
bool operator==(const cDate &ob1, const cDate &ob2)
{

    if (ob1.year == ob2.year)
    {
        if (ob1.month == ob2.month)
        {

            if (ob1.days == ob2.days)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

bool operator<(const cDate &ob1, const cDate &ob2)
{
    if (ob1.year <= ob2.year)
    {

        if (ob1.month <= ob2.month)
        {

            if (ob1.days < ob2.days)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
bool operator>(const cDate &ob1, const cDate &ob2)
{

    if (ob1.year >= ob2.year)
    {

        if (ob1.month >= ob2.month)
        {

            if (ob1.days > ob2.days)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
bool operator<=(const cDate &ob1, const cDate &ob2)
{

    if (ob1.year <= ob2.year)
    {

        if (ob1.month <= ob2.month)
        {

            if (ob1.days <= ob2.days)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

bool operator>=(const cDate &ob1, const cDate &ob2)
{

    if (ob1.year >= ob2.year)
    {

        if (ob1.month >= ob2.month)
        {

            if (ob1.days >= ob2.days)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

// get the current date function :
cDate cDate::getCurrentDate()
{
    cDate currentDate;
    // get the nombre of second from (January 1, 1970)  date
    time_t t1 = time(0);

    // convert it to a tm strucutre :
    tm *gm = gmtime(&t1);

    currentDate.days = gm->tm_mday;
    //  month of year from 0 to 11  (start from from 0 not 1 you need to add 1 in logging)
    currentDate.month = gm->tm_mon + 1;
    // year since 1900 (you need to add 1900 in logging)
    currentDate.year = 1900 + gm->tm_year;

    return currentDate;
}

// get current time info(str) :
string cDate::getCurrentTimeInfo()
{

    // get the nombre of second from (January 1, 1970)  date
    time_t t1 = time(0);
    // get current time info :
    string timeInfo(ctime(&t1));

    return timeInfo;
}

// set day  :
void cDate::setDays(const int &days)
{

    this->days = days;
}

// get days :
int cDate::getDays() const
{
    return this->days;
}