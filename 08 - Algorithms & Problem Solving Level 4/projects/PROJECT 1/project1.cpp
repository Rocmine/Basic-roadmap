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


 To Do Later inchalah :  
*/

#include <iostream>
#include "lib/myLib.h"
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>

#include <fstream>
#include <stdexcept>
using namespace std;
const string separator = "#/";

enum enUserPermissions{
    preShowClient =1,
    perAddClient,
    perDeleteClient,
    perUpdateClient,
    perFindClient,
    perTransaction,
    perManageUsers, 
    perLogout
}; 

struct stClient
{

    string accountNumber;
    string pinCode;
    string name;
    string phone;
    float accountBalance;
};

struct  stUser 
{
    string  username; 
    string  password;
    vector<bool> vPermissions;
      stUser() : vPermissions(8){}   

};

const string clientsFile = "clients.txt";

const string usersFile="users.txt"; 
// --------------------------- print page Section  Function--------------------------------

void printSectionTitle(string title)
{
    cout << "\n----------------------------------\n";
    cout << "        " << title << "     \n";
    cout << "----------------------------------\n\n";
}

// ------------------------------upload data To vector functions ----------------------------------------------
vector<string> getSplitStringWordToVector(string str, string delim = ::separator)
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

stClient lineClientDateToRecord(string lineData, string separator = ::separator)
{

    stClient Record;

    vector<string> vRecord = getSplitStringWordToVector(lineData);

    Record.accountNumber = vRecord[0];
    Record.pinCode = vRecord[1];
    Record.name = vRecord[2];
    Record.phone = vRecord[3];
    Record.accountBalance = stof(vRecord[4]);
    return Record;
}

vector<stClient> loadClientsToVector(string fileName = ::clientsFile)
{

    fstream ClientsFile;
    vector<stClient> vClients;
    ClientsFile.open(fileName, ios::out | ios::in);

    if (ClientsFile.is_open())
    {

        string dataLine = "";
        while (getline(ClientsFile, dataLine))
        {

            stClient client = lineClientDateToRecord(dataLine);
            vClients.push_back(client);
        }
        ClientsFile.clear();
        return vClients;
    }
    else
    {
        cerr << "Opening File Error :  ";
        exit(1);
    }
}

// ------------------------------------update file functions -----------------------------------------------
string RecordToLineClientDate(stClient client, string delim = ::separator)
{

    string str = client.accountNumber + delim + client.pinCode + delim + client.name + delim + client.phone + delim + to_string(client.accountBalance);

    return str;
}
void UpdateFile(vector<stClient> vClients, string fileName = ::clientsFile)
{

    fstream clientsFile;

    clientsFile.open(fileName, ios::out);

    for (int i = 0; i < vClients.size(); i++)
    {
        clientsFile << RecordToLineClientDate(vClients[i]) << endl;
    }

    clientsFile.close();
}
// ---------------------------------------------------- AddNewClients Functions :-----------------------------------------------------------------------------------------//
enum enIsClientFound
{
    notFound,
    isFound
};
enIsClientFound checkIfClientAlreadyExist(vector<stClient> &vClients, string ClientAn)
{

    for (stClient &c : vClients)
    {
        if (c.accountNumber == ClientAn)
        {
            return enIsClientFound::isFound;
        }
    }

    return enIsClientFound::notFound;
}
stClient ReadClient(vector<stClient> vClients)
{

    stClient client;
    enIsClientFound AlreadyExist = enIsClientFound::notFound;
    cout << "Adding New Client : \n\n";

    do
    {
        if (AlreadyExist)
            cout << "\nClient with [" << client.accountNumber << "]"
                 << " already exits\n";

        client.accountNumber = input::readString("Enter Account Number? ");
        AlreadyExist = checkIfClientAlreadyExist(vClients, client.accountNumber);

    } while (AlreadyExist == enIsClientFound::isFound);

    client.pinCode = input::readString("Enter PinCode? ");
    client.name = input::readString("Enter Name? ");
    client.phone = input::readString("Enter Phone? ");
    client.accountBalance = input::readFloat("Enter AccountBalance? ");

    return client;
}

