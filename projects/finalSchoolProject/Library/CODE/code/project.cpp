#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

// include our  input libary that will help us to getting input from  console  easily.
#include "../lib/input.h"
// ignore the using of std :
using namespace std;

const string fileJsonName = "data.json";

// include json library :
#include "../lib/json.hpp"
using json = nlohmann::json;

/* ✨ Un passager est caractérisé
      par un identifiant,
      nom, prénom, âge,
      téléphone,
      adresse
*/

enum enIsPassInVPass
{
    notInVPass,
    yesInVPass
};
string strIsPassInVPass[] = {
    "\nLe passager n'existe pas dans le vecteur de passagers : ",
    "\nLe passager existe dans le vecteur de passagers : "
    };

class cPassager
{
private:
    int idPass;
    string nom;
    string prenom;
    short age;
    string tele;
    string adresse;

public:
    // empty constructor :
    cPassager();

    // parametrized constructor :
    cPassager(int idPass, string nom, string prenom, short age, string tele, string adresse);

    // main functions :

    // operator de saisir :

    friend istream &operator>>(istream &inp, cPassager &passager);
    // operator de saisir d'un vector des passagers :
    friend istream &operator>>(istream &inp, vector<cPassager> &vPassager);

    friend ostream &operator<<(ostream &out, cPassager &passager);
    // operator d'affichage  d'un vector des passagers :
    friend ostream &operator<<(ostream &out, vector<cPassager> &vPassager);

    // get idPass functions :
    int getIdPass();

    // get age
    short getAge();

    // read edited pass values :
    void readEditedPassInfo(int passId);

    // check  if pass in vPass :
    static enIsPassInVPass isPassInVPass(int passId, vector<cPassager> &vPassager);

    // +=  operator :
    friend void operator+=(vector<cPassager> &vPassager, const cPassager &addedPass);

    friend class cJson;
};

// date class :
class cDate
{
private:
    short days;
    short month;
    int year;

    // convert from  cDate to string function  :
    string getDateToString();

public:
    // constructor par default :
    cDate();

    //  parametrized constructor :
    cDate(int days, short month, short year);

    // copy constructor :
    cDate(const cDate &copy);

    // operator de saisir :
    friend istream &operator>>(istream &inp, cDate &date);

    // operator de affichage
    friend ostream &operator<<(ostream &out, cDate &date);

    // operator de comparaison :
    friend bool operator>(const cDate &ob1, const cDate &ob2);
    friend bool operator<(const cDate &ob1, const cDate &ob2);
    friend bool operator==(const cDate &ob1, const cDate &ob2);
    friend bool operator>=(const cDate &ob1, const cDate &ob2);
    friend bool operator<=(const cDate &ob1, const cDate &ob2);

    static cDate getCurrentDate();
    // get current time info(str) :
    static string getCurrentTimeInfo();

    // set days :
    void setDays(int days);

    // get days :
    int getDays();

    void readDateFab()
    {
        bool isValidDate = false;
        do
        {

            days = input::readPositiveIntegerNumber("");
            month = input::readPositiveIntegerNumber("");
            year = input::readPositiveIntegerNumber("");
            isValidDate = days > 31 || days < 1 || month > 12 || month < 1

                          || *this > cDate::getCurrentDate();
            if (isValidDate)
                cout << "\n----[La date doit être inférieure ou égale à la date actuelle et valide : ] " << cDate::getCurrentTimeInfo() << "\n\nRentrer une autre fois [d/m/y] : ";

        } while (isValidDate);
    }

    friend class cJson;
};

/*
✨Un avion est caractérisé :
    -par son code (chaîne de caractères),
    -un pilote (chaine decaractère),
    -son modèle,
     sa capacité de stockage (numérique),
    -sa date de fabrication
    -et le nombre de vols assurés.
*/
class cAvion
{
private:
    int codeAv;
    string pilote;
    string modele;
    int capacite;
    cDate dateFab;
    int nbrVols;

public:
    // constructor  par default :
    cAvion();

    // parametrized constructor :
    cAvion(int codeAv, string pilote, string modele, int capacite, cDate dateFab, int nbrVols);

    // operator de saisir :
    friend istream &operator>>(istream &inp, cAvion &avion);

    // operator de affichage
    friend ostream &operator<<(ostream &out, cAvion &avion);

    // get capacite function :
    int getCapacite();

    friend class cJson;
};

/*
✨ Un vol est caractérisé :
    - par un avion,
    - un tableau de passagers,
    - date de départ,
    - date d'arrivée
*/
enum enPassInVol
{
    ePasNotInVol,
    eVolNotExit,
    ePasInVol

};
string strPassInVol[] = {
    "\nLe passager n'existe pas dans le vecteur des vols : ",
    "\nLe vol n'existe pas dans le vecteur des vols : ",
    "\nLe passager existe dans le vecteur des vols : "};

enum enPassInvVol
{
    ePassInvVol,
    ePassNotInvVol
};

string strPassInvVol[] = {
    "\nLe passager n'existe pas dans le vecteur des vols : ",
    "\nLe passager existe dans le vecteur des vols : "};
enum enCheckVolExist
{
    eVolNotExist,
    eVolExist
};

string strCheckVolExist[] = {
    "\nLe vol n'existe pas dans les vols : ",
    "\nLe vol existe dans les vols : "};

class cVol
{
    int volId;
    cAvion avion;
    vector<cPassager> vPassager;
    cDate dateDep;
    cDate dateAr;

public:
    // empty constructor :
    cVol();

    // parametrized constructor :
    cVol(int volId, cAvion avion, const vector<cPassager> &vPassager, cDate dateDep, cDate dateAr);

    // operator de saisir :
    friend istream &operator>>(istream &inp, cVol &vol);

    // edit vol info :
    void readEditVolInfo();

    // operator de affichage
    friend ostream &operator<<(ostream &out, cVol &vol);

    // 2) Tester si un passager appartient à un vol :
    enPassInVol testPassInVol(int passId, int *index = nullptr);

    // 3) Ajouter un passager à un vol, tester son existence :
    void operator+=(cPassager passager);

    // 4) Modifier les informations d'un passager d'un vol, tester son existence :
    void editPassInfo(int passId);

    //------------------------: vols N de tableau un donneEtant---------------------------------------//
    // 5) Modifier la date d'un vol tout en testant si la nouvelle date saisie est superieure a la date actuelle :
    void editDate();

