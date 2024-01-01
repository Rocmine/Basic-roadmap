#include"lib/myLib.h" 
#include<iostream>
using namespace std; 
int main(){

int num1=input::readIntegerNumber("enter a number : "); 
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
int num2=input::readIntegerNumber("enter a number : "); 

cout<<num1<<" "<<num2<<endl; 
return 0;
}