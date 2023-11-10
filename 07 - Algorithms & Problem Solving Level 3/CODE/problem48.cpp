/*
problem 48:
write a program to read clients file and show them on the screen as follows
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

int getNumberOfClientInFile(fstream &ClientsFile)
{

    unsigned fileLinesCounter = 0;
    string tempStrToCount;
    while (getline(ClientsFile, tempStrToCount))
        fileLinesCounter++;
    ClientsFile.clear();
    ClientsFile.seekg(0, ios::beg);
    return fileLinesCounter;
}
void printClientsBasicTableOnScreen(fstream &ClientsFile)
{

    cout << setw(75) << "\n\n                                          Client List (" << getNumberOfClientInFile(ClientsFile) << ") Client(s).\n";
    cout << setw(75) << "_______________________________________________________________________________________________________________________\n\n";
    cout << "  | " <<left<< setw(20) << "Account Name"
         << "   "
         << "  | " <<left<< setw(20) << "Pin Code"
         << "   "
         << "  | " <<left<< setw(20) << "Name"
         << "   "
         << "  | " <<left<< setw(10) << "phone"
         << "   "
         << "  | " << fixed << setprecision(2) << "   Balance"
         << "\n";
    cout << setw(75) << "_______________________________________________________________________________________________________________________\n\n";
}
void printClient(string dataLine)
{

    stClient client = lineClientDateToRecord(dataLine);

    cout << "  | " << left<<setw(20) << client.accountNumber << "   "
                                                          "  | "
         << left<<setw(20) << client.pinCode << "   "
         << left<<setw(3) << "  | " << setw(20) << client.name << "   "

         << "  | " << left<<setw(10) << client.phone << "   "
                                                  "  | "
         << fixed << setprecision(2) << "   " << client.accountBalance
         << "\n";
}

void printClients(fstream &ClientsFile)
{

    string dataLine = "";
    while (getline(ClientsFile, dataLine))
    {
        printClient(dataLine);
    }

    cout << setw(75) << "\n_______________________________________________________________________________________________________________________\n\n";
}
void ReadClients(string fileName)
{

    fstream ClientsFile;

    ClientsFile.open(fileName, ios::in);
    if (!ClientsFile.is_open())
    {
        cerr << "Error: File is not open." << endl;
    }
    else
    {
        ClientsFile.seekg(0, ios::beg);

        printClientsBasicTableOnScreen(ClientsFile);
        printClients(ClientsFile);
        // return the  file pointer to the begin :
        ClientsFile.clear();
        ClientsFile.close();
    }
}

int main()
{
    string fileName = "ClientFile.txt";
    ReadClients(fileName);
}
