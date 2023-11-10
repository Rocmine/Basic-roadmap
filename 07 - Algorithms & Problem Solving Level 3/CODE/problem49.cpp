/*
problem 49:
write a program to find client by  AccountNumber and print it on  the screen 
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

const string separator = "#//";
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

stClient lineClientDateToRecord(string lineData, string separator = "#//")
{

    stClient Record;

    vector<string> vRecord = getSplitStringWordToVector(lineData, separator = "#//");

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

enum enIsClientFound{no,yes}; 
 enIsClientFound printClientWithSpecificAN(fstream &ClientsFile,string ClientAn)
{

    string dataLine = "";
    while (getline(ClientsFile, dataLine))
    {   
   stClient client = lineClientDateToRecord(dataLine);

       if(client.accountNumber==ClientAn) {
        printRecord(client);
      return enIsClientFound::yes; 
       }       
    }

return enIsClientFound::no; 
   
}


int main()
{
    string fileName = "ClientFile.txt";
       fstream ClientsFile;
   ClientsFile.open(fileName, ios::in);
    if (!ClientsFile.is_open())
    {
        cerr << "Error: File is not open." << endl;
    }
    else
    {
        string lookForClient=input::readString("Enter accountNumber? ");


   if(printClientWithSpecificAN(ClientsFile,lookForClient)==enIsClientFound::no){
    cout<<"client with Account Number("<<lookForClient<<") "<<"not found!\n";
   } 

     ClientsFile.close();   
    }
       
}
