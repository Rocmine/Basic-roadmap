#include <iostream>

using namespace std;

class cPerson
{
    private : 
     short id; 

public:
    string firstName;
    string lastName;

    string getFullName()
    {

        return firstName + lastName;
    }
    int getId(){
         return id; 
    }
};

int main()
{

    cPerson p1;
    cout<<p1.getFullName()<<endl; 
 cout<<p1.getId()<<endl;

 string s1; 


    return 0;
}