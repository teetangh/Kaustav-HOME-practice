// TOPIC: std::vector

// NOTES:
// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

// ELEMENT ACCESS
// at(), [], front(), back(), data()

// MODIFIERS:
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Declarations
    std::vector<int> arr1;
    std::vector<int> arr2{5, 20};
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::vector<int> arr4{1, 2, 3, 4, 5};

    // Accessing Elements
    arr2[3] = 10;
    cout << arr2[3] << endl;
    arr2.push_back(47);
    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << ' ';
    cout << endl;

    arr3.at(3) = 30;
    for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << ' ';
    cout << endl;

    // Inserting,Size and Capacity
    cout << "VEC1" << endl;
    vector<int> Vec;
    for (int i = 0; i < 32; i++)
    {
        Vec.push_back(i);
        cout << "Size:" << Vec.size() << " Capacity: " << Vec.capacity() << endl;
    }
    // Reserve
    cout << "VEC2" << endl;
    vector<int> Vec2;
    Vec2.reserve(100);
    for (int i = 0; i < 16; i++)
    {
        Vec2.push_back(i);
        cout << "Size:" << Vec2.size() << " Capacity: " << Vec2.capacity() << endl;
    }

    // Constant Vector
    std::vector<int> vec;
    const std::vector<int> const_vec;

    vec.begin();  //iterator
    vec.cbegin(); //const_iterator

    const_vec.begin();  //const_iterator
    const_vec.cbegin(); //const_iterator

    // Reverse iterator
    std::vector<int> myvector(5);
    int i = 0;

    std::vector<int>::reverse_iterator rit;
    for (rit = myvector.rbegin(); rit != myvector.rend(); rit++)
        *rit = ++i;

    cout << "myvector contains" << endl;
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
        cout << ' ' << *it;
    cout << endl;

    return 0;
}