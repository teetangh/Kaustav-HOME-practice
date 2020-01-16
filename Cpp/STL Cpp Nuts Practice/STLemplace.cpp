// TOPIC: Emplace In STL

// 1. All the containers supports insert and emplace operation to store data.
// 2. Emplace is used to construct object in-place and avoids unnecessary copy of objects.
// 3. Insert and Emplace is equal for premetive data types but when we deal with heavy objects
//    we should use emplace if we can for efficiency.

#include <iostream>
#include <set>
using namespace std;

class A
{
public:
    int x;
    A(int x = 0) { cout << "Constructor" << endl; };
    A(const A &rhs)
    {
        x = rhs.x;
        cout << "Copy Constructor " << endl;
    };
};

bool operator<(const A &lhs, const A &rhs) { return lhs.x < rhs.x; }

int main()
{
    cout << "Insert fucntion :" << endl;
    // Creating set of objects of class A
    set<A> Set;
    // Inserting elements(OBJECTS) into Set A using insert or Emplace function
    Set.insert(A(1));
    // Object created unnecsearily   twice with insert approach
    A a2(10);
    Set.insert(a2);
    cout << "Emplace fucntion :" << endl;
    Set.emplace(10);

    for (auto &elm : Set)
        cout << elm.x << endl;
    return 0;
}