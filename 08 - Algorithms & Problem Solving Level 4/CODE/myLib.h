#include <iostream>
#include<string>
using namespace std;
namespace input
{

    long long int readIntegerNumber(string text="enter a  number")
    {

       long long  int Number;
        cout <<text;
        cin >> Number; cin.ignore(); 
  if(cin.fail()) throw   runtime_error("Invalid Type You Should Enter an Integer : ");
        
        return Number;
    }

   float readFloat(string text="enter a  float number  "){
        float num=0; 
       cout<<text;
       cin>>num;  cin.ignore(); 
        if(cin.fail()) throw   runtime_error("Invalid Type You Should Enter an Integer : ");
       return num; 
    }
    int readIntegerInRange(int min, int max,string text="enter a  number")
    {

        int number = 0;
        do
        {
            number = readIntegerNumber(text);
        } while (number < min || number > max);
        return number;
    }
    float readFloatInRange(int min, int max,string text="enter a  number")
    {

        float number = 0;
        do
        {
            number = readFloat(text);
        } while (number < min || number > max);
        return number;
    }
    int readPositiveIntegerNumber(string text="enter a positive number :")
    {

        int number = 0;
        do
        {
            number = readIntegerNumber(text);
        } while (number < 0);
        return number;
    }
    float readPositiveFloatNumber(string text="enter a positive number :")
    {

        float number = 0;
        do
        {
            number = readFloat(text);
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
    string readString(string text="enter a string ")
    {

        string Str;
        cout<<text; 
        getline(cin>>ws,Str);
        return Str;
    }
     char readCharacter(string text="enter a string ")
    {

        char character;
        cout<<text; 
        cin>>character;
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
   
}

namespace output
{

    void printIntegerResult(string text, int result)
    {

        cout << text << " " << result << endl;
    }

}

