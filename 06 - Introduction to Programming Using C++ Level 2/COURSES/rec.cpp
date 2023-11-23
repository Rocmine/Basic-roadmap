
// step into: step by step  

// step over : run the line without enter into the details : 
//( like run a line without enter into the details of functions)

// step out : get out from a function if you entered 

//create your library :

/*

-first create a file with h extension : 
-then write the code of you library into using functions namespaces .. whatever you want : 
- now include your library in the main functions :
#include "libraryName.h" ;
-- and now you are able to use  the functions ... in you are library 
-- and also you can  using namespace  with your libraries  
*/

// ternary operator : condition ? expression1 : expression:---------------[-] 
// example : 
 5 < 6 ? cout<<"yes, 6 is grater than 5 " : cout<<" no, 6 is not  grater than 5 "

//  ranged loop :--------------------[-]
// for ( datatype  element :elements){// code}
//example :
int arr[] = {1, 2, 3, 4, 5, 6, 6, 7};

    for (int n : arr)
    {
        cout << n << " ";
    }

// bitwise and operator :  &  -------------[]
// Number 1 and Number 2 = > return a result 

// convert numbers 1 and 2  to binary  then  and do an and operator 
//for each bit then convert 
//the result to decimal and return it : 

//EXAMPLE : 
12 //00001100
25 //00011001 
R  //00001000 => 8 in decimal : 
cout<< (12 & 25);

// bitwise  or  operator :  |  -------------[]
// Number 1 and Number 2 = > return a result 

// convert numbers 1 and 2  to binary  then  and do an or operator for each bit then 
//convert the result to decimal and return it : 

//EXAMPLE : 
12 //00001100
25 //00011001 
R  //00011101 => 29 in decimal : 
cout<< (12 | 25);



// functions declaration Vs definition : 


//functions declaration : 
dataType functionName(arguments); 


// function definition : 
dataType functionName(arguments){
    // code 
}


// default parameters : 
dataType functionName(argument1=defaultValue , argument2=defaultValue); 


// function overloading : 
/*
it's a type of polymorphism : 
you can set many functions with the same name but change arguments type and return 

and when you call the function the compiler decide which  is one when compiled depends 
on  convenient  function with   parameters passed to the function  
*/
// example : 

double mySum(double a, double b)
{
    return a + b;
}

int mySum(int a, int b)
{
    return a + b;
}

int mySum(int a, int b, int c)
{
    return a + b + c;
}

int mySum(int a, int b, int c, int d)
{
    return a + b + c + d;
}


// call stack/call hierarchy : 
//example : 
void function4(){

    cout<<"hi I'm function4"; 
}
void function3(){

    function4(); 
}
void function2(){

  function3(); 
}
void function1(){
function2(); 
}

int main()
{

    function1(); 
}


// vs functions tips : 

// Recursion : 
/*
it's means that function will call itself 

We have to approach of  solving a problem 

-- iterative :  using for loops  

-- recursion  : using callback stack (to call the function itself multiple times )
*/
dataType functionName(argument1=defaultValue , argument2=defaultValue){

// base case : 
code 

//recursion  case :
code  
}


// example : 
void printNumbersFrom0To4(int n)
{
    // base case :
    if (n ==5)
        return;

    // recursion case :
    cout << n << " ";
    printNumbersFrom0To4(n +1);
}

int main(){
 cout<<"recursion :"<<endl;
printNumbersFrom0To4(0); 

}


// static variable : 

/*
Static variables in C++ are variables that are associated with a class or a 
function rather than with a specific instance of the class or a local scope 
of the function


Static member variables are often used to keep track of shared data among instances of a class.
Static local variables are used when you need to maintain state across function calls.
*/
// example : 

// the number variable not gonna destroyed from the memory it will retain its value 
// number initalized  just in the first call 
void myFunc(){

static int number=1; 
cout<<"Value of Number :"<<number<<"\n"; 
number++; 

}
int main()
{
myFunc();
myFunc();
myFunc();
myFunc();

}
// result : 1 2 3 4 

// automatic Variables : 
auto VariableName=value; 

// register Variables : (save variable in  registry increase the speed ) 
register VariableName=value;



//   format (printf) : 
 // %d integer 
 // %f float 
 // %c character 
 // %s string 
 //%.2f print two decimal numbers : 
 // or" %.*f" ,2
 
// width specification : 
// "%0*d ",NumberOfZeroReplaced ,Variable

//example : 
//  result 0012 => replace two digits  in the left  by 0 :
printf("the value of num is %0*d",4,num); 

