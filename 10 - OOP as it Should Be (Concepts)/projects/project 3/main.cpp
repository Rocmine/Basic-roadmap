#include<iostream> 
#include "./lib/cDate.cpp"

int main(){
 
 cDate date1(10,12,2003);
 cout<<"enter the  the date : "; 
 cin>>date1; 
  
 cout<<date1;  
 date1.printCalender(); 
    return 0; 
}