    // 6) Tester si un vol appartient à un tableau donné :
    static enCheckVolExist isVolExistInVol(int volId, const vector<cVol> &vVols, int *index = nullptr);

    // 7) Tester si un passager appartient à un tableau donné :
    static enPassInVol isPassExistInVol(int volId, int passId, vector<cVol> &vVols);

    // 8) Ajouter un vol à un tableau donné, tester son existence :
    friend void operator+=(vector<cVol> &vVols, const cVol &vol);

    // 9) Ajouter un passager à un vol donné, tester son existence :
    static void addPassagerTovVol(int volId, int passId, vector<cVol> &vVols);

    // 10) Afficher les informations de tous les vols d'un tableau :
    friend ostream &operator<<(ostream &out, vector<cVol> &vVol);

    // check passager in vols :
    static enPassInvVol isPassInvVols(int passId, vector<cVol> &vVol);

    // 11) Afficher les vols d'un passager donné ;
    static void afficheVolOfPass(int passId, vector<cVol> &vVol);

    // 12) Afficher les passagers ayant moins de 10 ans :
    void static affichePassVolsWhereAgeMoreThan10(vector<cVol> &vVol);

    // 13) Afficher les informations des vols qui seront lancé le lendemain :
    static void afficheVolsInfoForAfterTomorrow(vector<cVol> &vVol);

    // 14) Supprimer un vol d'un tableau donné ;
    static void supprimeVol(int volId, vector<cVol> &vVol);

    // set volId :
    int getVolId();
    // get volId :
    void setVolId(int volId);

    friend class cJson;
};

enum enMenuChoice
{
    eTestPassengerBelonging = 1,
    eAddPassengerToFlight,
    eModifyPassengerInfo,
    eModifyFlightDate,
    eTestFlightBelonging,
    eTestPassengerBelongingAgain,
    eAddFlight,
    eAddPassengerToFlightAgain,
    eDisplayAllFlights,
    eDisplayAllPassInfo,
    eDisplayPassengersUnder10,
    eDisplayFlightsForTomorrow,
    eDeleteFlight,
    eQuit
};

class cSystem
{

protected:
    // [1]   Tester si un passager appartient à un vol
    void sCheckIfPassInVol(vector<cVol> &vVols);

    // [2]   Ajouter un passager à un vol
    void sAddPassager(vector<cVol> &vVols);

    // [3]   Modifier les informations d'un passager
    void sEditPassInfo(vector<cVol> &vVols);

    //  [4]   Modifier la date d'un vol
    void sModifyVolDate(vector<cVol> &vVols);

    // [5]   Tester si un vol appartient :
    void sCheckVolInvVol(vector<cVol> &vVols);

    // [6]   Tester si un passager appartient a un vVols:
    void sCheckPassInVVols(vector<cVol> &vVols);

    // [7]   Ajouter un vol  :
    void sAddVol(vector<cVol> &vVols);

    // [8]   Ajouter un passager à un vol :

    void sAddPassToVol(vector<cVol> &vVols);

    // [9]   Afficher les informations de tous les vols :
    void sDisplayVvol(vector<cVol> &vVols);

    //  [10]  Afficher les vols d'un passager donné :
    void sDisplayPassInfo(vector<cVol> &vVols);

    //  [11]  Afficher les passagers ayant moins de 10 ans :
    void sDisplayMoreThan10(vector<cVol> &vVols);

    // [12]  affichier les vols pour  lendemain :
    void sDisplayVolsAfterTomorrow(vector<cVol> &vVols);

    // [13]  supprimier une vol  :
    void sDeleteVol(vector<cVol> &vVols);
};
class cFlightSystem : public cSystem
{
public:
    static void printSectionTitle(string title);
    void printMenu();
    void handelWithUserChoices(vector<cVol> &vVols);
    void StartSystem(vector<cVol> &vVols);
};

class cJson
{

    static json dateToJson(const cDate &date);
    static json avionToJson(const cAvion &avion);
    static json vPassagerToJson(const cPassager &passager);
    static json vPassagerToJson(const vector<cPassager> &vPassager);
    static json getVolsAsAJsonContent(const vector<cVol> &vVols);

    // Function to convert JSON to cDate
    static cDate jsonToDate(const json &dateJson);

    // Function to convert JSON to cAvion
    static cAvion jsonToAvion(const json &avionJson);

    // Function to convert JSON to cPassager
    static cPassager jsonToPassager(const json &passagerJson);

    // Function to convert JSON to vector<cPassager>
    static vector<cPassager> jsonToVPassager(const json &vPassagerJson);

    // Function to convert JSON to cVol
    static cVol jsonToVol(const json &volJson);

    // Function to read JSON content from a file and convert it to vector<cVol>

public:
    static void writeVolsToJsonFile(const vector<cVol> &vVols, const string &filename = ::fileJsonName);
    static vector<cVol> readVolsFromJsonFile(const string &filename = ::fileJsonName);
};

//------------------start declare  cPasagger operators :-------------------------------------------
istream &operator>>(istream &inp, cPassager &passager);
istream &operator>>(istream &inp, vector<cPassager> &vPassager);

ostream &operator<<(ostream &out, cPassager &passager);
ostream &operator<<(ostream &out, vector<cPassager> &vPassager);

// +=  operator :
void operator+=(vector<cPassager> &vPassager, const cPassager &addedPass);

//------------------start declare cDate operators :-------------------------------------------

// operator de saisir :
istream &operator>>(istream &inp, cDate &date);

// operator de affichage
ostream &operator<<(ostream &out, cDate &date);
bool operator>(const cDate &ob1, const cDate &ob2);
bool operator<(const cDate &ob1, const cDate &ob2);
bool operator==(const cDate &ob1, const cDate &ob2);
bool operator>=(const cDate &ob1, const cDate &ob2);
bool operator<=(const cDate &ob1, const cDate &ob2);

//------------------start  cAvion  operators :-------------------------------------------
// operator de saisir :
istream &operator>>(istream &inp, cAvion &avion);

// operator de affichage
ostream &operator<<(ostream &out, cAvion &avion);

//------------------start cVol  operators  :-------------------------------------------
// 8) Ajouter un vol à un tableau donné, tester son existence :
istream &operator>>(istream &inp, cVol &vol);
void operator+=(vector<cVol> &vVols, const cVol &vol);
// 10) Afficher les informations de tous les vols d'un tableau :
ostream &operator<<(ostream &out, vector<cVol> &vVol);

