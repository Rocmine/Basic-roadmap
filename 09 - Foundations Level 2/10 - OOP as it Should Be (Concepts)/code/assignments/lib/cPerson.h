#pragma once 
#include<iostream>
using namespace std ;
 class cPerson
{

    int id;
    string firstName;
    string lastName;
    string email;
    string phone;

public:
    // empty constructor :
    cPerson()
    {
        id = 0;
        firstName = "";
        lastName = "";
        email = "";
        phone = "";
    }
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
    void print(bool isBaseClass = true)
    {

        cout << "\n______________________________________\n";
        cout << "the id        : " << id << "\n";
        cout << "the firstName : " << firstName << "\n";
        cout << "the lastName  : " << lastName << "\n";
        cout << "the email     : " << email << "\n";
        cout << "the phone     : " << phone << endl;
        if (isBaseClass)
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
