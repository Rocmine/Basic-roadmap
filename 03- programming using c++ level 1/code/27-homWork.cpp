#include <iostream>
#include <string>
using namespace std;

// write a program using Array and Structures and Functions to do the following :
// lesson 48  :
struct stPerson
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};

void ReadPerson(stPerson &Person)
{
    cout << "enter your  First Name   :";
    getline(cin >> ws, Person.FirstName);

    cout << "enter your Last Name    : ";
    getline(cin >> ws, Person.LastName);

    cout << "Enter your age : ";
    cin >> Person.Age;

    cout << "Enter your phone number :";
    cin >> Person.Phone;
}

void PrintPerson(stPerson &Person)
{

    cout << "-----------------------------------\n";

    cout << " First name is  : " << Person.FirstName << "\n";
    cout << " Last name      : " << Person.LastName << "\n";
    cout << " Age            : " << Person.Age << "\n";
    cout << " Phone          : " << Person.Phone << "\n";

    cout << "-----------------------------------"
         << endl;
}

void ReadPersons(stPerson Persons[100], unsigned short &Length)
{

    cout << "How many Numbers do yo Wanna to enter?\n ";
    cin >> Length;
    cout << Length << endl;

    for (int i = 0; i < Length; i++)
    {
        system("cls");
        cout << "Person : [" << i + 1 << "]"
             << "\n";
        ReadPerson(Persons[i]);
    }
}

void PrintPersons(stPerson Persons[100], const unsigned short &Length)
{
    system("cls");
    for (int i = 0; i < Length; i++)
    {
        PrintPerson(Persons[i]);
    }
}

int main()
{

    stPerson Persons[100];
    unsigned short Length = 0;
    ReadPersons(Persons, Length);
    PrintPersons(Persons, Length);

    return 0;
}