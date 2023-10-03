
// main structure :--------------------------------------[-] : 

// include the main library : (iostream  input output steam) library :  
#include<iostream>
// main function  it's run automaticaly  : when the source code : 
int main(){

 return 0;  
}

 // case sensitive : --------------------------[-] :
// cpp is a main sensitive  language  => A capital  != a small 

// cout object function  : 
std::cout<<"text"; 

//new line :
std::cout<<"text \n "; 
// or :
std::cout<<"text"<<endl; 


// the difference  between endl : 
/*
"endl" is a stream manipulator that is used to insert a newline character into an output stream and flush the 
stream's buffer. Flushing the buffer means that any data that is stored in the buffer is written to the output 
device (such as the screen or a file).
*/

// \n don't clear the buffer  : (flush the buffer) 
// endl auto  clearing  to the  buffer : 

// combine   between  \n && endl to improve the performance of your program : 

//literal types :


/*
literals are fixed values used to represent data
 -we can not assign different values to literal
-integer literals, floating point literals, characters literals, escape sequences literals, characters literals
-escape literals are used to print double quotation, single quotation, back slash, tab space, end line

integer literals :  
1- decimal 
2- octal 
3- hexadecimal 

floating point literals 

characters 
escape sequences literals \n \\ \t  \' \a audio bell 
*/ 


// variable : 
dataType variableName=Value; 


// fundamentals : int(integral type) , float(floating type) , double(double) ,bool(boolean type ),string (string type) , void , wide character(wchar_T)=> unicode 

// derived : function, array , pointer , reference 

// user defined  class ,structure , union ,enum , type def 


// datatype => : type 
//variableName => identifier 
// value => literal  || constant || value 

// input : to get Value from the  user : 
cin>>variableName 

// type modifiers : --------------------------[-]
// you can use it with int double char :
// default singed : 
// the last byte in the left is used the to store the signe of number like -5 .... 
// when you use the unsigned keyword means the left byte will be allocated for number rather than signe(-) this means we will gain more space : 
//  assume we have an  unsigned int variable   the max value of the bit in the last byte is   2^31=2147483648 😑
signed; 
unsigned; 
short;  // for int : -32768  to 32767      2byte  
long; // it's the same  for int 
long long ;//  8 byte  for int   || long double  12 byte   float and double are  always  signed value ; 

// char 1byte  
// string 12byte 
// void 0 byte 

int v1; 
signed int v1;

short int v4; 
short v5; 

unsigned short int v6; 
unsigned short v7; 

signed long int v12;
long v10; 

unsigned long long v13; 
long double v14;

signed char v15; 
char v16; 
unsigned char v17; 


double distance=56E12; // means 56 + 12 zero  or 56*10^12
cout<<distance<<endl; 

short d=3434233; // Error! out of range : 
cout<<d<<endl; 

unsigned int a=-10; // error! can only store positive number : 
cout<<a<<endl; 

// range of DATA TYPE  : 
CHAR_MIN;CHAR_MAX;
INT_MIN;INT_MAX; 
LONG_MIN;LONG_MAX; 
LLONG_MIN;LLONG_MAX;
DBL_MIN;DBL_MAX; 
LDBL_MIN;LDBL_MAX; 
FLT_MIN;FLT_MAX;  
ULLONG_MAX; // UNSIGNED LONG LONG INT RANGE : ..... 


//struct : 
struct stAddress
{
string stAddress; 
string PoBox; 

}; 

struct stOwner{

string fullName; 
string Phone; 
stAddress address; 
};

struct car
{
    string brand; 
    string model; 
    int year; 
    stOwner owner; 
};



// enum : 
/*
an enumeration is a distinct type whose value is restricted to a range of values : 

Enum is a group of values "constants" and we could say: It is a select list of values.
Enum = Laptop {cpu, ssd, ..... xn-1} and we use is to simplify the select options and values and to organize our data in the software.

enum enEnglishCertificates
{
  TOEFL, IELTS, DUILINGO
};
I deal with data and we store number values

*/


// casting enum : 
int c=2; 
enum Color{Red,Green,Yellow}; 
Color myColor=(Color)c; 





#include<iostream>
using namespace std; 

enum Color{Red,Green,Yellow,Blue};
enum Direction{North,South,East,West};
enum Week{sat,Sun,Mon,Tue,Wed,Thu,Fri};
enum Gender{Male,Female};
enum Status{Single,Married}; 


int main(){

Color MyColor=Color::Red; 
Direction MyDirection=Direction::East; 
Week Today=Week::Mon; 
Status MyStatus=Status::Married; 

    return 0; 
}

// example 2 : 
#include <iostream>
using namespace std;

enum Color
{
    Red,
    Green,
    Yellow,
    Blue
};
enum Direction
{
    North,
    South,
    East,
    West
};
enum Week
{
    sat,
    Sun,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri
};
enum Gender
{
    Male,
    Female
};
enum Status
{
    Single,
    Married
};

