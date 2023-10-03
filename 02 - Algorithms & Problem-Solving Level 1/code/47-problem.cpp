#include <iostream>
using namespace std;

// problem 47 :
/*
write  a program to read a loanAmount and monthly Payment and calculate how many months need to settle the loan :



*/

void getValues(float &loanAmount, float &monthlyPayment)
{

   cout << "enter the  loanAmount: ";
   cin >> loanAmount;

   if (cin.fail() || loanAmount < 0)
      throw runtime_error("invalid month value you should enter a  positive  digit :  ");

   cout << "enter  the  monthlyPayment ";
   cin >> monthlyPayment;

   if (cin.fail() || monthlyPayment <= 0)
      throw runtime_error("invalid month value you should enter a  positive digit :  ");
}

float Calc(float loanAmount, float monthlyPayment)
{
   cout << loanAmount / monthlyPayment << " months" << endl;
}

int main()
{

   float loanAmount, monthlyPayment;

   try
   {
      getValues(loanAmount, monthlyPayment);
      Calc(loanAmount, monthlyPayment);
   }
   catch (runtime_error e)
   {

      cout << "Error :" << e.what() << endl;
   }

   return 0;
}