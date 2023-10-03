#include <iostream>
#include <string>
using namespace std;

// lesson 32 
struct stAddress
{
    string city;
    string country;

    void getAddressInfo()
    {
        cout << "enter your city :";
        getline(cin >> ws, city);

        cout << "enter your country :";
        getline(cin >> ws, country);
    }
};

struct stUser
{
    string name;
    unsigned short age;
    stAddress Address;

    void GetUserINfo()
    {

        stUser User;
        cout << "enter your name : ";
        getline(cin >> ws, name);

        cout << "enter your age :";
        cin >> age;
        Address.getAddressInfo();
    }

    void PrintUserInfo()
    {

        cout << "\n--------------------------------"
             << "\n";
        cout << "Name    :" << name << "\n";
        cout << "Age     :" << age << "\n";
        cout << "City    :" << Address.city << "\n";
        cout << "country :" << Address.country << "\n";

        cout << "------------------------------"
             << "\n"
             << endl;
    }
};

void printSquare()
{
    cout << "************"
         << "\n";
    cout << "************"
         << "\n";
    cout << "************"
         << "\n";
    cout << "************"
         << "\n"
         << endl;
}

void printMyFeeling()
{

    cout << "I love programming "
         << "\n";
    cout << "I promise to be the best developer ever"
         << "\n";
    cout << "I know it will take some time to practice, but I will achieve my goal"
         << "\n\n";
    cout << "Best Regards"
         << "\n";
    cout << "Mohammed Abu-Hahdoud" << endl;
}


void printHCharacter()
{
    cout << "*               *" << endl;
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*****************" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n";
    cout << "*               *" <<"\n"<<endl;
}
int main()
{
    stUser User1;

    User1.GetUserINfo();
    User1.PrintUserInfo();
    printMyFeeling();
    printHCharacter();
    return 0;
}