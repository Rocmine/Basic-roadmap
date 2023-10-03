/*
write a program to ask the user to enter 
.first name 
.second name
the print the full name on screen 
*/

#include<iostream>
using namespace std; 

int main(){
     string firstName; 
     string lastName; 
     string FullName; 
    cout<<"enter the first name :";
    cin>>firstName; 
    cout<<"enter the second name :"; 
    cin>>lastName; 
    FullName=firstName+" "+lastName; 
    cout<<"the full name is "<<FullName<<endl;  
    
}