#include <iostream>
using namespace std;

// problem 48 :
/*
write  a program to read a loanAmount and ask you how many months you need to settle the loan then calculate the monthly installment amount 



*/

void getValues(float &loanAmount, float &manyMonths)
{

   cout << "enter the  loanAmount: ";
   cin >> loanAmount;

   if (cin.fail() || loanAmount < 0)
      throw runtime_error("invalid loanAmount value you should enter a  positive  digit :  ");

   cout << "enter  how many Months you need: ";
   cin >>manyMonths ;

   if (cin.fail() || manyMonths <= 0)
      throw runtime_error("invalid manyMonths value you should enter a  positive digit :  ");
}

float Calc(float loanAmount, float manyMonths)
{
   cout << loanAmount / manyMonths << "$" << endl;
}

int main()
{

   float loanAmount, manyMonths;

   try
   {
      getValues(loanAmount,manyMonths);
      Calc(loanAmount, manyMonths);
   }
   catch (runtime_error e)
   {

      cout << "Error :" << e.what() << endl;
   }

   return 0;
}