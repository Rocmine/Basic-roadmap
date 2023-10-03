
// problem 14: 
/*
write a program to ask the user to enter 
.number 1 
.number 2 
then print the two numbers ,then swap the two numbers and print them 
*/


#include<iostream>
using namespace std; 

int main(){
 int num1,num2; 
 cout<<"entre two numbers "; 
 cin>>num1>>num2; 
  
  //first technique : 
  cout<<"first technique"<<endl; 
  int temp=num1; 
  num1=num2;
  num2=temp; 
  cout<<num1<<endl<<num2<<endl; 
  cout<<"second technique "<<endl; 
  num1+=num2; 
  num2=num1-num2; 
  num1-=num2; 
 cout<<num1<<endl<<num2<<endl; 


    return 0; 
}