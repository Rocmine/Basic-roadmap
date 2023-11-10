/*
problem 45:
write a program to read bank client data record  and convert it to one line

*/

#include <iostream>
#include "myLib.h"
#include <cctype>
#include <string>
using namespace std;

struct stClient
{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    float accountBalance;
};

stClient ReadClient()
{

    stClient client;

    cout << "enter the Client  data a: \n\n";

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

int main()
{
    stClient client = ReadClient();

    cout << "Client Record for saving is :\n";
    cout << RecordToLineClientDate(client, "//#") << "\n"
         << endl;

    return 0;
}