void addClient(vector<stClient> &vClient)
{

    stClient client = ReadClient(vClient);
    vClient.push_back(client);
}
enum enWannaAddMore
{
    no,
    yes
};
enWannaAddMore checkIfUserWannaAddMoreRecord()
{
    char wannaAddMore;
    cout << "\nClient added Successfully, do you want to add more clients";

    wannaAddMore = input::readCharacter("[y][n] : ");

    if (wannaAddMore == 'y' || wannaAddMore == 'Y')
        return enWannaAddMore::yes;

    return enWannaAddMore::no;
}

void AddClients(vector<stClient> &vClient, string fileName = ::clientsFile)
{
    enWannaAddMore wannaAddMore = enWannaAddMore::no;
    do
    {
        system("cls");
        printSectionTitle("Add New Clients Screen ");
        addClient(vClient);
        wannaAddMore = checkIfUserWannaAddMoreRecord();

    } while (wannaAddMore == enWannaAddMore::yes);

    UpdateFile(vClient);
}

// -------------------------------------show Client list  functions ----------------------------- :

void printClientsBasicTableOnScreen(vector<stClient> vClients)
{

    cout << setw(75) << "\n\n                                          Client List (" << vClients.size() << ") Client(s).\n";
    cout << setw(75) << "_______________________________________________________________________________________________________________________\n\n";
    cout << "  | " << left << setw(20) << "Account Number"
         << "   "
         << "  | " << left << setw(20) << "Pin Code"
         << "   "
         << "  | " << left << setw(20) << "Name"
         << "   "
         << "  | " << left << setw(10) << "phone"
         << "   "
         << "  | " << fixed << setprecision(2) << "   Balance"
         << "\n";
    cout << setw(75) << "_______________________________________________________________________________________________________________________\n\n";
}
void printClient(stClient client)
{

    cout << "  | " << left << setw(20) << client.accountNumber << "   "
                                                                  "  | "
         << left << setw(20) << client.pinCode << "   "
         << left << setw(3) << "  | " << setw(20) << client.name << "   "

         << "  | " << left << setw(10) << client.phone << "   "
                                                          "  | "
         << fixed << setprecision(2) << "   " << client.accountBalance
         << "\n";
}

void printClients(vector<stClient> vClients)
{

    system("cls");
    printClientsBasicTableOnScreen(vClients);
    for (stClient &client : vClients)
    {
        printClient(client);
    }

    cout << setw(75) << "\n_______________________________________________________________________________________________________________________\n\n";
}

// ----------------------------------------delete functions------------------------------------------------------
enIsClientFound checkIfClientAlreadyExist(vector<stClient> vClients, string ClientAn, stClient &MyClient)
{

    string dataLine = "";
    for (stClient c : vClients)
    {
        if (c.accountNumber == ClientAn)
        {
            MyClient = c;
            return enIsClientFound::isFound;
        }
    }

    return enIsClientFound::notFound;
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

void deleteRecordFromVector(vector<stClient> &vClients, string ClientAn)
{

    for (int i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].accountNumber == ClientAn)
        {

            vClients.erase(vClients.begin() + i);
            return;
        }
    }
}
void deleteClient(vector<stClient> &vClients)
{
    system("cls");
    printSectionTitle("delete Clients Screen ");
    stClient client;

    string ClientAn = input::readString("Enter AccountNumber? ");
    if (checkIfClientAlreadyExist(vClients, ClientAn, client) == enIsClientFound::isFound)
    {

        printRecord(client);

        char sureToDelete = input::readCharacter("\nAre you sure you want delete this element? y/n ?");
        if (toupper(sureToDelete) == 'Y')
        {
            deleteRecordFromVector(vClients, ClientAn);
            UpdateFile(vClients);
            cout << "Client deleted with Successfully \n";
        }
        else
        {
            cout << "Operation Canceled with success\n";
        }
    }
    else
    {
        cout << "\nclient with Account Number(" << ClientAn << ") "
             << "not found!\n\n";
    }
}

// ---------------------- update client functions --------------------------------------------

void ReadUpdatedClient(stClient &client)
{

    client.pinCode = input::readString("Enter PinCode? ");
    client.name = input::readString("Enter Name? ");
    client.phone = input::readString("Enter Phone? ");
    client.accountBalance = input::readFloat("Enter AccountBalance? ");
}

