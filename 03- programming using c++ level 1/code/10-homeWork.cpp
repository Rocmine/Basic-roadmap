#include <iostream>
using namespace std;

enum Color
{
    Red,
    Green,
    Yellow,
    Blue
};
enum Direction
{
    North,
    South,
    East,
    West
};
enum Week
{
    sat,
    Sun,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri
};
enum Gender
{
    Male,
    Female
};
enum Status
{
    Single,
    Married
};

struct ContactInfo
{

    string Email;
    string PhoneNumber;
};

struct Address
{
    string City;
    string Country;
    string strict;
    short postalCode;
};
struct SalaryInfo
{
    float MonthlySalary;
    float YearlySalary;
};

struct SocialStat
{
    Gender Gender;
    Status isMarried;
};
struct User
{
    string Name;
    unsigned short Age;
    SocialStat SocialStat;
    Address UserAddress;
    ContactInfo contacts;
    SalaryInfo AllSalary;
};

int main()
{

    User ob1;
    ob1.Name = "ayoub";
    ob1.Age = 19;

    ob1.SocialStat.Gender = Gender::Male;
    ob1.SocialStat.isMarried = Status::Married;

    ob1.UserAddress.City = "rabat";
    ob1.UserAddress.Country = "morocco";
    ob1.UserAddress.postalCode = 11233;
    ob1.UserAddress.strict = "amal 2";

    ob1.contacts.Email = "ayoubmajid71@gmal.com";
    ob1.contacts.PhoneNumber = "06641343432";

    ob1.AllSalary.MonthlySalary = 5000;
    ob1.AllSalary.YearlySalary = ob1.AllSalary.MonthlySalary * 12;

    cout << "------------User----------------" << endl;
    cout << "basic informations  :\n";
    cout << " Name            :  " << ob1.Name << "\n";
    cout << " Age             :  " << ob1.Age << "\n\n";

    cout << "address informations :\n";
    cout << " City            :  " << ob1.UserAddress.City << "\n";
    cout << " country         :  " << ob1.UserAddress.Country << "\n";
    cout << " strict          :  " << ob1.UserAddress.strict << "\n";
    cout << " postal code     :  " << ob1.UserAddress.postalCode << "\n\n";

    cout << "contacts informations :\n";
    cout << " email           :  " << ob1.contacts.Email << "\n";
    cout << " phone           :  " << ob1.contacts.PhoneNumber << "\n\n";

    cout << "salary informations  :\n";
    cout << " monthly salary  : " << ob1.AllSalary.MonthlySalary << "\n";
    cout << " yearly salary   :  " << ob1.AllSalary.YearlySalary << "\n";

    cout << "social Status :\n";
    cout << " Gender            :" << (ob1.SocialStat.Gender == Gender::Male ? "Male" : "Female") << "\n";
    cout << " Status            :" << (ob1.SocialStat.isMarried == Status::Married ? "Married" : "single") << "\n";

    cout << "----------------------------------" << endl;

    return 0;
}
