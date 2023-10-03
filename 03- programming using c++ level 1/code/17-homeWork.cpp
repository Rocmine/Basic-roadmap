#include<iostream>
using namespace std; 

//lesson 43 : 

void Swap(int &Num1 , int &Num2){
  
  Num1+=Num2; 
  Num2+Num1-Num2;
  Num1=Num1-Num2;  
}

int main(){
int Num1;
int Num2; 
Num1=100;
Num2=200;  
 

 cout<<"th value of Num1   is : "<<Num1<<"\n"; 
 cout<<"the value of Num2 is  :"<<Num2<<"\n"; 

swap(Num1,Num2); 
cout<<"\nAfter calling the swap function : \n"; 

 cout<<"th value of Num1   is : "<<Num1<<"\n"; 
 cout<<"the value of Num2 is  :"<<Num2<<endl; 



return 0; 
}