void updateRecordFromVector(vector<stClient> &vClients, string ClientAn)
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
void Update(vector<stClient> &vClients)
{

    system("cls");
    printSectionTitle("Update Clients Screen ");
    stClient client;

    string ClientAn = input::readString("Enter AccountNumber? ");
    if (checkIfClientAlreadyExist(vClients, ClientAn, client) == enIsClientFound::isFound)
    {

        printRecord(client);

        char sureToDelete = input::readCharacter("\nAre you sure you want update this element? y/n ?");
        if (toupper(sureToDelete) == 'Y')
        {
            updateRecordFromVector(vClients, ClientAn);
            UpdateFile(vClients);
            cout << "Client updated with Successfully \n";
        }
        else
        {
            cout << "Operation Canceled with success\n";
        }
    }
    else
    {
        cout << "\nclient with Account Number(" << ClientAn << ") "
             << "not found!\n\n";
    }
}

// ---------------------find client functions --------------------------------------------

void findClient(vector<stClient> vClients)
{
    system("cls");
    printSectionTitle("Find Clients Screen ");
    stClient client;

    string ClientAn = input::readString("Enter AccountNumber? ");
    if (checkIfClientAlreadyExist(vClients, ClientAn, client) == enIsClientFound::isFound)
    {
        printRecord(client);
    }
    else
    {
        cout << "\nclient with Account Number(" << ClientAn << ") "
             << "not found!\n\n";
    }
}


// ---------------------Transaction functions --------------------------------------------
/*
[1] Deposit.
[2] Withdraw.
[3] Total Balances
[4] Main Menu.
*/

// ------------------Deposit  functions -----------------------------------------------
void printTransactionMenu()
{

    system("cls");
    cout << setw(70) << "\n======================================================================\n";

    cout << "                          Transaction Menu Screen                          \n";
    cout << setw(70) << "======================================================================\n";

    cout << "                "
         << "[1] Deposit.\n";
    cout << "                "
         << "[2] Withdraw.\n";
    cout << "                "
         << "[3] Total Balances.\n";
    cout << "                "
         << "[4] Main Menu.\n";
   
    cout << setw(70) << "======================================================================\n";
}

enum enGameTransactionChoices
{
    eDeposit = 1,
     eWithdraw,
     TotalBalances,
      mainMenu
};
void DepositRecordFromVector(vector<stClient> &vClients, string ClientAn)
{

    for (int i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].accountNumber == ClientAn)
        {  
        
            vClients[i].accountBalance += input::readFloat("Enter Deposit amount? ");
            return;
        }
    }
}


 void  Deposit(vector<stClient> &vClients){
   system("cls");
    printSectionTitle("Deposit Screen");
    stClient client;

    string ClientAn = input::readString("Enter AccountNumber? ");
    if (checkIfClientAlreadyExist(vClients, ClientAn, client) == enIsClientFound::isFound)
    {

        printRecord(client);
       
            DepositRecordFromVector(vClients, ClientAn);
            UpdateFile(vClients);
            cout << "amount  deposed   Successfully \n\n";
    
 }
  else
    {
        cout << "\nclient with Account Number(" << ClientAn << ") "
             << "not found!\n\n";
    }
 }
 // ------------------ eWithdraw  functions -----------------------------------------------
 void WithdrawRecordFromVector(vector<stClient> &vClients, string ClientAn)
{

    for (int i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].accountNumber == ClientAn)
        {  
        
            vClients[i].accountBalance -= input::readFloat("Enter Withdraw amount?");
            return;
        }
    }
}
  void Withdraw(vector<stClient> &vClients){
 system("cls");
    printSectionTitle("Withdraw Screen");
    stClient client;

    string ClientAn = input::readString("Enter AccountNumber? ");
    if (checkIfClientAlreadyExist(vClients, ClientAn, client) == enIsClientFound::isFound)
    {

        printRecord(client);
       
            WithdrawRecordFromVector(vClients, ClientAn);
            UpdateFile(vClients);
            cout << "amount  Withdraw  Successfully \n\n";
    

 }
 else
    {
        cout << "\nclient with Account Number(" << ClientAn << ") "
             << "not found!\n\n";
    }
  }
