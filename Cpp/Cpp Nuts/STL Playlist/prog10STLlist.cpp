// TOPIC: list In STL

// 1. This is double linked list what we know from C prgramming language.
// 2. List is sequence container that allow non-contiguous memory allocation.
// 3. List is faster compared to other sequence containers (vector, forward_list, deque) in terms of
//    insertion, removal and moving elements in any position provided we have the iterator of the position.
// 4. We should use this class instead of traditional double linked list because
//    a. Well tested
//    b. Bunch of available function
// 5. Few Available Operations
//    operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back, pop_back, push_front
//    pop_front, reverse, sort, merge, splice, unique, remove, remove_if, resize.

#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Declaring and Initialisation
    list<int> list1 = {5, 2, 4, 6, 2};
    list<int> list2 = {7, 6, 1, 9};

    // Iteration through the lists
    for (auto &elm : list1)
        cout << elm << ' ';
    cout << endl;

    for (auto &elm : list2)
        cout << elm << ' ';
    cout << endl;

    // Sorting
    list1.sort();
    list2.sort();

    cout << "After sorting both the lists" << endl;
    for (auto &elm : list1)
        cout << elm << ' ';
    cout << endl;

    for (auto &elm : list2)
        cout << elm << ' ';
    cout << endl;

    cout << "After splicing" << endl;
    list<int> list3 = list1;
    list3.splice(list3.begin(), list2);
    for (auto &elm : list3)
        cout << elm << ' ';
    cout << endl;

    // Weird unique function(Removes only adjacent duplicates)
    cout << "applying unique function on list4" << endl;
    list<int> list4 = {7, 7, 7, 6, 1, 9, 2, 7, 7, 7, 8};
    list4.unique();
    for (auto &elm : list4)
        cout << elm << ' ';
    cout << endl;
    // Better Trick
    cout << "applying unique function on list5 after sorting" << endl;
    list<int> list5 = {7, 7, 7, 6, 1, 9, 2, 7, 7, 7, 8};
    list5.sort();
    list5.unique();
    for (auto &elm : list5)
        cout << elm << ' ';
    cout << endl;
}