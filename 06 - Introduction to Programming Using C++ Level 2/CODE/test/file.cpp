#include <iostream>
#include "myLib.h"
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;
#include <ctime>

// #pragma warning(disable:4996);

/*

now->tm_sec : // seconds of minutes from 0 to 61
now->tm_min : //  minutes of hour from 0 to 59
now->tm_hour : //  hours of day from 0 to 24
now->tm_mday : //  days of month from 0 to 31
now->tm_mon : //  month of year from 0 to 11  (start from from 0 not 1 you need to add 1 in logging)
mow->tim_year : // years since 1900 (you need to add 1900 in logging)
now->tm-wday : number of days since sunday :
now->tm_yday : number of days since january
now->tm_isdst : hours of daylight saving time (time zone +1 +2 .. );


*/

