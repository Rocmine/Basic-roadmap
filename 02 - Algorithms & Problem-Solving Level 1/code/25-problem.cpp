// problem  25 :

/*
write a program to ask the user to enter age
if age is between 18 and 45 print "valid age "  otherwise print "invalid age " and re-ask to enter a valid age :
*/
#include <iostream>

using namespace std;

int getAge()
{
    int age;

    cout << "entre your age :";
    cin >> age;
    if (cin.fail())
        throw runtime_error("  you should entre a digit");
    return age;
}

bool isNotValidAge(int age)
{

    if (age >= 18 && age <= 45)
        throw string("valid age");

    return 1;
}

int main()
{

    try
    {
        int age = 0;
        bool stat = false;
        do
        {

            age = getAge();
            system("cls");
            stat = isNotValidAge(age);
            if (stat)
                cout << "invalid age :" << endl;

        } while (stat);
    }
    catch (runtime_error e)
    {
        system("cls");
        cout << "Error " << e.what() << endl;
    }
    catch (string msg)
    {

        cout << msg << endl;
    }

    return 0;
}