// ✨------------------start main ( ):-------------------------------------------
int main()
{

    // clear the screen before start the program :
    system("cls");
    // Set the console to UTF-8 mode (Windows specific)
#ifdef _WIN32
    system("chcp 65001 > null");
#endif

    vector<cVol> vVols = cJson::readVolsFromJsonFile();
    cFlightSystem sys;
    try
    {

        sys.StartSystem(vVols);
        cJson::writeVolsToJsonFile(vVols);
    }
    catch (runtime_error &e)
    {
        cin.clear();
        system("cls");
        cout << "Error : " << e.what() << endl;
    }
}
// ✨------------------end main ( ):-------------------------------------------

//------------------start cPasagger class :-------------------------------------------

// empty constructor :
cPassager::cPassager()
{
    idPass = -1;
    nom = "undefined";
    prenom = "undefined";
    age = 0;
    tele = "undefined";
    adresse = "undefined";
}

// parametrized constructor :
cPassager::cPassager(int idPass, string nom, string prenom, short age, string tele, string adresse)
{
    this->idPass = idPass;
    this->nom = nom;
    this->prenom = prenom;
    age < 0 ? this->age = 0 : this->age = age;
    this->tele = tele;
    this->adresse = adresse;
};

// -------------------------------main functions :-----------------------------

// operator de saisir :
istream &operator>>(istream &inp, cPassager &passager)
{
    passager.idPass = input::readIntegerNumber("Entrez l'ID du passager : ");
    passager.nom = input::readString("Entrez le nom : ");
    passager.prenom = input::readString("Entrez le prénom : ");
    passager.age = input::readIntegerInRange(0, 120, "Entrez l'âge : ");
    passager.tele = input::readString("Entrez le téléphone : ");
    passager.adresse = input::readString("Entrez l'adresse : ");

    cout << endl;
    return inp;
}
// operator de saisir d'un vector des passagers :

istream &operator>>(istream &inp, vector<cPassager> &vPassager)
{
    int i = 0;
    cout << "\n";
    cout << "   \n----------------------------["
         << "Start Pass"
         << "]---------------------------\n";
    for (cPassager &passager : vPassager)
    {
        cout << "-------------------------PASSAGER : [" << ++i << "]-------------------------\n";
        enIsPassInVPass PassInVPassStatus = enIsPassInVPass::notInVPass;
        int idPass;
        do
        {

            idPass = input::readPositiveIntegerNumber(" entere le Id de passager  : ");

            PassInVPassStatus = cPassager::isPassInVPass(idPass, vPassager);
            if (PassInVPassStatus == enIsPassInVPass::yesInVPass)
            {
                cout << "\nL'ID est déjà enregistré, essayez un autre ID : \n";
            }

        } while (PassInVPassStatus == enIsPassInVPass::yesInVPass);

        passager.readEditedPassInfo(idPass);
    }
    cout << "   ----------------------------["
         << "End Pass"
         << "]---------------------------\n\n";
    return inp;
}

// operator de affichage
ostream &operator<<(ostream &out, cPassager &passager)
{
    cout << "\n";
    cout << "     ID du passager : " << passager.idPass << "\n";
    cout << "     Nom : " << passager.nom << "\n";
    cout << "     Prénom : " << passager.prenom << "\n";
    cout << "     Âge : " << passager.age << "\n";
    cout << "     Téléphone : " << passager.tele << "\n";
    cout << "     Adresse : " << passager.adresse << "\n";

    cout << "\n";
    return out;
}

// operator d'affichage  d'un vector des passagers :
ostream &operator<<(ostream &out, vector<cPassager> &vPassager)
{
    int i = 0;
    cout << "   \n----------------------------["
         << "Start Pass"
         << "]---------------------------\n";
    for (cPassager &passager : vPassager)
    {
        cout << "     -------------------PASSAGER : [" << ++i << "]\n";
        cout << passager;
    }
    cout << "   ----------------------------["
         << "End Pass"
         << "]---------------------------\n\n";
    return out;
}

// get idPass functions :
int cPassager::getIdPass()
{
    return idPass;
}

// get age
short cPassager::getAge()
{
    return age;
}

// read edited pass values :
void cPassager::readEditedPassInfo(int passId)
{
    this->idPass = passId;
    nom = input::readString("Entrez le nom : ");
    prenom = input::readString("Entrez le prénom : ");
    age = input::readIntegerInRange(0, 120, "Entrez l'âge : ");
    tele = input::readString("Entrez le téléphone : ");
    adresse = input::readString("Entrez l'adresse : ");
}
// check  if pass in vPass :
enIsPassInVPass cPassager::isPassInVPass(int passId, vector<cPassager> &vPassager)
{

    for (int i = 0; i < vPassager.size(); i++)
    {

        if (vPassager[i].idPass == passId)
            return enIsPassInVPass::yesInVPass;
        if (vPassager[i].idPass == -1)
            return enIsPassInVPass::notInVPass;
    }
    enIsPassInVPass::notInVPass;
}
// +=  operator :
void operator+=(vector<cPassager> &vPassager, const cPassager &addedPass)
{

    if (cPassager::isPassInVPass(addedPass.idPass, vPassager) == enIsPassInVPass::yesInVPass)
    {

        cout << "\nLe passager existe déjà dans le vecteur de passagers : \n";
    }
    else
    {
        vPassager.push_back(addedPass);
    }
}
//------------------- end cPassager class -------------------------------------------
//------------------- start cDate class -------------------------------------------

// convert from  cDate to string function  :
string cDate::getDateToString()
{
    string stDay = to_string(days);
    string stMonth = to_string(month);
    string stYear = to_string(year);

    if (stDay.length() == 1)
        stDay = '0' + stDay;
    if (stMonth.length() == 1)
        stMonth = '0' + stMonth;

    return stDay + "/" + stMonth + "/" + stYear;
}

// constructor par default :
cDate::cDate()
{
    year = 0;
    month = 0;
    days = 0;
}

//  parametrized constructor :
cDate::cDate(int days, short month, short year)
{
    this->days = days;
    this->month = month;
    this->year = year;
}

// copy constructor :
cDate::cDate(const cDate &copy)
{
    this->days = copy.days;
    this->month = copy.month;
    this->year = copy.year;
}