// ------------------ balance   functions -----------------------------------------------
  void printBasicBalanceTableOnScreen(vector<stClient> vClients)
{

    cout << setw(75) << "\n\n                                          Client List (" << vClients.size()<< ") Client(s).\n";
    cout << setw(75) << "_______________________________________________________________________________________________________________________\n\n";
    cout << "  | " << left << setw(20) << "Account Name"
         << "   "
         << "  | " << left << setw(20) << "Pin Code"
         << "   "
         << "  | " << left << setw(20) << " client Name"
         << "   "
         << "  | " << fixed << setprecision(2) << "   Balance"
         << "\n";
    cout << setw(75) << "_______________________________________________________________________________________________________________________\n\n";
}
void printBalanceClientInfo(stClient client)
{

    cout << "  | " << left << setw(20) << client.accountNumber << "   "
                                                                  "  | "
         << left << setw(20) << client.pinCode << "   "
         << left << setw(3) << "  | " << setw(20) << client.name << "   "
         << "  | " 
         << fixed << setprecision(2) << "   " << client.accountBalance
         << "\n";
}


  void PrintBalanceTable(vector<stClient> vClients){
    system("cls");
    printBasicBalanceTableOnScreen(vClients);
    for (stClient &client : vClients)
    {
        printBalanceClientInfo(client);
    }

    cout << setw(75) << "\n_______________________________________________________________________________________________________________________\n\n";
 }

void Wait( string msg);
enum enWannaReturnToMenu{
    noBackMenu, 
    wannaBackMenu 
};

enWannaReturnToMenu ManageUserTransactionChoices(enGameTransactionChoices GameChoice, vector<stClient> &vClients)
{
     enWannaReturnToMenu wannaReturnToMenu=enWannaReturnToMenu::noBackMenu; 
    switch (GameChoice)
    {
    case enGameTransactionChoices::eDeposit :
            Deposit(vClients); 
        break;
    case enGameTransactionChoices::eWithdraw :
            Withdraw(vClients); 
        break;
    case enGameTransactionChoices::TotalBalances :
             PrintBalanceTable(vClients);
        break;
    case enGameTransactionChoices::mainMenu :
             wannaReturnToMenu=enWannaReturnToMenu::wannaBackMenu;
        break;
      
  
    }
    if( wannaReturnToMenu==enWannaReturnToMenu::noBackMenu)
       Wait("go back to Transaction menu :");
    return wannaReturnToMenu;
}

void transactionF(vector<stClient> &vClients){
     system("cls");
    printSectionTitle("Transactions Menu Screen");
    printTransactionMenu();

    int userChoice = 0;
    do
    {
        
           printTransactionMenu();
            userChoice = input::readIntegerInRange(enGameTransactionChoices::eDeposit, enGameTransactionChoices::mainMenu, "Choose what do you want to do [1 to 4]? ");

            if(ManageUserTransactionChoices(enGameTransactionChoices(userChoice), vClients) == enWannaReturnToMenu::wannaBackMenu)
            userChoice=enGameTransactionChoices::mainMenu;
        
    
         
    } while(enGameTransactionChoices(userChoice) != enGameTransactionChoices::mainMenu);

}

// -----------------------------------------Manage  users  Functions-----------------------------------------
 
void  StrToPermissionsVector(vector<bool> &vPermissions, string str){
 for(int i=enUserPermissions::preShowClient; i<str.length();i++){
 vPermissions[i]=bool(str[i]); 
 
 }
}
string vPermissionsToString(const vector<bool> &vPermissions){
  string strVPerm=" "; 
  for(int i=enUserPermissions::preShowClient ; i<vPermissions.size();i++){
        strVPerm+=vPermissions[i];
     
  }
  return strVPerm; 

} 
        
 stUser lineUserDateToRecord(string lineData, string separator = ::separator)
{

    stUser Record;

    vector<string> vRecord = getSplitStringWordToVector(lineData);

    Record.username = vRecord[0];
    Record.password = vRecord[1];
  StrToPermissionsVector(Record.vPermissions,vRecord[2]); 
     
    return Record;
}

