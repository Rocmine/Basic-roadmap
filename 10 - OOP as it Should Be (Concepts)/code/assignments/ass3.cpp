#include <iostream>
#include "lib/cPerson.h"
#include "lib/cEmployee.h"
#include "lib/cDeveloper.h"
using namespace std;




int main()
{
    cDeveloper d1(1, "ayoub", "majid", "mj@gmail.com", "5445", "ajile amine ", "A22C", 5004.43, "c++");
    d1.print();
    return 0;
}