// operator de saisir :
istream &operator>>(istream &inp, cDate &date)
{
    bool isValidDate = false;
    do
    {

        date.days = input::readPositiveIntegerNumber("");
        date.month = input::readPositiveIntegerNumber("");
        date.year = input::readPositiveIntegerNumber("");
        isValidDate = date.days > 31 || date.days < 1 || date.month > 12 || date.month < 1

                      || date < cDate::getCurrentDate();
        if (isValidDate)
            cout << "\n----[La date doit être supérieure ou égale à la date actuelle et valide : ] " << cDate::getCurrentTimeInfo() << "\n\nRentrer une autre fois [d/m/y] : ";

    } while (isValidDate);

    return inp;
}

// operator de affichage
ostream &operator<<(ostream &out, cDate &date)
{

    cout << date.getDateToString() << endl;
    return out;
}

// operator de comparaison :
bool operator==(const cDate &ob1, const cDate &ob2)
{

    return ob1.year==ob2.year && ob1.month == ob2.month && ob1.days==ob2.days; 
}

bool operator<(const cDate &ob1, const cDate &ob2)
{
    if (ob1.year < ob2.year)
        return true;
    if (ob1.year == ob2.year)
    {
        if (ob1.month < ob2.month) return true;

        if (ob1.month == ob2.month)
        {
            if (ob1.days < ob2.days)
                return true;
        }
    }
    return false;
}

bool operator>(const cDate &ob1, const cDate &ob2)
{
    if (ob1.year > ob2.year)
        return true;
     if (ob1.year == ob2.year)
    {
        if (ob1.month > ob2.month)  return true;
      if (ob1.month == ob2.month)
        {
            if (ob1.days > ob2.days)
                return true;
        }
    }
    return false;
}

bool operator>=(const cDate &ob1, const cDate &ob2)
{
    return !(ob1 < ob2);
}

bool operator<=(const cDate &ob1, const cDate &ob2)
{
    return !(ob1 > ob2);
}

// get the current date function :
cDate cDate::getCurrentDate()
{
    cDate currentDate;
    // get the nombre of second from (January 1, 1970)  date
    time_t t1 = time(0);

    // convert it to a tm strucutre :
    tm *gm = gmtime(&t1);

    currentDate.days = gm->tm_mday;
    //  month of year from 0 to 11  (start from from 0 not 1 you need to add 1 in logging)
    currentDate.month = gm->tm_mon + 1;
    // year since 1900 (you need to add 1900 in logging)
    currentDate.year = 1900 + gm->tm_year;

    return currentDate;
}

// get current time info(str) :
string cDate::getCurrentTimeInfo()
{

    // get the nombre of second from (January 1, 1970)  date
    time_t t1 = time(0);
    // get current time info :
    string timeInfo(ctime(&t1));

    return timeInfo;
}

// set day  :
void cDate::setDays(int days)
{

    this->days = days;
}

// get days :
int cDate::getDays()
{
    return this->days;
}
//------------------- End cDate class -------------------------------------------
//------------------- start cAvion class -------------------------------------------

// constructor  par default :
cAvion::cAvion()
{
    codeAv = 0;
    pilote = "undefined";
    modele = "undefined";
    capacite = 0;
    dateFab = cDate();
    nbrVols = 0;
}

// parametrized constructor :
cAvion::cAvion(int codeAv, string pilote, string modele, int capacite, cDate dateFab, int nbrVols) : dateFab(dateFab)
{
    this->codeAv = codeAv;
    this->pilote = pilote;
    this->modele = modele;
    this->capacite = capacite;
    this->nbrVols = nbrVols;
}

// operator de saisir :
istream &operator>>(istream &inp, cAvion &avion)
{
    avion.codeAv = input::readPositiveIntegerNumber("entere id d'avion  : ");
    avion.pilote = input::readString("entere le nom de  pilote  : ");
    avion.modele = input::readString("entere le modele  : ");
    avion.capacite = input::readPositiveIntegerNumber("enter la capacite [maximum de passager]  : ");
    cout << "entere la date de fabrication d'avion  [d/m/y]  : ";
    avion.dateFab.readDateFab();
    avion.nbrVols = input::readPositiveIntegerNumber("entere le nomber des vols associe  : ");
    return inp;
}

// operator de affichage
ostream &operator<<(ostream &out, cAvion &avion)
{

    cout << " Le code de l'avion    : " << avion.codeAv << "\n";
    cout << " Le nom du pilote      : " << avion.pilote << "\n";
    cout << " Le modèle de l'avion  : " << avion.modele << "\n";
    cout << " La capacité de l'avion : " << avion.capacite << "\n";
    cout << " La date de fabrication de l'avion : " << avion.dateFab << "\n";
    cout << " Le nombre de vols de l'avion : " << avion.nbrVols << "\n";

    return out;
}

// get capacite function :
int cAvion::getCapacite()
{
    return capacite;
}

//------------------- end cAvion class -------------------------------------------
//------------------- start cVol class -------------------------------------------

// empty constructor :
cVol::cVol()
{
    volId = 0;
}

// parametrized constructor :
cVol::cVol(int volId, cAvion avion, const vector<cPassager> &vPassager, cDate dateDep, cDate dateAr) : volId(volId), avion(avion), vPassager(vPassager), dateDep(dateDep), dateAr(dateAr)
{
}

