#include <iostream>
using namespace std;

enum enWeekDay
{
    son = 1,
    Mon,
    Tues,
    Wed,
    Thu,
    Fri,
    Sat
};
string arrWeekDay[] = {"", "sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void ShowMenu()
{

    cout << "_______________________\n";
    cout << "(1) Sunday\n";
    cout << "(2) Monday\n";
    cout << "(3) Tuesday\n";
    cout << "(4) Wednesday\n";
    cout << "(5) Thursday\n";
    cout << "(6) Friday\n";
    cout << "(7) Saturday\n";
    cout << "Your Choice?" << endl;
}

enWeekDay ReadUserDay()
{
    unsigned short UserDay;
    cin >> UserDay;
    return enWeekDay(UserDay);
}
string GetWeekDayName(enWeekDay UserDay)
{

    if (UserDay < enWeekDay::son || UserDay > enWeekDay::Sat)
    {
        cout << "Invalid Day value ";
        exit(1);
    }

    return arrWeekDay[UserDay];
}

int main()
{
    ShowMenu();

    cout << "Today is " << GetWeekDayName(ReadUserDay()) << endl;

    return 0;
}