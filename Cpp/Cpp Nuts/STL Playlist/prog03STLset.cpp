// TOPIC: std::set

// NOTES:
// 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in set then we will have to provide 
//    compare function so that set can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// It store unique elements and they are stored in sorted order (A/D)


#include <iostream>
#include <set>
// #include <string>
#include <functional>
using namespace std;

class Person
{
public:
    float age;
    string name;

    bool operator<(const Person &rhs) const { return age < rhs.age; }
    bool operator>(const Person &rhs) const { return age > rhs.age; }
};

int main()
{
    cout << "Set" << endl;
    set<Person> Set = {{30, "Rupesh"}, {25, "Hitesh"}, {22, "John"}};
    for (const auto &e : Set)
        cout << e.age << " " << e.name << endl;

    cout << "mySet" << endl;
    set<int> mySet;
    mySet.insert({1, 2, 3, 4, 5, 1, 2, 3, 4, 5});
    for (const auto &e : mySet)
        cout << e << endl;

    cout << "Set2" << endl;
    set<int, std::greater<>> Set2 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    for (const auto &e : Set2)
        cout << e << endl;

    return 0;
}