// operator de saisir :
istream &operator>>(istream &inp, cVol &vol)
{
    vol.volId = input::readPositiveIntegerNumber("Entrer l'ID du vol : ");
    cin >> vol.avion;
    vol.vPassager.resize(vol.avion.getCapacite());
    cout << "\n";
    cin >> vol.vPassager;
    cout << "\n";
    cout << "Entrer la date de départ [d/m/y] : ";
    cin >> vol.dateDep;

    do
    {
        cout << "Entrer la date d'arrivée [d/m/y] : ";
        cin >> vol.dateAr;

        if (vol.dateDep > vol.dateAr)
            cout << "\n---La date n'est pas valide. La date d'arrivée doit être postérieure à la date de départ : \n\n";
    } while (vol.dateDep > vol.dateAr);

    return inp;
}
// read edit vol info :
// edit vol info :
void cVol::readEditVolInfo()
{
    cin >> avion;

    short nbrPassToAdd = input::readIntegerInRange(0, avion.getCapacite(), "Entrez le nombre de passagers à ajouter (Max [" + to_string(avion.getCapacite()) + "]): ");
    vPassager.resize(nbrPassToAdd);

    cin >> vPassager;

    cout << "Entrer la date de départ [d/m/y] : ";
    cin >> dateDep;

    do
    {
        cout << "Entrer la date d'arrivée [d/m/y] : ";
        cin >> dateAr;

        if (dateDep > dateAr)
            cout << "\n---Date non valide. La date d'arrivée doit être postérieure à la date de départ : \n\n";
    } while (dateDep > dateAr);
}
// operator de affichage
ostream &operator<<(ostream &out, cVol &vol)
{

    cout << " le id  de vol   : " << vol.volId << "\n";
    cout << vol.avion << "\n";
    cout << vol.vPassager << "\n";
    cout << " la date d'epart [d/m/y]     : " << vol.dateDep;
    cout << " la date d'arrivie [d/m/y]   : " << vol.dateAr;
    return out;
}

// 1) Tester si un passager appartient à un vol :
enPassInVol cVol::testPassInVol(int passId, int *index /*= nullptr*/)
{
    if (index == nullptr)
    {

        index = new int(-1);
    }

    for (int i = 0; i < vPassager.size(); i++)
    {
        if (vPassager[i].getIdPass() == passId)
        {
            *index = i;
            return enPassInVol::ePasInVol;
        }
    }

    return enPassInVol::ePasNotInVol;
}

// 2) Ajouter un passager à un vol, tester son existence :
void cVol::operator+=(cPassager passager)
{
    if (testPassInVol(passager.getIdPass()) == enPassInVol::ePasInVol)
    {
        cout << "\nLe passager existe déjà dans la base.\n";
    }
    else
    {
        vPassager.push_back(passager);
        cout << "\nLe passager a été ajouté avec succès.\n";
    }
}

// 3) Modifier les informations d'un passager d'un vol, tester son existence :
void cVol::editPassInfo(int passId)
{
    int indexPass;
    if (testPassInVol(passId, &indexPass) == enPassInVol::ePasInVol)
    {
        cout << "\nInformations du passager à modifier :\n";
        cout << vPassager[indexPass] << "\n";
        cout << "Saisir les nouvelles données du passager [" << passId << "]\n";

        vPassager[indexPass].readEditedPassInfo(passId);
    }
    else
    {
        cout << "---Ce numéro [" << passId << "] ne correspond à aucun passager.\n";
    }
}
// 4) Modifier la date d'un vol tout en testant si la nouvelle date saisie est superieure a la date actuelle :
void cVol::editDate()
{
    cDate newDateDep, newDateArr;

    cout << "\nDate de départ actuelle : " << dateDep << "\n";
    cout << "Date d'arrivée actuelle : " << dateAr << "\n";

    bool notValidDates = false;

    cout << "Entrer la nouvelle date de départ [d/m/y] : ";
    cin >> dateDep;

    do
    {
        cout << "Entrer la nouvelle date d'arrivée [d/m/y] : ";
        cin >> dateAr;

        if (dateDep > dateAr)
            cout << "\n---Date non valide. La date d'arrivée doit être postérieure à la date de départ : \n\n";
    } while (dateDep > dateAr);

    cout << "\n---La date a été modifiée pour le vol numéro [" << volId << "]\n";
}

// 5) Tester si un vol appartient à un tableau donné :
enCheckVolExist cVol::isVolExistInVol(int volId, const vector<cVol> &vVols, int *index /*= nullptr*/)
{
    if (index == nullptr)
    {

        index = new int(-1);
    }

    for (int i = 0; i < vVols.size(); i++)
    {
        if (vVols[i].volId == volId)
        {
            *index = i;
            return enCheckVolExist::eVolExist;
        }
    }
    return enCheckVolExist::eVolNotExist;
}

// 6) Tester si un passager appartient à un tableau donné :
enPassInVol cVol::isPassExistInVol(int volId, int passId, vector<cVol> &vVols)
{
    int targetVolIndex;
    if (isVolExistInVol(volId, vVols, &targetVolIndex) == enCheckVolExist::eVolNotExist)
        return enPassInVol::eVolNotExit;

    else
    {

        return vVols[targetVolIndex].testPassInVol(passId);
    }
}
// check passager in vols :
enPassInvVol cVol::isPassInvVols(int passId, vector<cVol> &vVol)
{

    for (cVol &vol : vVol)
    {

        if (isPassExistInVol(vol.volId, passId, vVol) == enPassInVol::ePasInVol)
            return enPassInvVol::ePassInvVol;
    }
    return enPassInvVol::ePassNotInvVol;
}

// 7) Ajouter un vol à un tableau donné, tester son existence :
void operator+=(vector<cVol> &vVols, const cVol &vol)
{

    if (cVol::isVolExistInVol(vol.volId, vVols) == enCheckVolExist::eVolExist)
    {

        cout << "\nLe vol existe déjà dans le système : \n";
    }

    else
    {
        vVols.push_back(vol);
    }
}

// 8) Ajouter un passager à un vol donné, tester son existence :
void cVol::addPassagerTovVol(int volId, int passId, vector<cVol> &vVols)
{
    int targetVolIndex;
    if (isVolExistInVol(volId, vVols, &targetVolIndex) == enCheckVolExist::eVolNotExist)
    {

        cout << "\nLe vol avec le numéro [" << volId << "] n'existe pas : \n";
    }
    else if (isPassExistInVol(volId, passId, vVols) == enPassInVol::ePasInVol)
    {

        cout << "\nLe passager avec le numéro [" << passId << "] existe déjà.\n";
    }
    else if (vVols[targetVolIndex].avion.getCapacite() <= vVols[targetVolIndex].vPassager.size())
    {
        cout << "\nLa capacité est insuffisante.\n";
        cout << "Capacité maximale [" << vVols[targetVolIndex].avion.getCapacite() << "]\n";
        cout << "Nombre de passagers déjà réservés : [" << vVols[targetVolIndex].vPassager.size() << "]\n";
    }

    else
    {
        cout << "\nEntrez les informations du passager : "

             << " [" << passId << "]-------------\n";
        cPassager tempPass;
        tempPass.readEditedPassInfo(passId);
        vVols[targetVolIndex] += tempPass;
    }
}

