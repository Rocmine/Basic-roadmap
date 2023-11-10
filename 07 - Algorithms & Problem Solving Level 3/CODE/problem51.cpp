/*
problem 51:
write a program to update client by AccountNUmber :
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

enum enIsClientFound
{
    no,
    yes
};

vector<stClient> loadClientsToVector(fstream &ClientsFile)
{

    ClientsFile.seekg(0, ios::beg);

    vector<stClient> vClients;
    string dataLine = "";
    while (getline(ClientsFile, dataLine))
    {
        stClient client = lineClientDateToRecord(dataLine);
        vClients.push_back(client);
    }

    return vClients;
}
enIsClientFound checkIfClientAlreadyExist(vector<stClient> vClients, string ClientAn, stClient &MyClient)
{

    string dataLine = "";
    for (stClient &c : vClients)
    {
        if (c.accountNumber == ClientAn)
        {
            MyClient = c;
            return enIsClientFound::yes;
        }
    }

    return enIsClientFound::no;
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

void ReadUpdatedClient(stClient &client)
{

    client.pinCode = input::readString("Enter PinCode? ");
    client.name = input::readString("Enter Name? ");
    client.phone = input::readString("Enter Phone? ");
    client.accountBalance = input::readFloat("Enter AccountBalance? ");
}

void deleteRecordFromVector(vector<stClient> &vClients, string ClientAn)
{

    for (int i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].accountNumber == ClientAn)
        {
            ReadUpdatedClient(vClients[i]);
            return;
        }
    }
}
string RecordToLineClientDate(stClient client, string delim = "#//")
{

    string str = client.accountNumber + delim + client.pinCode + delim + client.name + delim + client.phone + delim + to_string(client.accountBalance);

    return str;
}

void UpdateFile(string fileName, vector<stClient> vClients)
{

    fstream clientsFile;

    clientsFile.open(fileName, ios::out);

    for (int i = 0; i < vClients.size(); i++)
    {
        clientsFile << RecordToLineClientDate(vClients[i]) << endl;
    }

    clientsFile.close();
}

void printClientVector(vector<stClient> &vClients)
{
    for (int i = 0; i < vClients.size(); i++)
    {
        printRecord(vClients[i]);
    }
}
int main()
{

    string fileName = "ClientFile.txt";
    fstream clientsFile;
    stClient client;

    clientsFile.open(fileName, ios::in);

    if (clientsFile.is_open())
    {

        vector<stClient> vClients = loadClientsToVector(clientsFile);
        string ClientAn = input::readString("Enter AccountNumber? ");
        if (checkIfClientAlreadyExist(vClients, ClientAn, client) == enIsClientFound::yes)
        {

            printRecord(client);

            char sureToDelete = input::readCharacter("Are you sure you want update this element? y/n ?");
            if (toupper(sureToDelete) == 'Y')
            {

                deleteRecordFromVector(vClients, ClientAn);
                UpdateFile(fileName, vClients);
                cout << "Client updated with Successfully \n";
            }
            else
            {
                cout << "Operation Canceled with success\n";
            }
        }
        else
        {
            cout << "client with Account Number("
                 << ClientAn
                 << ") "
                 << "not found!\n";
        }

        clientsFile.close();
    }
    else
    {

        cout << " Error  while opening the file : " << endl;
    }

    return 0;
}