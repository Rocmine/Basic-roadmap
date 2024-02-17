#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <limits>

using namespace std;

class cInput
{

public:
    static int readIntegerNumber(string text = "Enter a number : ", bool StrictMode = true,string errorMsg="Invalid Type. You should enter an integer : ") 
    {
        int Number;
        bool renter = false;

        do
        {
         
            try
            {
                renter = false;
                 cout << text;
                cin >> Number;
                if (StrictMode)
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                else
                    cin.ignore();

                if (cin.fail())
                {
                    throw runtime_error(errorMsg);
                } 
            }
            catch (runtime_error &error)
            {
                // Clear flag error:
                cin.clear();
                fflush(stdin);

                cout << "Error: " << error.what()<< endl;
             
                renter = true;
            }
        } while (renter);

        return Number;
    }
    static float readFloat(string text = "Enter a Float number : ", bool StrictMode = true)
    {
        float Number;
        bool renter = false;

        do
        {
            cout << text;
            try
            {
                renter = false;
                cin >> Number;
                if (StrictMode)
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                else
                    cin.ignore();

                if (cin.fail())
                {
                    throw runtime_error("Invalid Type. You should enter an integer.");
                }
            }
            catch (runtime_error &error)
            {
                // Clear flag error:
                cin.clear();
                fflush(stdin);

                cout << "Error: " << error.what() << endl;
                renter = true;
            }
        } while (renter);

        return Number;
    }

    static int readIntegerInRange(int min, int max, string text = "Enter a Number :")
    {

        int number = 0;
        do
        {
            number = readIntegerNumber(text);
        } while (number < min || number > max);
        return number;
    }

    static int readPositiveIntegerNumber(string text = "Enter A Positive Number : ", bool strictMode = true, string errorMsg="")
    {

        int number = 0;
        do
        {
            number = readIntegerNumber(text, strictMode,errorMsg);
        } while (number < 0);
        return number;
    }

    static int readNegativeIntegerNumber(string text = "Enter A Negative Number : ", bool strictMode = true)
    {
        int number = 0;
        do
        {
            number = readIntegerNumber(text, strictMode);
        } while (number >=0);
        return number;
    }

    static string readString(string text = "enter a string ")
    {

        string Str;
        cout << text;
        getline(cin >> ws, Str);
        return Str;
    }

    static char readCharacter(string text = "enter a string ")
    {

        char character;
        cout << text;
        cin >> character;
        return character;
    }
    static string readStrWhileEqualValue(string Value)
    {

        string str = "";
        do
        {
            str = readString();
        } while (str == Value);

        return str;
    }
};