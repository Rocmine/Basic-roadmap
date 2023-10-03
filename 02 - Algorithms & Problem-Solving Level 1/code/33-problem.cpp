

// problem 33 :
/*

write a program to ask the user to enter
.Grade
then print the grade as follows :

90-100 print A:

80-89 print B:

70-79 print C:
 60 69 print D:
50 59 print E
otherwise print F
*/

#include <iostream>
using namespace std;

int getGrade()
{
    int grade = 0;
    cout << "enter your grade : ";
    cin >> grade;
    if (cin.fail())
        throw runtime_error("invalid grade value you should enter a digit :");

    if (grade > 100 || grade < 0)
        throw string("you should enter a value between 0 and 100");

    return grade;
}

void throwResult(int grade)
{

    if (grade >= 90)  throw string("A");
    else if (grade >= 80)  throw string("B");
    else if (grade >= 70)  throw string("C");
    else if (grade >= 60)  throw string("D");
    else if (grade >= 50)  throw string("E");
    else                   throw string("F");
}

int main()
{

    int grade = 0;

    try
    {

        grade = getGrade();
        throwResult(grade);
    }
    catch (runtime_error e)
    {

        cin.clear();
        cin.ignore();
        cout << "Error :" << e.what() << endl;
    }
    catch (string grade)
    {

        cout << "your Grade is :" << grade << endl;
    }

    return 0;
}