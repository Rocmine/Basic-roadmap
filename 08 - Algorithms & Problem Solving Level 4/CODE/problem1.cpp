/* 
 problem 1 : 
 write a program to read a number and print the text of that number 
*/
#include<iostream>
#include "myLib.h"
using namespace std; 






string convertFromNumberToText(int number){
 
 if(number==0) return ""; 

  if(number>=1 && number<=19){
 string arr[]={"","one","two","there","foure","six","seven","eight","nine","thin"}; 

 return  arr[number];  
  }
  if(number>=20 && number<=99){

 string arr[]={"","","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}; 

 return arr[number/10] + " " + convertFromNumberToText(number%10);   
 }

if(number>=100 &&  number<=999){
 string arr[]={"","One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};

 
 return  arr[number/100] +" "+ convertFromNumberToText(number/10); 
}

if(number>=1000 && number<=9999){
 
string arr[]={"One Thousand", "Two Thousand", "Three Thousand", "Four Thousand", "Five Thousand", "Six Thousand", "Seven Thousand", "Eight Thousand", "Nine Thousand"}; 

return arr[number/1000] + " " + convertFromNumberToText(number/100); 
}
else{
 


}

 }



 int main(){

int number=input::readIntegerNumber("enter a Number?"); 
cout<<convertFromNumberToText(number)<<endl;  
 


    return 0 ;
 }


