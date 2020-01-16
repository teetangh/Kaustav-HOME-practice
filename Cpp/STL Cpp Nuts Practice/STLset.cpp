// fTOPIC: std::vector

// NOTES:
// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

// ELEMENT ACCESS
// at(), [], front(), back(), data()

// MODIFIERS:
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

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