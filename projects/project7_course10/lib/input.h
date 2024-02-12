#include <iostream>
#include <string>
#include<exception>
#include<limits>
using namespace std;
namespace input
{

  int readIntegerNumber(string text = "Enter a number: ", bool StrictMode=true) {
    int Number;
    bool renter = false;

    do {
        cout << text;
        try {
            renter = false;
            cin >> Number;
         if(StrictMode)  cin.ignore(numeric_limits<streamsize>::max(),'\n');
            else cin.ignore(); 
         
            if (cin.fail()) {
                throw runtime_error("Invalid Type. You should enter an integer.");
            }
        } catch (runtime_error &error) {
            // Clear flag error:
            cin.clear();
             fflush(stdin); 
            

            cout << "\nError: " << error.what() << endl;
            renter = true;
        }
    } while (renter);

    return Number;
}
    int readIntegerInRange(int min, int max, string text = "enter a  number")
    {

        int number = 0;
        do
        {
            number = readIntegerNumber(text);
        } while (number < min || number > max);
        return number;
    }
    int readPositiveIntegerNumber()
    {

        int number = 0;
        do
        {
            number = readIntegerNumber();
        } while (number < 0);
        return number;
    }
    int readNegativeIntegerNumber()
    {
        int number = 0;
        do
        {
            number = readIntegerNumber();
        } while (number > 0);
        return number;
    }
    string readString(string text = "enter a string ")
    {

        string Str;
        cout << text;
        getline(cin >> ws, Str);
        return Str;
    }
    char readCharacter(string text = "enter a string ")
    {

        char character;
        cout << text;
        cin >> character;
        return character;
    }

    string readStrWhileEqualValue(string Value)
    {

        string str = "";
        do
        {
            str = readString();
        } while (str == Value);

        return str;
    }
    float readFloat(string text = "Enter a Float number  : ", bool StrictMode=true) {
    float Number;
    bool renter = false;

    do {
        cout << text;
        try {
            renter = false;
            cin >> Number;
         if(StrictMode)  cin.ignore(numeric_limits<streamsize>::max(),'\n');
            else cin.ignore(); 
         
            if (cin.fail()) {
                throw runtime_error("Invalid Type. You should enter an integer.");
            }
        } catch (runtime_error &error) {
            // Clear flag error:
            cin.clear();
             fflush(stdin); 
            

            cout << "\nError: " << error.what() << endl;
            renter = true;
        }
    } while (renter);

    return Number;
}
}

namespace output
{

    void printIntegerResult(string text, int result)
    {

        cout << text << " " << result << endl;
    }

}
