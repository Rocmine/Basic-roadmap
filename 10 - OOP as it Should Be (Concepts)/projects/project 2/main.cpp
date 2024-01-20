#include <iostream>
#include <string> 

// include string library :
#include "./lib/cString.h"
using namespace std;

string  charToString(char myChar) {
    return string(1, myChar);
}


int main()
{
 
  cString st1="hello world ";
 

cout<<cString::camelCase("hello world");

    
    return 0;
}
