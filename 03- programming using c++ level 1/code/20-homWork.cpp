#include <iostream>
#include <string>
using namespace std;

// write a program using Array and Structures and Functions to do the following :
// lesson 41  :
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

void ReadPersons(stPerson Persons[2])
{

    ReadPerson(Persons[0]);
    system("cls");
    ReadPerson(Persons[1]);
}

void PrintPersons(stPerson Persons[2])
{

    PrintPerson(Persons[0]);
    PrintPerson(Persons[1]);
}

int main()
{

    stPerson Persons[2];
    ReadPersons(Persons);
    PrintPersons(Persons);

    return 0;
}