#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// #31 : pow  2 3 4 
int getNumber()
{
    int Number = 0;
    cout << "enter a number  :";
    cin >> Number;

    return Number;
}
void powPrinter(const int number)
{
    int a = number * number;
    int b = number * number * number;
    int c = number * number * number * number;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

// #32 :  pow(n,M); 

int GetNumberAndPower(int &number, int &m)
{
    cout << "enter  number  :";

    cin >> number;
    cout << "enter M :";
    cin >> m;
    return number;
}
int power(int a, int b)
{   
    if(b==0) return 0 ; 
    int res = a;
    for (int i = 1; i < b; i++)
    {
        res *= a;
    }
    return res;
}


// # 33 :
/*

write a program to ask the user to enter
.Grade
then print the grade as follows :

90-100 print A:

80-89 print B:

70-79 print C:
 60 69 print D:
50 59 print E
otherwise print F
*/
int ReadGrade()
{
    int grade=0;
    do{
  grade = 0;
    cout << "enter your grade : ";
    cin >> grade; 

    }while(grade > 100 || grade < 0); 
 

    return grade;
}
char GetDegree(int grade)
{

    if (grade >= 90)  cout<< string("A");
    else if (grade >= 80)  return 'B';
    else if (grade >= 70)  return 'C';
    else if (grade >= 60)  return 'D';
    else if (grade >= 50)  return 'E';
    else                   return 'F';
}

void PrintDegree(char Degree){

cout<<Degree<<endl; 

}

//#34 commission : 
float GetPercentage(int Ts = 0)
{
    if (Ts >= 500000 && Ts <= 1000000)
        return   0.02;
    if (Ts >= 100000)
        return   0.03;
    if (Ts >= 50000)
        return    0.05;
    if (Ts >= 1000)
        return  0.01;
    else
        return   0;
}

float CalculateTotalCommission(float Ts){

return GetPercentage(Ts)*Ts; 


}
void PrintTCom(float TCom){
    cout<<"the total Commission  :"<<TCom<<endl; 
}


//#35: Piggy bank Calculator :  I'm so tired 


int main(){


// #31 
//powPrinter(getNumber()); 

//#32: 
// int Number=0,M=0;
// GetNumberAndPower(Number,M); 
// cout<<"The result is "<<power(Number,M); 


//#33: 
// PrintDegree(GetDegree(ReadGrade())); 
//#34: 
PrintTCom(CalculateTotalCommission(getNumber()));

    return 0; 
}