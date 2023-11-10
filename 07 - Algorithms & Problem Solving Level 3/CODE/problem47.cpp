/*
problem 47:
write a program to ask yiu to enter clients  and save  them to a file
*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
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
    cout << "Account Balance : " << fixed << setprecision(2) << client.accountBalance << "\n";

    cout << "\n";
}

stClient ReadClient()
{

    stClient client;

    cout << "enter the Client  data : \n\n";

    client.accountNumber = input::readString("Enter Account Number? ");
    client.pinCode = input::readString("Enter PinCode? ");
    client.name = input::readString("Enter Name? ");
    client.phone = input::readString("Enter Phone? ");
    client.accountBalance = input::readFloat("Enter AccountBalance? ");

    return client;
}

string RecordToLineClientDate(stClient client, string delim = " ")
{

    string str = client.accountNumber + delim + client.pinCode + delim + client.name + delim + client.phone + delim + to_string(client.accountBalance);

    return str;
}

void SaveRecordToFile(fstream &fileName, const stClient &client, string separator = "#//")
{

    string dataLine = RecordToLineClientDate(client, separator);

    fileName << dataLine << endl;
}

void AddClient(fstream &clientsFile)
{

    stClient client = ReadClient();

    SaveRecordToFile(clientsFile, client);
}
enum enWannaAddMore
{
    no,
    yes
};
enWannaAddMore checkIfUserWannaAddMoreRecord()
{
    char wannaAddMore;
    cout << "\nClient Successfully, do you want to add more clients";

    wannaAddMore = input::readCharacter("[y][n] : ");

    if (wannaAddMore == 'y' || wannaAddMore == 'Y')
        return enWannaAddMore::yes;

    return enWannaAddMore::no;
}

void AddClients(string fileName)
{

    fstream ClientsFile;
    string separator = "#//";

    //  open the file :
    ClientsFile.open(fileName, ios::out |ios::app  )  ;

    if (ClientsFile.is_open())
    {
        enWannaAddMore wannaAddMore = enWannaAddMore::no;
        do
        {
            system("cls");
            AddClient(ClientsFile);

            wannaAddMore = checkIfUserWannaAddMoreRecord();

        } while (wannaAddMore == enWannaAddMore::yes);
    }
}

int main()
{

    AddClients("ClientFile.txt");
}