// .* : number of decimal  digit  || for %c it's replaced by number of spaces  (1  => 0 space )
// 0* : number of  replaced (if empty) 0 in the left of number 

// example : 
 // 7  of 0 (replace if empty )   in the left  and 3 decimal digit
printf("the value of num is %0*.*f",7,3,num); 
//result : 012.000


// setw manipulator : 
cout<<setw(value)<<"test"; 
/*
in this code you will You will reserve a amount of space for the next text after setw() manipulator : 
very useful when handel with tables or when you wanna create formatted  text : 
*/

// example : 
cout<<setw(9)<<"---------"<<"|"<<setw(32)<<"--------------------------------"<<"|"<<setw(9)<<"---------"<<"|\n"; 
cout<<setw(9)<<"  Code   "<<"|"<<setw(32)<<"              Name              "<<"|"<<setw(9)<<"  Mark   "<<"|\n"; 
cout<<setw(9)<<"---------"<<"|"<<setw(32)<<"--------------------------------"<<"|"<<setw(9)<<"---------"<<"|\n"; 
cout<<setw(9)<<""<<"|"<<setw(32)<<""<<"|"<<setw(9)<<""<<"|\n";
cout<<setw(9)<<" c1 "<<"|"<<setw(32)<<" introduction to programming 1 "<<"|"<<setw(9)<<"13 "<<"|\n"; 
cout<<setw(9)<<" c2 "<<"|"<<setw(32)<<" foundations 1 "<<"|"<<setw(9)<<"18 "<<"|\n"; 
cout<<setw(9)<<" c3 "<<"|"<<setw(32)<<" cpp  level 1 "<<"|"<<setw(9)<<"20 "<<"|\n"; 
cout<<setw(9)<<"---------"<<"|"<<setw(32)<<"--------------------------------"<<"|"<<setw(9)<<"---------"<<"|\n";  




// two dimensional Arrays : 

dataType ArrayName[NbrLines,nbeColumns]={
     {value1,valu2,value3..},
     {value1,valu2,value3..},
     {value1,valu2,value3..}
     ... 
} 
// example : 
void print2DArray(int arr[][10], int l, int c)
{

    for (int i = 0; i < l; i++)
    {
        cout << "\n"
             << setw(2);
        for (int j = 0; j < c; j++)
        {

            cout << (j == 0 ? "|" : "") << setw(3) << arr[i][j] << setw(2) << setw(3) << (j == c - 1 ? "|" : "");
        }
    }
    cout << "\n\n";
}


// vectors Declaration and initialization : 
/*
Vectors are a dynamic array-like data structure in C++ that are part of the Standard 
Template Library (STL). Vectors provide several advantages over traditional arrays,
 including dynamic sizing, automatic memory management, 
 and a variety of built-in functions for manipulating and accessing their elements.

vectors : dynamic  Array  (stack data structure)

#include<vector>

with functions you can use pass by reference  or value 
*/
// syntax : 
vector <dataType> variableName={Value1,value2,...}; 

//initialize with default value 
vector<dataType> vName(NumberOfElement,intialeValue);

// example : 
vector <int> vNumbers={10,12,13,14,15}; 

for(int &number :vNumbers){
    cout<<number<<" ";  
}

//4. Accessing Elements:
int value = vName[index];
int value = vName.at(index);


// resize vector : 
vName.resize(20, 0); 



// add an element  to a vector : 
vectorName.push_back(Value); 

// remove the last element from vector : 
vectorName.pop_back(); 

// vector of structure :
vector <stName> vName; 

//example : 
struct stEmployee
{
    string firstName;
    string lastName;
    float salary;
};

void printVector(vector<stEmployee> &vEmployees)
{
    for (stEmployee &employee : vEmployees)
    {

        cout << "\n";

        cout << "First Name : " << employee.firstName << "\n";
        cout << "Last Name : " << employee.lastName << "\n";
        cout << "salary : " << fixed << setprecision(2) << employee.salary << "\n";

        cout << "\n";
    }
}

// vector functions :  -------- 

// check if vector  is empty or not 
vName.empty();  

// return number  of vector elements : 
vName.size(); 
// or : 
vName.capacity(); 

// clear a vector :
vName.clear(); 

// return the first  element : 
vName.front(); 


// return the last  element :
vName.back();  

// begin function : 
vName.begin(); 
/*
begin(): The begin() function returns an iterator pointing 
to the first element in the container.
*/

// end function : 
/*
end(): The end() function returns an iterator pointing to one past the last element in the
 container. It does not point to an actual element in the container but serves as a 
 sentinel to indicate the end of the range
*/