vector<stUser> loadUsersToVector(string fileName = ::usersFile)
{

    fstream usersFile;
    vector<stUser> vUsers;
    usersFile.open(fileName, ios::out | ios::in);

    if (usersFile.is_open())
    {

        string dataLine = "";
        while (getline(usersFile, dataLine))
        {

            stUser client = lineUserDateToRecord(dataLine);
            vUsers.push_back(client);
        }
        usersFile.clear();
        return vUsers;
    }
    else
    {
        cerr << "Opening File Error :  ";
        exit(1);
    }
}

// ------------------------------------update Users file functions -----------------------------------------------
string RecordToLineUserData(const stUser &user, string delim = ::separator)
{

    string str = user.username + delim + user.password + delim +
    vPermissionsToString(user.vPermissions);

    return str;
}
void UpdateUsersFile(const vector<stUser> &vUsers, string fileName = ::usersFile)
{

    fstream usersFile;

    usersFile.open(fileName, ios::out);

    for (int i = 0; i < vUsers.size(); i++)
    {
        usersFile << RecordToLineUserData(vUsers[i]) << endl;
    }

    usersFile.close();
}

enum enGameManageUsersChoices{
  eShowUsers=1,
  eAddNewUser, 
  eDeleteUser, 
  eUpdateUser,
  eFindUser, 
  eMainMenu
}; 


void printManageUsersMenu()
{

    system("cls");
    cout << setw(70) << "\n======================================================================\n";

    cout << "                          Manage Users Menu Screen                          \n";
    cout << setw(70) << "======================================================================\n";

    cout << "                "
         << "[1] List Users.\n";
    cout << "                "
         << "[2] Add new User.\n";
    cout << "                "
         << "[3] delete User.\n";
    cout << "                "
         << "[4] update User.\n";
    cout << "                "
         << "[5] Find User.\n";
    cout << "                "
         << "[6] Main Menu.\n";
   
    cout << setw(70) << "======================================================================\n";
}

void printUsersBasicTableOnScreen(vector<stUser> vUsers)
{

    cout << setw(75) << "\n\n                                          Client List (" << vUsers.size() << ") Client(s).\n";
    cout << setw(75) << "_______________________________________________________________________________________________________________________\n\n";
    cout << "  | " << left << setw(10) << "Username "
         << "   "
         << "  | " << left << setw(14) << "Password"
         << "   "
         << "  | " << left << setw(20) << "Permission"
         << "   "    
         << "\n";
    cout << setw(75) << "_______________________________________________________________________________________________________________________\n\n";
}
string getStrPermissionToPrint(vector<bool> vPermissions){
  string strPerm[]{"N","Y"}; 
 string strVPerm=""; 
  for(int i=enUserPermissions::preShowClient ; i<vPermissions.size();i++){

        strVPerm+= "["+ to_string(i) +"]:" + strPerm[vPermissions[i]] +"  ";
     
  }
  return strVPerm; 
} 
void printUser(stUser user)
{

    cout << "  | " << left << setw(10) << user.username << "  "
                                                                  "   | "
         << left << setw(14) << user.password << "   "
         << left << "  | "<< getStrPermissionToPrint(user.vPermissions)
         << "   "
         << "\n";
}

void printUsers(vector<stUser> vUsers)
{

    system("cls");
    printUsersBasicTableOnScreen(vUsers);
    for (stUser &user : vUsers)
    {
        printUser(user);
    }

    cout << setw(75) << "\n_______________________________________________________________________________________________________________________\n\n";
}

enum enIsUserFound
{
    userNotFound,
    UserFound
};
enIsUserFound checkIfUserAlreadyExist(vector<stUser> &vUsers, string username ,stUser &MyUser= *(new stUser))
{

    for (stUser &u : vUsers)
    {
        if (u.username == username)
        {
         MyUser=u;    
            return enIsUserFound::UserFound;
        }
    }

    return enIsUserFound::userNotFound;
}

