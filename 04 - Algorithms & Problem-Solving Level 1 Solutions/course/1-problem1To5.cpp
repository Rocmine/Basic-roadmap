#include <iostream>
#include <string>
using namespace std;

// #1 print your Name on the screen : ---------------------[]
void PrintName(string Name)
{

    cout << "\nYour name is :" << Name << endl;
}
// #2  get Name and print it on the screen : ---------------------[]
string GetName()
{
    string Name = "";
    cout << "Enter your name : ";
    getline(cin >> ws, Name);
    return Name;
}

// #3 get Number and check if ood or even : ---------------------[]
int GetNumber()
{
    int Number = 0;
    cout << "enter a Number :";
    cin >> Number;
    return Number;
}
enum enNumberType
{
    Even = 0,
    Odd
};
bool CheckOddOrEven(int Number)
{

    return Number % 2 == enNumberType::Even ? enNumberType::Even : enNumberType::Odd;
}

// #4 get Age Driver License then if age > 21 and has a driver license print Hired else print Rejected : ---------------------[]

enum enHasLicence
{
    no,
    yes
};
struct stUser
{
    unsigned short Age;
    enHasLicence HasLicence;
};

void ReadUserInfo(stUser &User)
{

    cout << "Enter your Age :";
    cin >> User.Age;

    bool TempHasLicence = 0;
    cout << " do you have a Licence :  ( 0:No, 1:yes ) ";
    cin >> TempHasLicence;

    User.HasLicence = enHasLicence(TempHasLicence);
}

void PrintIUserJobStat(const stUser User)
{

    (User.Age >= 21 && User.HasLicence == enHasLicence::yes) ? cout << "Hired" : cout << "Rejected";
}

// #5 the same of #4 but just  if the user has a  Recommendation it will reject without checking anything else 😂
int main()
{

    // //#1-----------------------------[-]
    // PrintName("Ayoub");

    // //#2-----------------------------[-]
    // PrintName(GetName());

    // //#3-----------------------------[-]
    //  cout<<(CheckOddOrEven(GetNumber())==enNumberType::Even ? "even":"odd")<<endl;

    // #4-----------------------------[-]
    stUser User;
    ReadUserInfo(User);
    PrintIUserJobStat(User);

    return 0;
}
