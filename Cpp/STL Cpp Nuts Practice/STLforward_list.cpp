// TOPIC: forward_list In STL

// 1. This is single linked list what we know from C programming language.
// 2. Why forward_list why not single_list ?
// 3. We should use this class instead of traditional single linked list because
//    a. Well tested
//    b. Bunch of available function
// 4. Few Available Operations
//    operator =, assign, front, empty, max_size, clear, insert_after, emplace_after, reverse, sort, merge
//    splice_after, unique, remove, remove_if, resize

#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    // Declaration and Initialisation
    forward_list<int> list1 = {5, 4, 6, 2};
    forward_list<int> list2 = {7, 6, 1, 9};

    // Insertion using begin() and before_begin()
    list1.insert_after(list1.before_begin(), 8);
    list1.insert_after(list2.begin(), 2);

    // Printing the elements
    cout << "list1 elements" << endl;
    for (auto &elm : list1)
        cout << elm << endl;
    cout << "list2 elements" << endl;
    for (auto &elm : list2)
        cout << elm << endl;

    //Sorting
    list2.sort();

    // Reverse Sorting
    list1.sort();
    list1.reverse();

    // Merging requires the lists to be individually sorted
    // OR else merge becomes Concatenation
    list1.sort();
    list2.sort();
    // forward_list<int> list3 = list1.merge(list2);        //Doesnt work
    forward_list<int> list3;
    list3.merge(list1);
    list3.merge(list2);

    cout << "Merged list3 elements" << endl;
    for (auto &elm : list3)
        cout << elm << endl;

    // splice_after
    forward_list<int> list4 = {0, 3, 5, 1, 7};
    forward_list<int> list5 = {1, 8, 4, 3, 2};

    // Results after splicing
    cout << " Results after splicing" << endl;
    list4.splice_after(list4.begin(), list5);
    for (auto &elm : list4)
        cout << elm << endl;

    // Size or distance of List
    cout << "size of list4 " << std::distance(list4.begin(), list4.end()) << endl;

    // forward list iterator
    forward_list<int> list6 = {1, 2, 3, 4, 5};
    forward_list<int> list7 = {6, 7, 8, 9, 10, 1};

    auto it = list7.begin();
    it++;
    list6.splice_after(list6.begin(), list7, it, list7.end());

    // Printing afterSplicing
    cout << "List6 elements" << endl;
    for (auto &elm : list6)
        cout << elm << endl;

    // remove and removeif with lamba functions
    list6.sort();
    cout << "List6 elements after SORTING" << endl;
    for (auto &elm : list6)
        cout << elm << endl;

    list6.remove(8);
    cout << "List6 elements after removing 8" << endl;
    for (auto &elm : list6)
        cout << elm << endl;

    list6.remove_if([](int n) {
        return n > 4;
    });
    cout << "List6 elements after removing if n>4" << endl;
    for (auto &elm : list6)
        cout << elm << endl;

    list6.unique();
    cout << "List6 elements after removing duplicates" << endl;
    for (auto &elm : list6)
        cout << elm << endl;
}