// 9) Afficher les informations de tous les vols d'un tableau :
ostream &operator<<(ostream &out, vector<cVol> &vVol)
{
    int i = 0;

    for (cVol &vol : vVol)
    {
        cout << "\n/---------------------------["
             << "Start Vol"
             << "]------------------------------/\n";
        cout << "--------------------------Vol : [" << ++i << "]\n";
        cout << vol << "\n";
        cout << "\n/---------------------------["
             << "Fin Vol"
             << "]------------------------------/\n\n";
    }

    return out;
}

// 10) Afficher les vols d'un passager donné ;
void cVol::afficheVolOfPass(int passId, vector<cVol> &vVol)
{

    int i = 0;
    int index;

    if (isPassInvVols(passId, vVol) == enPassInvVol::ePassNotInvVol)
    {

        cout << "\nle passager n'exist pas dans la base des  donnees :\n";
    }
    else
    {
        for (cVol &vol : vVol)
        {
            if (vol.testPassInVol(passId, &index) == enPassInVol::ePasInVol)
            {
                cout << "\n/---------------------------["
                     << "Start Vol"
                     << "]------------------------------/\n";

                cout << "--------------------------Vol : [" << ++i << "]\n";
                cout << vol << "\n";
                cout << "\n/---------------------------["
                     << "Fin Vol"
                     << "]------------------------------/\n\n";
            }
        }
    }
}
// 11) Afficher les passagers ayant moins de 10 ans :
void cVol::affichePassVolsWhereAgeMoreThan10(vector<cVol> &vVol)
{

    enPassInVol isExistPass = enPassInVol::ePasNotInVol;
    int i = 0;

    for (cVol &vol : vVol)
    {
        cout << "\n/---------------------------["
             << "Start Vol"
             << "]------------------------------/\n";
        cout << "--------------------------Vol  id: [" << vol.volId << "]\n";

        for (cPassager &passager : vol.vPassager)
        {

            if (passager.getAge() < 10)
            {
                isExistPass = enPassInVol::ePasInVol;
                cout << "-------------------------PASSAGER : [" << ++i << "]-------------------------\n";
                cout << passager << endl;
            }
        }
        if (isExistPass == enPassInVol::ePasNotInVol)
        {
            cout << "---Il n'existe aucun passager dans ce [Vol] \n";
        }
        cout << "\n/----------------------------["
             << "Fin Vol"
             << "]-------------------------------/\n\n";
    }
}

// 12) Afficher les informations des vols qui seront lancé le lendemain :
void cVol::afficheVolsInfoForAfterTomorrow(vector<cVol> &vVol)
{
    int i = 0;
    cDate tomorrowDate = cDate::getCurrentDate();
    tomorrowDate.setDays(tomorrowDate.getDays() + 2);

    enCheckVolExist volExist = enCheckVolExist::eVolNotExist;

    for (cVol &vol : vVol)
    {

        if (vol.dateDep == tomorrowDate)
        {
            volExist == enCheckVolExist::eVolExist;
            cout << "\n/---------------------------["
                 << "Start Vol"
                 << "]------------------------------/\n";
            cout << "--------------------------Vol : [" << ++i << "]\n";
            cout << vol << "\n";
            cout << "\n/---------------------------["
                 << "Fin Vol"
                 << "]------------------------------/\n\n";
        }
    }

    if (volExist == enCheckVolExist::eVolNotExist)
    {

        cout << "\n---Il n'existe aucun vol pour le lendemain  : \n";
    }
}

// 13) Supprimer un vol d'un tableau donné ;
void cVol::supprimeVol(int volId, vector<cVol> &vVol)
{

    int targetVolIndex;

    if (isVolExistInVol(volId, vVol, &targetVolIndex) == enCheckVolExist::eVolNotExist)
    {
        cout << "\nLe vol avec le numéro [" << volId << "] n'existe pas dans la base du système : \n ";
    }
    else
    {
        vVol.erase(vVol.begin() + targetVolIndex);
        cout << "\nLe vol avec le numéro [" << volId << "] a été supprimé avec succès.\n";
    }
}

// set volId :
int cVol::getVolId()
{
    return volId;
}
// get volId :
void cVol::setVolId(int volId)
{
    this->volId = volId;
}

//------------------- end cVol class -------------------------------------------
//------------------- start cSystem class -------------------------------------------
// [1]   Tester si un passager appartient à un vol
void cSystem::sCheckIfPassInVol(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
    }
    else
    {

        int VolId = input::readPositiveIntegerNumber("Entrez le numéro de vol : ");
        int passId = input::readPositiveIntegerNumber("Entrez le numéro de passager : ");
        cout << "\n----" << strPassInVol[cVol::isPassExistInVol(VolId, passId, vVols)] << "\n";
    }
}

// [2]   Ajouter un passager à un vol
void cSystem::sAddPassager(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
    }

    else
    {
        int VolId = input::readPositiveIntegerNumber("Entrez le numéro de vol : ");
        int passId = input::readPositiveIntegerNumber("Entrez le numéro de passager : ");

        cout << endl;

        cVol::addPassagerTovVol(VolId, passId, vVols);
    }
}

// [3]   Modifier les informations d'un passager

void cSystem::sEditPassInfo(vector<cVol> &vVols)
{

    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
    }
    else
    {
        int targetVolIndex = 0;
        int VolId = input::readPositiveIntegerNumber("Entrez le numéro de vol : ");
        int passId = input::readPositiveIntegerNumber("Entrez le numéro de passager : ");

        enCheckVolExist CheckVolExist = cVol::isVolExistInVol(VolId, vVols, &targetVolIndex);

        if (CheckVolExist == enCheckVolExist::eVolNotExist)
        {
            cout << strPassInVol[CheckVolExist] << "\n";
        }
        else
        {
            vVols[targetVolIndex].editPassInfo(passId);
        }
    }
}

