#include<iostream>
#include "./lib/cInput.h"
using namespace std; 


int  main(){

    string  firstName=cInput::readString("enter your firstName : "); 
      short age=cInput::readPositiveIntegerNumber("enter your age : "); 

     cout<<"The first name : "<<firstName<<"\n";
     cout<<"The age : "<<age<<endl; 
    return 0; 
}