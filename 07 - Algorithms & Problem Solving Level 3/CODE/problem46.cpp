/*
problem 46:
write a program to convert line data to record and print it :

*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
#include<iomanip>
using namespace std;

struct stClient
{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    float accountBalance;
};

vector<string> getSplitStringWordToVector(string str, string delim = " ")
{
    vector<string> vstr;
    short counter = 0;
    short pos = 0;
    string word;

    while ((pos = str.find(delim)) != string::npos)
    {

        vstr.push_back(str.substr(0, pos));

        str.erase(0, pos + delim.length());
    }

    // counts the last word :
    if (str != "")
        vstr.push_back(str);

    return vstr;
}

stClient lineClientDateToRecord(string lineData, string separator)
{

    stClient Record;

    vector<string> vRecord = getSplitStringWordToVector(lineData, separator);

    Record.accountNumber = vRecord[0];
    Record.pinCode = vRecord[1];
    Record.name = vRecord[2];
    Record.phone = vRecord[3];
    Record.accountBalance = stof(vRecord[4]);
    return Record;
}

void printRecord(stClient client)
{

    cout << "\n";

    cout << "Account Number  : " << client.accountNumber << "\n";
    cout << "Account PinCode : " << client.pinCode << "\n";
    cout << "Account Name    : " << client.name << "\n";
    cout << "Account Phone   : " << client.phone << "\n";
    cout << "Account Balance : " << fixed<<setprecision(2)<<client.accountBalance << "\n";

    cout << "\n";
}

int main()
{
    string lineData = "12//#sds//#ayoub//#m211//#5000";

    cout << lineData << "\n";

    cout << "The following is the extracted client record :  \n";
    stClient client = lineClientDateToRecord(lineData, "//#");
       printRecord(client); 
    return 0;
}