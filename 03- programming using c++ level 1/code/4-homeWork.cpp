#include <iostream>
using namespace std;

int main()
{

    string userName = "";
  unsigned short age = 0;
    string city = "no city ";
    string country = "no country ";
    float monthlySalary = 0;
    float yearlySalary = monthlySalary * 12;
    char gender = 'N'; // N means not  one :
    bool isMarried = false;

    // get user informations :
    cout << "_________________________________" << endl;
    cout << "enter you name : ";
    cin >> userName;
    cout << "enter you city :";
    cin >> city;
    cout << "enter you monthly salary :";
    cin >> monthlySalary;
    cout << "enter your gender :";
    cin >> gender;
    cout << "enter your stat : (married => 1 or  single => 0 )";
    cin >> isMarried;

    // print user informations :
    cout << "------------------------------------------" << endl;
    cout << "Name :" << userName << "\n";
    cout << "City :" << city << "\n";
    cout << "Country :" << country << "\n";
    cout << "Monthly Salary :" << monthlySalary << "\n";
    cout << "yearly Salary :" << yearlySalary << "\n";
    cout << "Gender :" << gender << "\n";
    cout << "Married" << isMarried << "\n";
    cout << "------------------------------------------" << endl;

    // pause then clear the screen for next assignment  :
    system("pause");
    system("cls");

    // assignment 2 :
 long long  int num1 = 0, num2 = 0, num3 = 0;
    // get numbers values :
    cout << "enter three numbers :";
    cin >> num1 >> num2 >> num3;

    // print numbers :
    cout << num1 << "+\n";
    cout << num2 << "+\n";
    cout << num3 << "\n";
    cout << "_________________________\n";
    cout << "total" << num1 + num2 + num3 << endl;

    // pause then clear the screen for next assignment  :
    system("pause");
    system("cls");

    // assignment 3 :
    short   initialAge = 0;
    // get age :
    cout << "enter your age :";
    cin >> initialAge;

    cout << "\nafter 5 years you will be " << initialAge + 5 << " years old" << endl;

    return 0;
}