struct ContactInfo
{

    string Email;
    string PhoneNumber;
};

struct Address
{
    string City;
    string Country;
    string strict;
    short postalCode;
};
struct SalaryInfo
{
    float MonthlySalary;
    float YearlySalary;
};

struct SocialStat
{
    Gender Gender;
    Status isMarried;
};
struct User
{
    string Name;
    unsigned short Age;
    SocialStat SocialStat;
    Address UserAddress;
    ContactInfo contacts;
    SalaryInfo AllSalary;
};

int main()
{

    User ob1;
    ob1.Name = "ayoub";
    ob1.Age = 19;

    ob1.SocialStat.Gender = Gender::Male;
    ob1.SocialStat.isMarried = Status::Married;

    ob1.UserAddress.City = "rabat";
    ob1.UserAddress.Country = "morocco";
    ob1.UserAddress.postalCode = 11233;
    ob1.UserAddress.strict = "amal 2";

    ob1.contacts.Email = "ayoubmajid71@gmal.com";
    ob1.contacts.PhoneNumber = "06641343432";

    ob1.AllSalary.MonthlySalary = 5000;
    ob1.AllSalary.YearlySalary = ob1.AllSalary.MonthlySalary * 12;

    cout << "------------User----------------" << endl;
    cout << "basic informations  :\n";
    cout << " Name            :  " << ob1.Name << "\n";
    cout << " Age             :  " << ob1.Age << "\n\n";

    cout << "address informations :\n";
    cout << " City            :  " << ob1.UserAddress.City << "\n";
    cout << " country         :  " << ob1.UserAddress.Country << "\n";
    cout << " strict          :  " << ob1.UserAddress.strict << "\n";
    cout << " postal code     :  " << ob1.UserAddress.postalCode << "\n\n";

    cout << "contacts informations :\n";
    cout << " email           :  " << ob1.contacts.Email << "\n";
    cout << " phone           :  " << ob1.contacts.PhoneNumber << "\n\n";

    cout << "salary informations  :\n";
    cout << " monthly salary  : " << ob1.AllSalary.MonthlySalary << "\n";
    cout << " yearly salary   :  " << ob1.AllSalary.YearlySalary << "\n";

    cout << "social Status :\n";
    cout << " Gender            :" << (ob1.SocialStat.Gender == Gender::Male ? "Male" : "Female") << "\n";
    cout << " Status            :" << (ob1.SocialStat.isMarried == Status::Married ? "Married" : "single") << "\n";

    cout << "----------------------------------" << endl;

    return 0;
}



// structure with enums : 
#include <iostream>
using namespace std;

enum enColor
{
    Red,
    Green,
    Yellow,
    Blue
};
enum enGender
{
    Male,
    Female
};
enum enMaritalStatus
{
    Single,
    Married
};

struct stAddress
{
    string StreetName;
    string BuildingNo;
    string PoBox;
    string ZipCode;
};

struct stContactInfo
{
    string Phone;
    string email;
    stAddress Address;
};

struct stPerson
{

    string FirstName;
    string LastName;
    stContactInfo contactInfo;
    enMaritalStatus MaritalStatus;
    enGender Gender;
    enColor FavoriteColor;

    int printPersonFullName()
    {
        cout << "Name : " << this->FirstName << endl;
        cout << "Last Name :" << this->LastName << endl;
    }
};

int main()
{

    stPerson person1;

    person1.FirstName = "Ayoub";
    person1.LastName = "Majid";
    person1.contactInfo.email = "ayoub@gmail.com";
    person1.contactInfo.Phone = "23223423423";

    person1.contactInfo.Address.StreetName + "abo";
    person1.contactInfo.Address.PoBox = "12312";
    person1.contactInfo.Address.BuildingNo = "mafds";
    person1.contactInfo.Address.ZipCode = 12112;

    person1.Gender = enGender::Male;
    person1.MaritalStatus = enMaritalStatus::Single;

    person1.printPersonFullName();

    return 0;
}


// casting :  

// include string library : 
//string to int : 
int intVariable=stoi(stringVariable);

// string to float : 
float floatVariable=stoi(stringVariable); 

// string to double  : 
double doubleVariable=stod(stringVariable); 

// int to string : 
string str=to_string(num); 

// ignore enter character : 
cin.ignore(1,'\n'); 


// change the color of the screen 
// red : 
system("color 4F"); 
 
/*
   0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua

*/

// convert from string to *char :
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // Using c_str()
    const char* charPtr1 = str.c_str();
    
    // Using data()
    const char* charPtr2 = str.data();
    
    // Printing the C-style strings
    std::cout << "Using c_str(): " << charPtr1 << std::endl;
    std::cout << "Using data(): " << charPtr2 << std::endl;
    
    return 0;
}
