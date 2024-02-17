#pragma once
#include <iostream>
#include <iomanip>
#include "./cInput.h"
#include "./cUtil.h"
#include <cmath>
using namespace std;

enum enIsLeapYear
{
    noLeap,
    isLeap
};
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
class cDate;
class cValidate
{

public:
    static bool IsEndOfTheWeek(cDate date);
    static bool IsWeekEnd(cDate date);
    static bool isBusinessDay(cDate date);
    static bool checkIfValidDay(cDate date);
    static bool isAValidDate(cDate date);
    static bool isAValidDateNow(cDate date);
    static enIsLeapYear checkIfYearIsLeap(int year);
    static bool checkIfLastDaysInMonth(cDate date);
    static bool checkIfLastMonthInYear(int month);
};
class cDate
{
private:
    short days;
    short month;
    int year;

    // convert from  cDate to string function  :
    string getDateToString() const;

    static int getMonthDaysInYear(short year, short month)
    {
        int numberOfDays[] = {0, 31, cValidate::checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return numberOfDays[month];
    }

    int getMonthDaysInYear() const
    {
        return getMonthDaysInYear(year, month);
    }

    short calculateDayOfWeek(short dayOrder) const
    {
        short a = (14 - month) / 12;
        short m = month + 12 * a - 2;

        short d = (dayOrder + year + year / 4 - year / 100 + year / 400 + ((31 * m) / 12)) % 7;

        return d;
    }

    bool checkIfLastDaysInMonth() const
    {
        return cValidate::checkIfLastDaysInMonth(*this);
    }

    bool checkIfLastMonthInYear() const
    {
        return cValidate::checkIfLastMonthInYear(month);
    }

    bool checkIfValidDay() const
    {

        return cValidate::checkIfValidDay(*this);
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
    friend bool operator!=(const cDate &ob1, const cDate &ob2);

    static cDate getCurrentDate();
    // get current time info(str) :
    static string getCurrentTimeInfo();

    // set days :
    void setDays(const int &days);

    // get days :
    int getDays() const;

    void readDateNow()
    {
        bool isValidDate = false;
        do
        {

            days = cInput::readPositiveIntegerNumber("", false);
            month = cInput::readPositiveIntegerNumber("", false);
            year = cInput::readPositiveIntegerNumber("", false);
            isValidDate = cValidate::isAValidDateNow(*this);
            if (!isValidDate)
                cout << "----[the Date should be grater than or equal current Date : ] " << cDate::getCurrentTimeInfo() << "Rentrer une autre fois [d/m/y] : ";

        } while (!isValidDate);
    }

    void printMonthCalender() const
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
    void printMonthCalender(int month) const
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

    void printCalender() const
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

    static int getNbrDaysFromDate(cDate date)
    {

        short days = 0;
        for (int i = 1; i < date.month; i++)
        {

            days += getMonthDaysInYear(date.year, i);
        }

        days += date.days;

        return days;
    }

    static int yearToDays(int year)
    {

        return cValidate::checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 366 : 365;
    }

    static float getAvgDaysBetweenTwoYear(int year1, int year2)
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
    static float getDiffDaysFromTwoDate(cDate date1, cDate date2, bool includeToDay = false)
    {

        float nbrDays = abs(round((date2.year - date1.year) * getAvgDaysBetweenTwoYear(date2.year, date1.year)) + getNbrDaysFromDate(date2) - getNbrDaysFromDate(date1));
        return includeToDay ? ++nbrDays : nbrDays;
    }
    static float getAgeDaysFromBirth(cDate birthDate)
    {

        return getDiffDaysFromTwoDate(birthDate, getCurrentDate(), true);
    }
    static string getFormalAgeFromBirthDate(cDate birthDate)
    {

        float nbrDays = getAgeDaysFromBirth(birthDate);
        float avgYearsDays = getAvgDaysBetweenTwoYear(birthDate.year, getCurrentDate().year);

        cDate age;
        float years = nbrDays / avgYearsDays;
        cout << (years - (int)years) << endl;
        float month = (years - (int)years) * 12;
        float days = (month - int(month)) * 30;

        return (to_string(int(years)) + " Years ," + to_string(int(month)) + " Months , " + to_string(int(days)) + " Days");
    }
    static void increaseDateByOneDay(cDate &date)
    {

        if (cValidate::checkIfLastDaysInMonth(date))
        {

            if (cValidate::checkIfLastMonthInYear(date.month))
            {
                date.year++;
                date.days = 1;
                date.month = 1;
            }
            else
            {
                date.month++;
                date.days = 1;
            }
        }
        else
        {

            date.days++;
        }
    }
    void increaseDateByOneDay()
    {
        increaseDateByOneDay(*this);
    }
    // postfix increment :
    cDate operator++(int)
    {
        cDate temp = *this;
        increaseDateByOneDay(*this);
        return temp;
    }

    // prefix increment :
    cDate operator++()
    {
        increaseDateByOneDay(*this);
        return *this;
    }

    static void increaseDaysByXDays(cDate &date, int nbrDays)
    {

        for (int i = 0; i < nbrDays; i++)
        {

            increaseDateByOneDay(date);
        }
    }
    void increaseDaysByXDays(int nbrDays = 0)
    {
        increaseDaysByXDays(*this, nbrDays);
    }
    static void increaseDaysByOneWeek(cDate &date)
    {

        increaseDaysByXDays(date, 7);
    }
    void increaseDaysByOneWeek()
    {
        increaseDaysByOneWeek(*this);
    }

    static void increaseDaysByXWeeks(cDate &date, int nbrWeeks)
    {
        for (int i = 0; i < nbrWeeks; i++)
        {
            increaseDaysByOneWeek(date);
        }
    }
    void increaseDaysByXWeeks(int nbrWeeks)
    {
        increaseDaysByXWeeks(*this, nbrWeeks);
    }

    static void increaseDaysByOneMonth(cDate &date)
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
        if (date.days > nbrDaysInMonth)
            date.days = nbrDaysInMonth;
    }
    void increaseDaysByOneMonth()
    {
        increaseDaysByOneMonth(*this);
    }

    static void increaseDaysByXMonths(cDate &date, int nbrMonths)
    {

        for (int i = 0; i < nbrMonths; i++)
        {

            increaseDaysByOneMonth(date);
        }
    }
    void increaseDaysByXMonths(int nbrMonths)
    {

        increaseDaysByXMonths(*this, nbrMonths);
    }

    static void increaseDaysByOneYear(cDate &date)
    {

        date.year++;
    }
    void increaseDaysByOneYear()
    {
        increaseDaysByOneYear(*this);
    }

    static void increaseDaysByXYears(cDate &date, int nbrYears)
    {

        for (int i = 0; i < nbrYears; i++)
        {

            increaseDaysByOneYear(date);
        }
    }
    void increaseDaysByXYears(int nbrYears)
    {
        increaseDaysByXYears(*this, nbrYears);
    }

    static void decreaseDateByOneDay(cDate &date)
    {

        if (date.days == 1)
        {

            if (date.month == 1)
            {
                date.year--;
                date.days = 31;
                date.month = 12;
            }
            else
            {
                date.month--;
                date.days = getMonthDaysInYear(date.year, date.month);
            }
        }
        else
        {

            date.days--;
        }
    }
    // prefix decrement  :
    cDate operator--()
    {
        decreaseDateByOneDay(*this);
        return *this;
    }
    // postfix decrement  :
    cDate operator--(int)
    {
        cDate temp = *this;
        decreaseDateByOneDay(*this);
        return temp;
    }

    static void decreaseDaysByXDays(cDate &date, int nbrDays)
    {

        for (int i = 0; i < nbrDays; i++)
        {

            decreaseDateByOneDay(date);
        }
    }
    void decreaseDaysByXDays(int nbrDays)
    {
        decreaseDaysByXDays(*this, nbrDays);
    }
    static void decreaseDaysByOneWeek(cDate &date)
    {

        decreaseDaysByXDays(date, 7);
    }
    void decreaseDaysByOneWeek()
    {
        decreaseDaysByOneWeek(*this);
    }

    static void decreaseDaysByXWeeks(cDate &date, int nbrWeeks)
    {
        for (int i = 0; i < nbrWeeks; i++)
        {
            decreaseDaysByOneWeek(date);
        }
    }
    void decreaseDaysByXWeeks(int nbrWeeks)
    {
        decreaseDaysByXWeeks(*this, nbrWeeks);
    }
    static void decreaseDaysByOneMonth(cDate &date)
    {

        if (date.month == 1)
        {
            date.month = 12;
            date.year--;
        }
        else
        {
            date.month--;
        }

        int nbrDaysInMonth = getMonthDaysInYear(date.year, date.month);
        if (date.days > nbrDaysInMonth)
            date.days = nbrDaysInMonth;
    }
    void decreaseDaysByOneMonth()
    {
        decreaseDaysByOneMonth(*this);
    }

    static void decreaseDaysByXMonths(cDate &date, int nbrMonths)
    {

        for (int i = 0; i < nbrMonths; i++)
        {

            decreaseDaysByOneMonth(date);
        }
    }
    void decreaseDaysByXMonths(int nbrMonths)
    {

        decreaseDaysByXMonths(*this, nbrMonths);
    }

    static void decreaseDaysByOneYear(cDate &date)
    {

        date.year--;
    }
    void decreaseDaysByOneYear()
    {
        decreaseDaysByOneYear(*this);
    }
    void decreaseDaysByXYears(cDate &date, int nbrYears)
    {

        for (int i = 0; i < nbrYears; i++)
        {

            decreaseDaysByOneYear(date);
        }
    }
    void decreaseDaysByXYears(int nbrYears)
    {
        decreaseDaysByXYears(*this, nbrYears);
    }

    static short getToDayOrderInWeek(cDate date)
    {
        int d = date.days;
        int m = date.month;
        int y = date.year;

        // Adjust the month and year for January and February
        if (m < 3)
        {
            m += 12;
            y -= 1;
        }

        int K = y % 100;
        int J = y / 100;

        // Zeller's Congruence algorithm to calculate the day of the week
        int h = (d + ((13 * (m + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

        // Convert to DayOfWeek enum
        return static_cast<enDayOrder>((h + 6) % 7); // Adjusting for Sunday as the first day
    }
    short getToDayOrderInWeek()
    {
        return getToDayOrderInWeek(*this);
    }

    static string getDayName(cDate date)
    {
        const char *dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return dayNames[getToDayOrderInWeek(date)];
    }
    string getDayName()
    {
        return getDayName(*this);
    }
    static short getDaysUntilEndOfWeek(cDate date)
    {

        enDayOrder dayOrder = enDayOrder(getToDayOrderInWeek(date));
        return enDayOrder::sat - dayOrder;
    }
    short getDaysUntilEndOfWeek() const
    {
        return getDaysUntilEndOfWeek(*this);
    }
    static short getDaysUntilEndOfMonth(cDate date)
    {

        return getMonthDaysInYear(date.year, date.month) - date.days;
    }
    short getDaysUntilEndOfMonth() const
    {
        return getDaysUntilEndOfMonth(*this);
    }
    static short getDaysUntilEndOfYear(cDate date)
    {

        cDate finalDate;
        finalDate.year = date.year;
        finalDate.month = 12;
        finalDate.days = 31;
        return getDiffDaysFromTwoDate(date, finalDate);
    }
    short getDaysUntilEndOfYear() const
    {
        return getDaysUntilEndOfYear(*this);
    }
    static int GetNumberOfVacationDaysFromTwoDate(cDate dateStart, cDate dateEnd)
    {

        int numberOfVacationDays = 0;
        int diffDays = getDiffDaysFromTwoDate(dateStart, dateEnd);

        for (int i = 0; i < diffDays; i++)
        {

            if (!cValidate::IsWeekEnd(dateStart))
            {
                numberOfVacationDays++;
            }

            increaseDateByOneDay(dateStart);
        }

        return numberOfVacationDays;
    }

    static cDate convertStringToDate(string strDate)
    {

        cDate date;

        vector<string> vDate = cUtile::getSplitStringWordToVector(strDate);
        date.days = stoi(vDate[0]);
        date.month = stoi(vDate[1]);
        date.year = stoi(vDate[2]);

        if (!cValidate::isAValidDate(date))
        {
            date.days = 0;
            date.month = 0;
            date.year = 0;
        }
        return date;
    }
    friend class cValidate;
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
    year = 1;
    month = 1;
    days = 1;
}

//  parametrized constructor :
cDate::cDate(int days, short month, short year)
{

    this->days = days;
    this->month = month;
    this->year = year;

    if (!cValidate::isAValidDate(*this))
    {
        this->days = 1;
        this->month = 1;
        this->year = 1;
    }
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

        date.days = cInput::readPositiveIntegerNumber("", false, "Invalid Date Retry Again [dd/mm/yyyy] : ");
        date.month = cInput::readPositiveIntegerNumber("", false);
        date.year = cInput::readPositiveIntegerNumber("", false);
        isValidDate = !date.checkIfValidDay() || date.days < 1 || date.month > 12 || date.month < 1;

        if (isValidDate)
            cout << "Invalid Date Retry Again [dd/mm/yyyy] :  ";

    } while (isValidDate);

    return inp;
}

// operator de affichage
ostream &operator<<(ostream &out, const cDate &date)
{

    cout << date.getDateToString();
    return out;
}

// operator de comparaison :
bool operator==(const cDate &ob1, const cDate &ob2)
{
 return ob1.year==ob2.year && ob1.month == ob2.month && ob1.days==ob2.days; 
}
bool operator!=(const cDate &ob1, const cDate &ob2)
{
 return !(ob1 ==ob2);
}

bool operator<(const cDate &ob1, const cDate &ob2)
{
    if (ob1.year < ob2.year)
        return true;
    if (ob1.year == ob2.year)
    {
        if (ob1.month < ob2.month) return true;

        if (ob1.month == ob2.month)
        {
            if (ob1.days < ob2.days)
                return true;
        }
    }
    return false;
}

bool operator>(const cDate &ob1, const cDate &ob2)
{
    if (ob1.year > ob2.year)
        return true;
     if (ob1.year == ob2.year)
    {
        if (ob1.month > ob2.month)  return true;
      if (ob1.month == ob2.month)
        {
            if (ob1.days > ob2.days)
                return true;
        }
    }
    return false;
}

bool operator>=(const cDate &ob1, const cDate &ob2)
{
    return !(ob1 < ob2);
}

bool operator<=(const cDate &ob1, const cDate &ob2)
{
    return !(ob1 > ob2);
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
    int temp = this->days;
    this->days = days;
    if (!cValidate::checkIfValidDay(*this))
    {

        this->days = temp;
    }
}

// get days :
int cDate::getDays() const
{
    return this->days;
}

bool cValidate::IsEndOfTheWeek(cDate date)
{
    enDayOrder dayOrder = enDayOrder(cDate::getToDayOrderInWeek(date));
    return dayOrder == enDayOrder::sat;
}

bool cValidate::IsWeekEnd(cDate date)
{

    enDayOrder dayOrder = enDayOrder(cDate::getToDayOrderInWeek(date));

    return dayOrder == enDayOrder::fri || dayOrder == enDayOrder::sat;
}

bool cValidate::isBusinessDay(cDate date)
{

    enDayOrder dayOrder = enDayOrder(cDate::getToDayOrderInWeek(date));

    return !IsWeekEnd(date);
}
bool cValidate::checkIfValidDay(cDate date)
{

    return date.getDays() <= cDate::getMonthDaysInYear(date.year, date.month) && date.getDays() > 0;
}
bool cValidate::isAValidDate(cDate date)
{

    return ((checkIfValidDay(date)) && (date.month <= 12 && date.month >= 1));
}
bool cValidate::isAValidDateNow(cDate date)
{

    return isAValidDate(date) && date >= cDate::getCurrentDate();
}
enIsLeapYear cValidate::checkIfYearIsLeap(int year)
{

    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? enIsLeapYear::isLeap : enIsLeapYear::noLeap;
}
bool cValidate::checkIfLastDaysInMonth(cDate date)
{
    return date.days == cDate::getMonthDaysInYear(date.year, date.month);
}
bool cValidate::checkIfLastMonthInYear(int month)
{

    return month == 12;
}