#pragma once 
#include<iostream>
using namespace std ;
#include "cPerson.h"
class cEmployee : public cPerson
{
    string title;
    string department;
    float salary;

public:
    void print(bool isBaseClass = true)
    {
        cPerson::print(false);
        cout << "the title      : " << title << "\n";
        cout << "the department : " << department << "\n";
        cout << "the salary     : " << salary << "\n";
        if (isBaseClass)
            cout << "______________________________________\n";
    }

    // setters :
    void setTitle(string title) { this->title = title; }
    void setDepartment(string department) { this->department = department; }
    void setSalary(float salary) { this->salary = salary; }

    // getters :
    string getTitle() { return title; }
    string getDepartment() { return department; }
    float getSalary() { return salary; }

    cEmployee(int id, string firstName, string lastName, string email, string phone, string title, string department, float salary)
        : cPerson(id, firstName, lastName, email, phone)
    {

        this->title = title;
        this->department = department;
        this->salary = salary;
    }
};
