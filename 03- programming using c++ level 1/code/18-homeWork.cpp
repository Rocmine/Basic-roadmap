#include <iostream>
#include <string>
using namespace std;
// lesson 38
struct strPerson
{
    string FirstName;
    string LastName;
    unsigned short Age;
    string Phone;

    void GetInfo();
    void PrintInfo();
};

int main()
{
    strPerson Person1;
    Person1.GetInfo();
    Person1.PrintInfo();
}

void strPerson::GetInfo()
{

    cout << "Enter  your First Name  :";
    getline(cin >> ws, FirstName);

    cout << "Enter your Last Name    :";
    getline(cin >> ws, LastName);

    cout << "enter your Age          :";
    cin >> Age;

    cout << "enter your Phone        :";
    getline(cin >> ws, Phone);
}

void strPerson::PrintInfo()
{

    cout << "--------------------------------------\n";

    cout << "Your First Name is    :" << FirstName << "\n";
    cout << "Your Last Name is     :" << LastName << "\n";
    cout << "Your Age is           :" << Age << "\n";
    cout << "Your Phone is         :" << Phone << "\n";

    cout << "--------------------------------------" << endl;
}