//  [4]   Modifier la date d'un vol
void cSystem::sModifyVolDate(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }

    int targetVolIndex = 0;
    int VolId = input::readPositiveIntegerNumber("Entrez le numéro de vol : ");

    enCheckVolExist CheckVolExist = cVol::isVolExistInVol(VolId, vVols, &targetVolIndex);

    if (CheckVolExist == enCheckVolExist::eVolNotExist)
    {
        cout << strCheckVolExist[CheckVolExist] << "\n";
    }
    else
    {
        vVols[targetVolIndex].editDate();
    }
}
// [5]   Tester si un vol appartient :
void cSystem::sCheckVolInvVol(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }
    int targetVolIndex = 0;
    int VolId = input::readPositiveIntegerNumber("Entrez le numéro de vol : ");

    enCheckVolExist CheckVolExist = cVol::isVolExistInVol(VolId, vVols, &targetVolIndex);
    cout << "\n----" << strCheckVolExist[CheckVolExist] << "\n";

    if (CheckVolExist == enCheckVolExist::eVolExist)
    {
        char userWannaDisplayVol = input::readCharacter("\nVoulez-vous l'afficher ? [o/n] : ");
        if (userWannaDisplayVol == 'o' || userWannaDisplayVol == 'O')
        {
            system("cls");
            cFlightSystem::printSectionTitle("Tester si un vol appartient ");
            cout << vVols[targetVolIndex] << "\n";
        }
    }
}

// [6]   Tester si un passager appartient a un vVols:
void cSystem::sCheckPassInVVols(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }
    int passId = input::readPositiveIntegerNumber("Entrez le numéro de passager : ");

    cout << "\n----" << strPassInvVol[cVol::isPassInvVols(passId, vVols) == enPassInvVol::ePassNotInvVol] << "\n";
}
// [7]   Ajouter un vol  :
void cSystem::sAddVol(vector<cVol> &vVols)
{

    cVol tempVol;

    tempVol.setVolId(input::readPositiveIntegerNumber("Entrez le numéro de vol : "));

    if (cVol::isVolExistInVol(tempVol.getVolId(), vVols) == enCheckVolExist::eVolExist)
    {
        cout << "\nLe vol existe déjà dans le système.\n";
    }
    else
    {
        cout << "\nEntrez les informations du vol : [" << tempVol.getVolId() << "]-------------\n";
        tempVol.readEditVolInfo();
        vVols += tempVol;
        cout << "\nLe vol a été ajouté avec succès.\n";
    }
}

// [8]   Ajouter un passager à un vol :

void cSystem::sAddPassToVol(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }
    int VolId = input::readPositiveIntegerNumber("Entrez le numéro de vol : ");
    int passId = input::readPositiveIntegerNumber("Entrez le numéro de passager : ");

    cVol::addPassagerTovVol(VolId, passId, vVols);
}

// [9]   Afficher les informations de tous les vols :
void cSystem::sDisplayVvol(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }
    cout << vVols << endl;
}

//  [10]  Afficher les vols d'un passager donné :
void cSystem::sDisplayPassInfo(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }
    int passId = input::readPositiveIntegerNumber("ente le numero de passager  : ");
    cVol::afficheVolOfPass(passId, vVols);
}

//  [11]  Afficher les passagers ayant moins de 10 ans :
void cSystem::sDisplayMoreThan10(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }

    cVol::affichePassVolsWhereAgeMoreThan10(vVols);
}

// [12]  affichier les vols pour  lendemain :
void cSystem::sDisplayVolsAfterTomorrow(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }

    cVol::afficheVolsInfoForAfterTomorrow(vVols);
}

// [13]  supprimier une vol  :
void cSystem::sDeleteVol(vector<cVol> &vVols)
{
    if (vVols.size() == 0)
    {
        cout << "\n----Le système est vide. Vous devez d'abord ajouter des avions : \n ";
        return;
    }
    int VolId = input::readPositiveIntegerNumber("Entrez le numéro de vol : ");

    cVol::supprimeVol(VolId, vVols);
}
//------------------- end cSystem class -------------------------------------------
//------------------- start cFlightSystem class -------------------------------------------
//------------------- start cFlightSystem class -------------------------------------------

void cFlightSystem::printSectionTitle(string title)
{
    cout << "\n---------------------------------------\n";
    cout << "         " << title << "     \n";
    cout << "---------------------------------------\n\n";
}

void cFlightSystem::printMenu()
{
    cout << "\n";
    cout << "   [1]->   Tester si un passager appartient à un vol\n";
    cout << "   [2]->   Ajouter un passager à un vol\n";
    cout << "   [3]->   Modifier les informations d'un passager\n";
    cout << "   [4]->   Modifier la date d'un vol\n";
    cout << "   [5]->   Tester si un vol appartient\n";
    cout << "   [6]->   Tester si un passager appartient à un vol\n";
    cout << "   [7]->   Ajouter un vol\n";
    cout << "   [8]->   Ajouter un passager à un vol\n";
    cout << "   [9]->   Afficher les informations de tous les vols\n";
    cout << "  [10]->   Afficher les vols d'un passager donné\n";
    cout << "  [11]->   Afficher les passagers ayant moins de 10 ans\n";
    cout << "  [12]->   Afficher les vols pour le lendemain\n";
    cout << "  [13]->   Supprimer un vol\n";
    cout << "  [14]->   Quitter\n";
    cout << "\n----------------------------------\n";

    cout << " Coded by Majid Ayoub & Rochdi Mohamed Amine\n"
         << endl;
}

