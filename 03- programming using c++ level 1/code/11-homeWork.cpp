#include <iostream>
using namespace std;

enum enColor
{
    Red,
    Green,
    Yellow,
    Blue
};
enum enGender
{
    Male,
    Female
};
enum enMaritalStatus
{
    Single,
    Married
};

struct stAddress
{
    string StreetName;
    string BuildingNo;
    string PoBox;
    string ZipCode;
};

struct stContactInfo
{
    string Phone;
    string email;
    stAddress Address;
};

struct stPerson
{

    string FirstName;
    string LastName;
    stContactInfo contactInfo;
    enMaritalStatus MaritalStatus;
    enGender Gender;
    enColor FavoriteColor;

    int printPersonFullName()
    {
        cout << "Name : " << this->FirstName << endl;
        cout << "Last Name :" << this->LastName << endl;
    }
};

int main()
{

    stPerson person1;

    person1.FirstName = "Ayoub";
    person1.LastName = "Majid";
    person1.contactInfo.email = "ayoub@gmail.com";
    person1.contactInfo.Phone = "23223423423";

    person1.contactInfo.Address.StreetName + "abo";
    person1.contactInfo.Address.PoBox = "12312";
    person1.contactInfo.Address.BuildingNo = "mafds";
    person1.contactInfo.Address.ZipCode = 12112;

    person1.Gender = enGender::Male;
    person1.MaritalStatus = enMaritalStatus::Single;

    person1.printPersonFullName();

    return 0;
}