sort(vName.begin(), vName.end()); // Sort elements in ascending order
reverse(vName.begin(), vName.end()); // Reverse the order of elements
vName.erase(vName.begin() + 2); // Erase an element at index 2

/*
push_back(): Adds an element to the end.
pop_back(): Removes the last element.
clear(): Removes all elements.
insert(): Inserts elements at a specific position.
erase(): Erases elements at a specific position.
empty(): Checks if the vector is empty.
size(): Returns the number of elements.
resize(): Resizes the vector.
reserve(): Allocates memory for a specified number of elements.
begin() and end(): Used for iteration.
max_size(): Returns the maximum possible number of elements.
capacity(): Returns the current capacity.

*/

// different between size and capacity : 
/*
size(): This function returns the number of elements that are currently stored in the container.
 It represents the actual size of the container based on the elements that have been added to it.

capacity(): This function returns the current storage capacity of the container.
 It is the maximum number of elements that the container can hold before it needs
  to reallocate memory. The capacity may be greater than or equal to the size. 
  Containers like std::vector dynamically allocate memory as elements are added,
   and the capacity reflects the size of the allocated memory.

For example, if you have a std::vector with a capacity of 10 and a size of 5,
 it means the vector currently holds 5 elements, and there is room for 5 more
  elements before it needs to reallocate memory to increase capacity. 
  The capacity is useful for optimizing memory management, especially in scenarios
   where you plan to add a large number of elements to a container to minimize 
   reallocation overhead.
*/


// call byRef / byVal :  Review 
/*

by value  : 
create new variable then copy the value of basic var in the main 

by ref : 
create a new alias for th basic var in the main (when change value of new alis the basic change also)
*/

//example : 

void  byVal(int x){

    x++;
}

void  byRef(int &x){
    x++; 
}


// create Reference : 
int main(){
int a=10; 
int &k=a; 
++k; 
cout<<"the value of k is :"<<k<<endl<<"the value of a is :"<<a; 
}

// what is pointer : 
int main(){

int k=12; 
int *x=&k;

//access to value : 
cout<<*x; 

// access to address : 
cout<<x; 

// access to address of pointer :
cout<<&x; 

// edit the value of pointed variable  :
cout<<++(*x); 

}

// dereferencing pointer  =>  *P 


//common mistakes when with pointer:

// pointers vs References 
/*
you can assign  reference just one time in runtime 

but pointer you can change the address multiple times 

*/

// call by reference using pointer : 
// example : 

void swap(int &n1, int &n2){

int temp=n1;
n1=n2;
n2=temp;
}

void swapPtr(int *n1, int *n2){

int temp=*n1;
*n1=*n2;
*n2=temp;
}

// pointers and arrays : 
int main(){
int arr[4]={10,12,15,20}; 

int *ptr=arr; 

// address are : 
cout<<ptr<<"\n"; 
cout<<ptr+1<<"\n"; 
cout<<ptr+2<<"\n"; 
cout<<ptr+3<<"\n"; 


// values are : 

cout<<*(  ptr   )<<"\n"; 
cout<<*(ptr +1)<<"\n"; 
cout<<*(ptr +2)<<"\n"; 
cout<<*(ptr +3)<<"\n"; 
}


// pointers and structures :
struct stEmployee
{
string name;
float Salary; 
};  
int main(){
stEmployee Employee1 ,*ptr; 
Employee1.name="ayoub";
Employee1.Salary=5000;


ptr=&Employee1; 

cout<< (*ptr).name<<endl;
cout<< ptr->Salary<<endl;

}

// pointer to void : 
// it's a pointer  that handel with all data types 

// but when you wanna to access to  the value of a void pointer you need  add a static casting 
// syntax : 
int main(){
*((type*)ptrName); 
// or 
*(static_cast<type*>(ptrName));
}

// example  :
int main()
{

void *ptr; 

ptr = new int(12); 

cout<< *((int*)ptr)<<endl; 

ptr = new float(3.33); 
cout<< *( static_cast<float*>(ptr))<<endl; 


}

// memory management  new and delete :

// dynamically allocate memory : 
type ptrName= new type(value); // value is optional 

// deallocate the memory : (after new allocation  you need add new    delete ); 
delete ptrName; 


// arrays  new and delete : 

// create dynamic array : 
type ptrName = new type [size]; 

// delete dynamic array :
delete [] ptrName;


// example : 
int main()
{

    float arr[100];
    int length = 0;

    cout << "please enter how many students you want?\n";
    cin >> length;

    float *ptr = new float[length];

    for (int i = 0; i < length; i++)
    {

        cout << "student " << i + 1 << " :";
        cin >> *(ptr + i);
    }

    for (int i = 0; i < length; i++)
    {
        cout << "student " << i + 1 << "  Mark : " << *(ptr + i) << endl;
    }

    delete[] ptr;
}

