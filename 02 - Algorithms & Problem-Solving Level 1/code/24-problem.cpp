// problem  24 :

/*
write a program to ask the user to enter age 
if age id between 18 and 45 print "valid age "  otherwise print "invalid age "
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

void isValidAge(int age)
{

    if (age >= 18 && age < 45)
        throw string("valid age :");

    else
        throw string("invalid age");
}

int main()
{

    try
    {
        int age = getAge();
        isValidAge(age);
    }
    catch (runtime_error e)
    {
        cout << "Error " << e.what() << endl;
    }
    catch (string msg)
    {

        cout << msg << endl;
    }

    return 0;
}