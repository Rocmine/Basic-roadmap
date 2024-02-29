/*
project 2 :  bank 1  extension  3 :
[1] Show Client List.
[2] Add New Client.
[3] Delete Client.
[4] Update Client Info.
[5] Find Client.
[6] Transactions.
[7] Manage Users.
[8] Logout

[7]Manage Users :
    [1] List Users.    UserName | Password | permissions
    [2] Add New User.
    [3] Delete User.
    [4] Update User.
    [5] Find User.
    [6] Main Menu.

 permissions : [1] to [7]
*/

#include <iostream>
#include "lib/cInput.h"
#include "lib/cUtil.h"

using namespace std;

class cClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    float accountBalance;
};

class cUser
{
    string username;
    string password;
    vector<bool> vPermissions;
    cUser() : vPermissions(8) {}
};

class cFile{
public:
static   string clientsFile="nice";

static  string usersFile;


};



int main()
{

    return 0;
}