// vectors Access elements 
vName.at(index); 
// or 
vName[index]; 

// vectors iterator : 
/*
In C++, an iterator is an object that allows you to traverse elements in a container (e.g., a 
vector, list, or map) and access the elements sequentially without exposing the underlying
 data structure. Iterators provide a way to access and manipulate container elements,
  regardless of the specific container type. C++ offers several types of iterators 
  to work with different containers, and they are an essential part of the 
   Template Library (STL).
*/
vector<type>::iterator iterName; 
int main()
{

    vector<int> num{1, 2, 3, 4, 5};

    //  declare iterator
    vector<int>::iterator iter;

    for (iter = num.begin(); iter != num.end(); iter++)
    {
        cout << *iter << " ";
    }
}


// exception handling : 

/*

Error handling is a crucial aspect of programming that involves managing and responding 
to unexpected or erroneous conditions that can occur during the execution
 of a program. Proper error handling is essential for creating robust and
  reliable software. Here are some key concepts and techniques related to
   error handling in programming:
*/

// type of errors : 
/*
Compile-Time Errors: These are detected by the compiler and prevent the program 
from being built. Common examples include syntax errors and type mismatches.

Run-Time Errors: These occur during program execution, such as dividing by zero,
 accessing invalid memory, or attempting to open a file that doesn't exist.

Logic Errors: These are not detected by the compiler, but they result in incorrect
 program behavior. Logic errors can be challenging to identify and fix because 
 the program runs without error messages 
*/

try {
    // Code that may throw an exception
} catch (ExceptionType1 e1) {
    // Handle ExceptionType1
} catch (ExceptionType2 e2) {
    // Handle ExceptionType2
}
// throw : 
throw exceptionClassName("Error"); 

//Standard Exception Classes:
/*
The C++ Standard Library provides several standard exception classes 
derived from std::exception, such as 
std::runtime_error, 
std::logic_error, 
and std::out_of_range,
 among others.
*/

