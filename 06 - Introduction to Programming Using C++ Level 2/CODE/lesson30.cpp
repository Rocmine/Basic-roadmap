#include <iostream>
#include "test/myLib.h"
#include <vector>
#include <iomanip>
using namespace std;

struct stEmployee
{
    string firstName;
    string lastName;
    float salary;
};

enum enUserDecide
{
    no,
    yes
};

stEmployee getEmployee()
{

    stEmployee tempEmployees;

    tempEmployees.firstName = input::readString("enter the first name :");
    tempEmployees.lastName = input::readString("enter the last name :");
    tempEmployees.salary = input::readFloat("enter the salary :");
    return tempEmployees;
}
void readVectorValuesUntilUserTellNo(vector<stEmployee> &VEmployee)
{

    string arrUserDecide[] = {"no", "yes"};
    string userDecide = "";

    do
    {
        
        VEmployee.push_back(getEmployee());
        userDecide = input::readString("if  you want continue enter [yes] otherwise enter [no] ");

    } while (userDecide == arrUserDecide[enUserDecide::yes]);
}

void printVector(vector<stEmployee> &vEmployees)
{
    for (stEmployee &employee : vEmployees)
    {

        cout << "\n";

        cout << "First Name : " << employee.firstName << "\n";
        cout << "Last Name : " << employee.lastName << "\n";
        cout << "salary : " << fixed << setprecision(2) << employee.salary << "\n";

        cout << "\n";
    }
}

int main()
{

   vector <stEmployee> vEmployees; 
   readVectorValuesUntilUserTellNo(vEmployees); 
   printVector(vEmployees); 

    return 0;
}