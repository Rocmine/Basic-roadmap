

//problem 30 : 
/*
write a program to calculate factorial of N! 
note user should only enter positive number ,otherwise reject  it and ask it enter again : 
*/

#include <iostream>
using namespace std;

int getNumber()
{
int number = 0;
    cout << "enter a number  :";
    cin >> number;

    return number;
}

int  isNotValid( int number)
{
    if (cin.fail())   throw runtime_error("invalid number :");
    if (number < 0 || number > 24) return 1; 
      
}

int factorial(int n)
{

    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {

    unsigned long long fact = 1;

        for (int i = 2; i <= n; i++)
        {
            fact =int(fact* i);
        }
        return fact;
    }
}

int main()
{

    try
    {  
       long  int number=0; 
        bool stat=false;


     do{
        
         number = getNumber();
         system("cls"); 
         stat=isNotValid(number);
         if(stat)  cout<<"you should enter a number between 0 and  24"<<endl;
         
     }while(stat);
        
    
      unsigned long long fact = factorial(number);
        cout<<sizeof(fact)<<endl; 
        cout << "the factorial is :" << fact << endl;
    }
    catch (runtime_error e)
    {
        cerr << "Error " << e.what() << endl;
    }


    return 0;
}