// example : 
#include <iostream>
#include <stdexcept>
int main() {
    try {
        int a = 10;
        int b = 0;
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        int result = a / b;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}


// string object : ------------------
#include<string>
#include<iostream>
int main(){

string str; 
// get length
 str.length(); 

// return index value : 
str.at(value); 

// push str 
str.append("addedText"); 

// insert at position :
str.insert(position,"addedStr");

//  get subString :
str.substr(startPosition,length);

// push character :
str.push_back('character'); 

// pop character : 
str.pop_back(); 

// find str :  (return position of str)
str.find("str"); 
// check if exist 
if(str.find("str")== str.npos){
// code   
}

// clear string 
str.clear(); 
}

// cctype some functions : 

// convert character from small to capital : 
tolower('character'); 


// convert character from  capital to small: 
toupper('character');  


// check if is small 
islower('character'): 

// check if is  capital 
isupper('character'); 

// check if is a special character : !"#%&'()*/:;<=>?@[\]^_`{|}~" 
ispunct('character'); 

// check if is digit : 
isdigit('character'); 

// write files write mode : 
/*
you need to include file library : 
#include<fstream> 
To work with files in C++, you need to include the <fstream> header, which provides classes 
and functions for file input and output. The key classes provided by
 this header are ifstream for reading, ofstream for writing,
  and fstream for both reading and 
*/

// create instance from fstream class : 
fstream fileName; 


// open file ; 
f1.open("fileName.extension",ios::modeName); 

//concat  modes 
f1.open("fileName.extension",ios::modeName1 | ios::modeName2);



/*
open modes : 
ios::out => "w" write mode  +> create new file if not exist and clear content 
iso::app => "a" append mode +> don't clear the old content  && create of is not exist
ios::in =>  "r" read mode =>  read from file  if exist 
ios::binary => "b"  binary mode =>  for binary file operations
*/


// check if file is opened or not : 
if(fileName.is_open()){
    // code 
}

// clear file : 
fileName.clear(); 

// close file ; 
fileName.close(); 

// write out on file :
fileName<<"youText..."; 
// rread  one element 
fileName>>variableName; 

//readAllLIne
getline(fileName,strvariableName);


// example : 
// read line by line from file :
void printFileContent(string fileName)
{

    fstream myFile;

    myFile.open(fileName, ios::in);

    if (myFile.is_open())
    {

        string line;

        while (getline(myFile, line))
        {
            cout << line << endl;
        }

        myFile.close();
    }
    else
    {
        cout << "file not exist :";
    }
}

// load data from a file to a vector  : 
void loadDataFromFileToVector(string fileName, vector<string> &vFileContent)
{

    fstream f1;
    f1.open(fileName, ios::in);

    if (f1.is_open())
    {

        string line;

        while (getline(f1, line))
        {
            vFileContent.push_back(line);
        }

        f1.close();
    }
    else
    {

        cout << "file not exist";
    }
}

void printVectorContent(const vector<string> &vContent)
{

    for (string vElement : vContent)
    {
        cout << vElement << endl;
    }
}

//save vector to file :
void saveVectorToFile(string fileName, vector<string> &vFileContent)
{

    // declare an file instance from fstream object :
    fstream file;

    // open the file in the write mode :
    file.open(fileName, ios::out);

    //  check if the file opened  correctly :
    if (file.is_open())
    {

        // write the vector to the file :

        for (string vElement : vFileContent)
        {
            file << vElement << endl;
        }

        file.close();
    }
    else
    {
        cout << "there was a  problem  while opening the file : check the file name of extension\n";
    }
}

// delete record from file : 
void deleteRecordFromFile(string fileName, string record)
{

    vector<string> vContent;

    loadDataFromFileToVector(fileName, vContent);

    // remove the record from the file :

    for (string &vElement : vContent)
    {
        if (vElement == record)
        {
            vElement = "";
        }
    }

    saveVectorToFile(fileName, vContent);
}


// update record from file :
void updateRecordFromFile(string fileName, string record, string updateRecord)
{

    vector<string> vContent;

    loadDataFromFileToVector(fileName, vContent);

    // remove the record from the file :

    for (string &vElement : vContent)
    {

        if (vElement == record)
        {
            vElement = updateRecord;
        }
    }

    saveVectorToFile(fileName, vContent);
}
 

//  error handling : 
fail(): This function checks whether any of the error flags is set, indicating a 
failure during the last operation. It is useful for general error checking.

bad(): This function checks whether a non-recoverable error has occurred,
 typically due to a stream corruption. If this flag is set, the stream is considered unusable.

eof(): This function checks whether the end-of-file (EOF) 
marker has been reached in the stream. 
It's useful to determine if you have read to the end of the file'.

//example : 
std::ifstream inFile("input.txt");
if (!inFile) {
    std::cerr << "Failed to open the input file." << std::endl;
} else {
    int number;
    if (inFile >> number) {
        std::cout << "Read number: " << number << std::endl;
    } else {
        if (inFile.eof()) {
            std::cout << "End of file reached." << std::endl;
        } else if (inFile.bad()) {
            std::cerr << "A non-recoverable error occurred." << std::endl;
        } else if (inFile.fail()) {
            std::cerr << "Error during reading." << std::endl;
        }
    }
    inFile.close();
}

// local /utc dataTime : 
#include <ctime>
// #pragma warning(disable:4996);
int main()
{

    time_t t = time(0); // get time now

    char *dt = ctime(&t); // convert in string form

    cout << "local date time is :" << dt << endl;

    tm *gmtm = gmtime(&t); // convert now to struct for utc date/time

    dt = asctime(gmtm); // convert from structure to string

    cout << "utc date and time is :" << dt;
}

// datetime Structure : 
/*

now->tm_sec : // seconds of minutes from 0 to 61 
now->tm_min : //  minutes of hour from 0 to 59 
now->tm_hour : //  hours of day from 0 to 24 
now->tm_mday : //  days of month from 0 to 31 
now->tm_mon : //  month of year from 0 to 11  (start from from 0 not 1 you need to add 1 in logging) 
mow->tim_year : // year since 1900 (you need to add 1900 in logging)
now->tm-wday : number of days since sunday :
now->tm_yday : number of days since january 
now->tm_isdst : hours of daylight saving time (time zone +1 +2 .. ); 


*/
int main()
{

    time_t t = time(0); // get time now

    tm *now = localtime(&t); // return a structure

    cout << "year :" << now->tm_year + 1900 << endl;
    cout << "month :" << now->tm_mon + 1 << endl;
    cout << "day :" << now->tm_mday << endl;
    cout << "hour :" << now->tm_hour << endl;
    cout << "min :" << now->tm_min << endl;
    cout << "second :" << now->tm_sec << endl;
    cout << "week day  :" << now->tm_wday << endl;
    cout << "year day   :" << now->tm_yday << endl;
    cout << "time zone ()   :" << now->tm_isdst << endl;

    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", now);
    cout << "Current time: " << buffer << endl;
}



