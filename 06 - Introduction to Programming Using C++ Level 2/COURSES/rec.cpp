
// step into: step by step  
// step over : run the line without enter into the details : ( like run a line without enter into the details of functions)
// step out : get out from a function if you entered 

//create your library :

/*

-first create a file with h extension : 
-then write the code of you library into using functions namespaces .. whatever you want : 
- now include your library in the main functions :
#include "libraryName.h" ;
-- and now you are able to use  the functions ... in you are library 
-- and also you can  using namespace  with your libraries  
*/

// ternary operator : condition ? expression1 : expression:---------------[-] 
// example : 
 5 < 6 ? cout<<"yes, 6 is grater than 5 " : cout<<" no, 6 is not  grater than 5 "

//  ranged loop :--------------------[-]
// for ( datatype  element :elements){// code}
//example :
int arr[] = {1, 2, 3, 4, 5, 6, 6, 7};

    for (int n : arr)
    {
        cout << n << " ";
    }

// bitwise and operator :  &  -------------[]
// Number 1 and Number 2 = > return a result 
// convert numbers 1 and 2  to binary  then  and do an and operator for each bit then convert the result to decimal and return it : 
//EXAMPLE : 
12 //00001100
25 //00011001 
R  //00001000 => 8 in decimal : 
cout<< (12 & 25);

// bitwise  or  operator :  &  -------------[]
// Number 1 and Number 2 = > return a result 
// convert numbers 1 and 2  to binary  then  and do an or operator for each bit then convert the result to decimal and return it : 
//EXAMPLE : 
12 //00001100
25 //00011001 
R  //00011101 => 29 in decimal : 
cout<< (12 | 25);



