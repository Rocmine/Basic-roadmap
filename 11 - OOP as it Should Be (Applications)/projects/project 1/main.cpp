#include <iostream>
#include "./lib/cUtil.h"
using namespace std;

struct stPerson
{
    string firstName;
    string lastName;
};

int main()
{

    vector<int> vArr = cUtile::GetVectorWithRandomValues(5);

    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    vector<int> result = vec1 + vec2;

    string x = "kamal";
    string y = "nice";
    swap(x, y);
    cout << x << "\n " << y << endl;

    stPerson p1;
    p1.firstName = "ayoub";
    p1.lastName = "mj";

    stPerson p2;
    p2.firstName = "amine";
    p2.lastName = "kamali";

    swap(p1, p2);

    cout << "p1 firstname : " << p1.firstName << endl;
    cout << "p2 firstName : " << p2.firstName << endl;

    cUtile::ShuffleVector(result);
    cout << cUtile::GetVectorWittNKey();
    return 0;
}