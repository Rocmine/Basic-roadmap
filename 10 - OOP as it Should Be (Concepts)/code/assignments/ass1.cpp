#include <iostream>
using namespace std;

class cPerson
{

    int id;
    string firstName;
    string lastName;
    string email;
    string phone;

public:
    // parametrized constructor :
    cPerson(int id, string firstName, string lastName, string email, string phone)
    {

        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->phone = phone;
    }

    // print function :
    void print()
    {

        cout << "\n______________________________________\n";
        cout << "the id        : " << id << "\n";
        cout << "the firstName : " << firstName << "\n";
        cout << "the lastName  : " << lastName << "\n";
        cout << "the email     : " << email << "\n";
        cout << "the phone     : " << phone << endl;
        cout << "______________________________________\n";
    }

    void sendEmail(string subject, string body)
    {
        cout << "\nThe following message sent successfully to email:" << email << "\n";
        cout << "subject : " << subject << "\n";
        cout << "boyd : " << body << "\n";
    }

    void sendSms(string sms)
    {
        cout << "\nThe following SMS sent successfully to phone:" << phone << "\n";
        cout << sms << "\n";
    }
};

int main()
{
    cPerson p1(10, "ayoub", "majid", "majid@gmail.com", "077144");
    p1.print();
    p1.sendEmail("hi", "how are you?");
    p1.sendSms("how are you?");

    return 0;
}