void cFlightSystem::handelWithUserChoices(vector<cVol> &vVols)
{

    int userChoice = enMenuChoice::eQuit;

    do
    {
        printMenu();
        userChoice = enMenuChoice(input::readIntegerInRange(enMenuChoice::eTestPassengerBelonging, enMenuChoice::eQuit, "Enterer votre choix : "));

        system("cls");

        switch (userChoice)
        {
        case eTestPassengerBelonging:
            printSectionTitle("Tester si un passager appartient à un vol");
            sCheckIfPassInVol(vVols);
            break;

        case eAddPassengerToFlight:
            printSectionTitle("Ajouter un passager à un vol");
            sAddPassager(vVols);

            break;

        case eModifyPassengerInfo:
            printSectionTitle("Modifier les informations d'un passager");
            sEditPassInfo(vVols);

            break;

        case eModifyFlightDate:
            printSectionTitle("Modifier la date d'un vol");
            sModifyVolDate(vVols);

            break;

        case eTestFlightBelonging:
            printSectionTitle("Tester si un vol appartient");
            sCheckVolInvVol(vVols);
            break;

        case eTestPassengerBelongingAgain:
            printSectionTitle("Tester si un passager appartient");
            sCheckPassInVVols(vVols);
            break;

        case eAddFlight:
            printSectionTitle("Ajouter un vol ");
            sAddVol(vVols);
            break;

        case eAddPassengerToFlightAgain:
            printSectionTitle("Ajouter un passager à un vol");
            sAddPassToVol(vVols);

            break;

        case eDisplayAllFlights:
            printSectionTitle("Afficher les informations de tous les vols");
            sDisplayVvol(vVols);
            break;

        case eDisplayAllPassInfo:
            printSectionTitle("Afficher les vols d'un passager ");
            sDisplayPassInfo(vVols);
            break;

        case eDisplayPassengersUnder10:
            printSectionTitle("Afficher les passagers ayant moins de 10 ans");
            sDisplayMoreThan10(vVols);
            break;

        case eDisplayFlightsForTomorrow:
            printSectionTitle("Afficher les vols pour lendemain");
            sDisplayVolsAfterTomorrow(vVols);
            break;

        case eDeleteFlight:
            printSectionTitle("Supprimier une vol");
            sDeleteVol(vVols);

            break;

        case eQuit:
            printSectionTitle("See You later  -) ");
            break;
        }

        if (userChoice != enMenuChoice::eQuit)
            cout << "\nAppuyez sur Entrée pour retourner au menu : ";
        system("pause>nul");

        system("cls");

        // udape file content :
        cJson::writeVolsToJsonFile(vVols);

    } while (userChoice != enMenuChoice::eQuit);
}
void cFlightSystem::StartSystem(vector<cVol> &vVols)
{

    handelWithUserChoices(vVols);
}
//------------------- end cFlightSystem class -------------------------------------------
//------------------- start cJson class -------------------------------------------
json cJson::dateToJson(const cDate &date)
{

    json dateObject;
    dateObject["days"] = date.days;
    dateObject["month"] = date.month;
    dateObject["year"] = date.year;

    return dateObject;
}

json cJson::avionToJson(const cAvion &avion)
{
    json avionJson = {
        {"codeAv", avion.codeAv},
        {"pilote", avion.pilote},
        {"modele", avion.modele},
        {"capacite", avion.capacite},
        {"dateFab", dateToJson(avion.dateFab)},
        {"nbrVols", avion.nbrVols}};
    return avionJson;
}

json cJson::vPassagerToJson(const cPassager &passager)
{

    json passagerObject;
    passagerObject["idPass"] = passager.idPass;
    passagerObject["nom"] = passager.nom;
    passagerObject["prenom"] = passager.prenom;
    passagerObject["age"] = passager.age;
    passagerObject["tele"] = passager.tele;
    passagerObject["adresse"] = passager.adresse;

    return passagerObject;
}
json cJson::vPassagerToJson(const vector<cPassager> &vPassager)
{
    json vPassObject;
    for (const cPassager &passager : vPassager)
    {
        vPassObject.push_back(vPassagerToJson(passager));
    }

    return vPassObject;
}

json cJson::getVolsAsAJsonContent(const vector<cVol> &vVols)
{
  json flights;
    

    json jsonArray;

    for (const auto &vol : vVols)
    {
        // Create a JSON object for each cVol
        json volObject;
        volObject["volId"] = vol.volId;
        volObject["avion"] = avionToJson(vol.avion);
        volObject["vPassager"] = vPassagerToJson(vol.vPassager);
        volObject["dateAr"] = dateToJson(vol.dateAr);
        volObject["dateDep"] = dateToJson(vol.dateDep);

        // Add the JSON object to the array
        jsonArray.push_back(volObject);
    }
 
 if(vVols.size()==0){ 
     jsonArray={}; 
    } 
   
    flights["flights"] = jsonArray;

    return flights;
}

void cJson::writeVolsToJsonFile(const vector<cVol> &vVols, const string &filename /*=::fileJsonName*/)
{
    // Convert vector<cVol> to JSON array
    json jsonArray = getVolsAsAJsonContent(vVols);

    // Write JSON content to file

    // Rocmine file
    string filePath = "../../WebPanel/" + filename;
    
    // Youbista file :
    // string filePath = "../files/" + filename;

    ofstream file(filePath, ios::trunc);
    if (file.is_open())
    {
        file << std::setw(4) << jsonArray << std::endl;
        file.close();
    }
    else
    {
        cout << "Error :" << filename << endl;
    }
}

cDate cJson::jsonToDate(const json &dateJson)
{
    
    return cDate(dateJson["days"], dateJson["month"], dateJson["year"]);
}

cAvion cJson::jsonToAvion(const json &avionJson)
{
    
    return cAvion(avionJson["codeAv"], avionJson["pilote"], avionJson["modele"],
                  avionJson["capacite"], jsonToDate(avionJson["dateFab"]), avionJson["nbrVols"]);
}

cPassager cJson::jsonToPassager(const json &passagerJson)
{
    
    return cPassager(passagerJson["idPass"], passagerJson["nom"], passagerJson["prenom"],
                     passagerJson["age"], passagerJson["tele"], passagerJson["adresse"]);
}

vector<cPassager> cJson::jsonToVPassager(const json &vPassagerJson)
{
    
    vector<cPassager> vPassager;
    for (const auto &passagerJson : vPassagerJson)
    {
        vPassager.push_back(jsonToPassager(passagerJson));
    }
    return vPassager;
}

cVol cJson::jsonToVol(const json &volJson)
{
    
    return cVol(volJson["volId"], jsonToAvion(volJson["avion"]),
                jsonToVPassager(volJson["vPassager"]), jsonToDate(volJson["dateDep"]), jsonToDate(volJson["dateAr"]));
}

vector<cVol> cJson::readVolsFromJsonFile(const string &filename /*=::fileJsonName*/)
{
    vector<cVol> vVols;

    // Rocmine file
    string filePath = "../../WebPanel/" + filename;
    
    // Youbista file :
    // string filePath = "../files/" + filename;

    ifstream file(filePath, ios::app);

    if (file.is_open())
    {
        if (!file.tellg())
        {

            json jsonArray;
            file >> jsonArray;
            json flights = jsonArray["flights"];
            // Convert JSON array to vector<cVol>9
            for (const json &flight : flights)
            {
                vVols.push_back(jsonToVol(flight));
            }
        }

        // clear the flag errors to continue using the file : []
        file.clear();
        file.close();
    }
    return vVols;
}
//---------------------- End cJson class -------------------------------------------
//---------------------✨Finsi Program ✨ -----------------------------------------