void  readUserPermissions(vector<bool> &vPerm){

string strPermissions[8]={
     "", 
    "[1] Show Client List",
    "[2] Add new Client",
    "[3] Delete Client",
    "[4] Update Client Info",
    "[5] Find Client",
    "[6] Transactions",
    "[7] Manage Users",
    };

  for(int i=enUserPermissions::preShowClient; i<vPerm.size(); i++){ 
   char perm; 
    cout<<"\n"; 
 bool validValue; 
  do{
     perm=input::readCharacter(strPermissions[i] +  " [y/n]? "); 

  }while(tolower(perm) !='y' && tolower(perm) != 'n');
   
    
   vPerm[i]= towlower(perm)=='y'; 
 
  }

   


}
stUser ReadUser(vector<stUser> vUsers)
{

    stUser user;
    enIsUserFound AlreadyExist = enIsUserFound::userNotFound;
    cout << "Adding New User : \n\n";

    do
    {
        if (AlreadyExist)
            cout << "\nUser with [" << user.username << "]"
                 << " already exits\n";

        user.username= input::readString("Enter the username ? ");
        AlreadyExist = checkIfUserAlreadyExist(vUsers, user.username);

    } while (AlreadyExist == enIsUserFound::UserFound);

    user.password = input::readString("Enter  the password ? ");
    cout<<"\n New User Permissions : \n"; 
     readUserPermissions(user.vPermissions); 
    
   
    

    return user;
}

void addUser(vector<stUser> &vUsers)
{

    stUser user = ReadUser(vUsers);
    vUsers.push_back(user);
}

enWannaAddMore checkIfUserWannaAddMoreUsers()
{
    char wannaAddMore;
    cout << "\nUser added Successfully, do you want to add more users? ";
do{
    wannaAddMore = input::readCharacter("[y][n] : ");
  }while(toupper(wannaAddMore) !='Y' && toupper(wannaAddMore) != 'N'); 
     
    
 

    if (wannaAddMore == 'y' || wannaAddMore == 'Y')
        return enWannaAddMore::yes;

    return enWannaAddMore::no;
}

void AddUsers(vector<stUser> &vUsers, string fileName = ::usersFile)
{
    enWannaAddMore wannaAddMore = enWannaAddMore::no;
    do
    {
        system("cls");
        printSectionTitle("Add New Users Screen ");
        addUser(vUsers);
        wannaAddMore = checkIfUserWannaAddMoreUsers();

    } while (wannaAddMore == enWannaAddMore::yes);

    UpdateUsersFile(vUsers);
}

void deleteUserFromVector(vector<stUser> &vUsers, string username)
{

    for (int i = 0; i < vUsers.size(); i++)
    {
        if (vUsers[i].username == username)
        {

            vUsers.erase(vUsers.begin() + i);
            return;
        }
    }
}
void deleteUser(vector<stUser> &vUsers)
{
    system("cls");
    printSectionTitle("delete User Screen ");
    stUser user;

    string  username= input::readString("Enter the Username? ");
    if (checkIfUserAlreadyExist(vUsers,username,user) == enIsUserFound::UserFound)
    {

        printUser(user);
                char sureToDelete; 
        do{

      sureToDelete = input::readCharacter("\nAre you sure you want delete this element? y/n ?");
       
         }while(toupper(sureToDelete) !='Y' && toupper(sureToDelete) != 'N'); 
        if (toupper(sureToDelete) == 'Y')
        {
            deleteUserFromVector(vUsers,username);
            UpdateUsersFile(vUsers);
            cout << "User deleted with Successfully \n";
        }
        else
        {
            cout << "Operation Canceled with success\n";
        }
    }
    else
    {
        cout << "\nUser with Account Number(" << username << ") "
             << "not found!\n\n";
    }
}



    
// -----------------------------------------Manage  users  Functions-----------------------------------------
 enWannaReturnToMenu ManageUserUsersChoices(enGameManageUsersChoices GameChoice, vector<stUser> &vUsers)
{
     enWannaReturnToMenu wannaReturnToMenu=enWannaReturnToMenu::noBackMenu; 
    switch (GameChoice)
    {
    case enGameManageUsersChoices::eShowUsers:
            printUsers(vUsers); 
        break;
    case enGameManageUsersChoices::eAddNewUser:
         AddUsers(vUsers); 
            
        break;
    case enGameManageUsersChoices::eDeleteUser :
     deleteUser(vUsers); 
            
        break;
    case enGameManageUsersChoices::eUpdateUser :
            
        break;
    case enGameManageUsersChoices::eFindUser:
            
        break;

    case enGameManageUsersChoices::eMainMenu:
             wannaReturnToMenu=enWannaReturnToMenu::wannaBackMenu;
        break;
      
  
    }
    if( wannaReturnToMenu==enWannaReturnToMenu::noBackMenu)
       Wait("go back to Manage Uses  menu :");
    return wannaReturnToMenu;
}

 
    void ManageUsers(vector<stUser> &vUsers){
    
     system("cls");
    printSectionTitle("manage Users Menu Screen");
    printManageUsersMenu();


      int userChoice = 0;
    do
    {
        
           printManageUsersMenu();
            userChoice = input::readIntegerInRange(enGameManageUsersChoices::eShowUsers, enGameManageUsersChoices::eMainMenu, "Choose what do you want to do [1 to 6]? ");

            if(ManageUserUsersChoices(enGameManageUsersChoices(userChoice), vUsers) == enWannaReturnToMenu::wannaBackMenu)
            userChoice=enGameManageUsersChoices::eMainMenu;
        
    
         
    } while(enGameManageUsersChoices(userChoice) != enGameManageUsersChoices::eMainMenu);

    }
      



