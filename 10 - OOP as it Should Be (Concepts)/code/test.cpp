#include <iostream>
using namespace std;

class person
{

protected:
  class c
  {

    string name;
    public :
    string lastName;

  public:
    void print()
    {
      cout << "the name : " << name << "\n";
      cout << "the last name  : " << lastName << "\n";
    }
  };

public:
  c a;
  string km;
};

class e : public person
{

  c e2;
   void test(){
      
   }
};

int main()
{
  e p1;
  p1.a.print();

  return 0;
}
