#include <iostream>
#include <string>

#include <iomanip>

using namespace std;

// problem 41 :
/*
write a program to readd a numberOfHours and calculates the number of weeks,and days included in that number :
*/

int getHours()
{
    float hours;
    cout << "enter the number of hours  :";
    cin >> hours;
    if (cin.fail() || hours < 0)
        throw runtime_error("you should enter a positive digit : ");
    return hours;
}

void numberOfWeeksDays(float hours)
{
    cout << fixed << setprecision(2);
    float NbrDays = (hours / 24);
    float NbrWeeks = (NbrDays / 7);

    throw string("\nthe number of week is : " + to_string(NbrWeeks) + "\nthe number days is : " + to_string(NbrDays) + "\n");
}

int main()
{

    try
    {
        float hours = getHours();
        numberOfWeeksDays(hours);
    }
    catch (runtime_error e)
    {
        cin.clear();
        cin.ignore();
        cout << "Error :" << e.what() << endl;
    }
    catch (string result)
    {
        cout << result;
    }
    return 0;
}