// --------------------------------------------------exit Functions------------------------------------------

void exitProgram()
{

    system("cls");
    printSectionTitle("Program Ends :-)");

    exit(0);
}

// ------------------print menu functions -----------------------------------------------

void printMenu()
{

    system("cls");
    cout << setw(70) << "\n======================================================================\n";

    cout << "                          Main Menu Screen                          \n";
    cout << setw(70) << "======================================================================\n";

    cout << "                "
         << "[1] Show Client List.\n";
    cout << "                "
         << "[2] Add new Client.\n";
    cout << "                "
         << "[3] Delete Client.\n";
    cout << "                "
         << "[4] Update Client Info.\n";
    cout << "                "
         << "[5] Find Client.\n";
    cout << "                "
         << "[6] Transactions.\n";
    cout << "                "
         << "[7] Manage Users.\n";

    cout << "                "
         << "[8] Logout .\n";
    cout << setw(70) << "======================================================================\n";
}
void Wait( string msg)
{

    cout <<msg;
    system("pause>0");

}
enum enGameChoices
{
    ShowClient = 1,
    AddClient,
    DeleteClient,
    UpdateClient,
    FindClient,
     transaction,
    eManageUsers, 
    eLogout
};

void ManageUserChoices(enGameChoices GameChoice, vector<stClient> &vClients,vector<stUser> &vUsers)
{

    switch (GameChoice)
    {
    case enGameChoices::ShowClient:
        printClients(vClients);
        break;

    case enGameChoices::AddClient:
        AddClients(vClients);
        break;

    case enGameChoices::DeleteClient:
        deleteClient(vClients); // [3]
        break;
    case enGameChoices::UpdateClient:
        Update(vClients); // [4]
        break;

    case enGameChoices::FindClient:
        findClient(vClients); // [5]
        break;
    case enGameChoices::eManageUsers:// [6]
    ManageUsers(vUsers);
    break;
    case enGameChoices::transaction:
        transactionF(vClients); // [7]
        break;

    
     

    case enGameChoices::eLogout:
        exitProgram(); // [8]
        break;
    }

    Wait("\nPress Enter to go back  to  main Menu :");
}

void StartBank()
{
    vector<stClient> vClients = loadClientsToVector();
    vector<stUser> vUsers = loadUsersToVector();

    int userChoice = 0;
    do
    {
        
            printMenu();
            userChoice = input::readIntegerInRange(enGameChoices::ShowClient, enGameChoices::eLogout, "Choose what do you want to do [1 to 7]? ");

            ManageUserChoices(enGameChoices(userChoice), vClients,vUsers);
        
    

    } while (enGameChoices(userChoice) != enGameChoices::eLogout);
}

int main()
{
    try
    {
        StartBank();
        
    }
    catch (const std::exception &e)
    {
        // Catch the exception and handle it
        system("cls"); 
        std::cerr << "\nCaught exception: " << e.what() << std::endl;
        cin.clear(); 
    }


    return 0;
}