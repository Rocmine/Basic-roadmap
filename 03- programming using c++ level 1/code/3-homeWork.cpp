

// are the following valid variable names  and why :
/*
age : valid
my-age : not valid special character
my_age : valid
_age   :valid
2x     :not valid begin by  2
x2     : valid
my name: not valid there is a space
myName : valid
#name  : special character
$name  : begin with special character
n@ame  : special character
int    : reserved  keyword
float  : reserved keyword

M
*/

#include <iostream>
using namespace std;

int main()
{

    string userName = "ayoub majid ";
     unsigned short age = 44;
    string city = "Rabat";
    string country = "Morocco";
    float monthlySalary = 50000;
    double yearlySalary = monthlySalary * 12;
    char gender = 'M';
    bool isMarried = true;

    cout << "------------------------------------------" << endl;
    cout << "Name :" << userName << "\n";
    cout << "City :" << city << "\n";
    cout << "Country :" << country << "\n";
    cout << "Monthly Salary :" << monthlySalary << "\n";
    cout << "yearly Salary :" << yearlySalary << "\n";
    cout << "Gender :" << gender << "\n";
    cout << "Married" << isMarried << "\n";
    cout << "------------------------------------------" << endl;

  int  num1 = 20, num2 = 30, num3 = 10;
    cout << num1 << "+\n";
    cout << num2 << "+\n";
    cout << num3 << "\n";
    cout << "_________________________\n";
    cout << "total" << num1 + num2 + num3 << endl;

     unsigned short initialAge = 25;
    cout << "\nafter 5 years you will be " << initialAge + 5 << "years old" << endl;

    return 0;
}