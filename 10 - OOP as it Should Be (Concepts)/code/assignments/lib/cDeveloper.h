#pragma once 
#include<iostream>
using namespace std ;
#include "cEmployee.h"

class cDeveloper : public cEmployee
{
    string mainProgrammingLanguage;

public:
    cDeveloper(int id, string firstName, string lastName, string email, string phone, string title, string department, float salary, string mainProgrammingLanguage)
        : cEmployee(id, firstName, lastName, email, phone, title, department, salary)
    {

        this->mainProgrammingLanguage = mainProgrammingLanguage;
    }

    void print(bool isBaseClass = true)
    {
        cEmployee::print(false);
        cout << "the main programming language : " << mainProgrammingLanguage << "\n";
        if (isBaseClass)
            cout << "______________________________________\n";
    }

    // setters :
    void setMainProLang(string mainProgLang) { mainProgrammingLanguage = mainProgLang; }

    // getters  :
    string getMainProgLang() { return mainProgrammingLanguage; }
};