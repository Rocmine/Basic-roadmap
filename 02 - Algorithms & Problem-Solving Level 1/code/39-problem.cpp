#include<iostream>
#include<string>
#include<iomanip>
using namespace std; 

// problem 39 : 

/*
write a program to read a totalBill and cashPaid and calculate the remainder to be paid back : 
*/


void getValues(float &totalBill,float &cashPaid ){
 
cout<<"enter the totalBill: "; 
cin>>totalBill; cin.ignore(); 
if(cin.fail()) throw runtime_error("invalid totalBill value you should enter a positive digit :"); 
cout<<"enter the cashPaid: "; 
cin>>cashPaid;
if(cin.fail()) throw runtime_error("invalid cashPaid value you should enter a positive digit :"); 

}

void Evaluate(const int totalBill , const int cashPaid){
 
 throw float(cashPaid-totalBill); 
}

int main(){

 float totalBill,totalPaid;
  
  try{
    
getValues(totalBill,totalPaid); 
Evaluate(totalBill,totalPaid); 

  }catch(runtime_error e){

     cout<<"Error :"<<e.what()<<endl;
  }catch(float result){
  
  cout<<"your Remainder is  :"<<fixed<<setprecision(2)<<result<<endl; 
  }
    return 0; 
}