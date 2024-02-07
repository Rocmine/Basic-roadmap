#include <iostream>
using namespace std;

/*
 Employee
ID

First name
Last name
FullName()
Title
Email
Phone
Salary
Department
SendEmail(..)
SendSMS(...)
Print()
*/
class cEmployee
{

    int id;
    string firstName;
    string lastName;
    string title; 
    string email;
    string phone;
    string department;
    float salary;  

public:
    // empty constructor :

    cEmployee()
    {
        id = 0;
        firstName = "";
        lastName = "";
        title=""; 
        email = "";
        phone = "";
        department="";
        salary=0; 
    }
    // parametrized constructor :
    cEmployee(int id, string firstName, string lastName ,string title, string email, string phone, string department , float salary)
    {

        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->title=title; 
        this->email = email;
        this->phone = phone;
        this->department=department;
        this->salary=salary; 
    }

    // print function :
    void print()
    {

        cout << "\n______________________________________\n";
        cout << "the id         : " << id << "\n";
        cout << "the firstName  : " << firstName << "\n";
        cout << "the lastName   : " << lastName << "\n";
        cout<<"the title        :"<<title<<"\n"; 
        cout << "the email      : " << email << "\n";
        cout << "the phone      : " << phone <<"\n";
        cout << "the department :    : " << department << "\n";
        cout << "the salary     : " << salary <<endl;
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

    // getters

    int getId() { return id; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    string getEmail() { return email; }
    string getPhone() { return phone; }

    // setters :
    void setFirstName(string firstName) { this->firstName = firstName; }
    void setLastName(string lastName) { this->lastName = lastName; }
    void setEmail(string email) { this->email = email; }
    void setPhone(string phone) { this->phone = phone; }
};

int main()
{
    cEmployee em(10, "ayoub", "majid","software engineer", "majid@gmail.com", "077144","22A",500.4);
    em.print();
    em.sendEmail("hi", "how are you?");
    em.sendSms("how are you?");

    return 0;
}

