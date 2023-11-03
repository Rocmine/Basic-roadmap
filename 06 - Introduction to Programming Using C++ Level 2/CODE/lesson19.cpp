#include<iostream>
using namespace std; 
// home work :

/*
write a programs to do the following :

.Using Recursion :

 .program To print numbers from m down to N;
 . program to calculate power N^M

*/

// the program one :

void printNumberFromMDownN(int m, int n)
{

    // base case :
    if (m < n)
        return;

    // Recursion case :
    cout << m << " ";
    printNumberFromMDownN(--m, n);
}

// calculate N^M
int calculateNPowerM(int m, int n, int result = 1)
{

    // base case :
    if (n == 0)
        return result;

    // recursion case :
    result *= m;
    calculateNPowerM(m, --n, result);
}


int main(){

cout<<"Assignment 1 : \n"; 
printNumberFromMDownN(20,10);


cout<<"Assignment 2 : \n"; 
cout<<calculateNPowerM(5,0); 

}
