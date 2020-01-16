// TOPIC: Multimap In C++

// NOTES:
// 1. Multimap is an associative container that contains a sorted list of key-value pairs,
//    while permitting multiple entries with the same key.
// 2. It store key value pair in sorted order on the basis of key (assending/decending).
// 3. Data structure used in multimap is not defined by standard, but red-black tree is assumed by most of the people.
// 4. Lookup: count, find, contains, equal_range, lower_bound, upper_bound
// 5. We dont have at() and [] functions to get element like we had in std::map.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    // Creating the Multimap
    std::multimap<char, int, std::less<>> Multimap;
    Multimap.insert(std::pair<char, int>('a', 1));
    Multimap.insert(make_pair('a', 2));
    Multimap.insert(make_pair('a', 3));
    Multimap.insert(make_pair('b', 4));
    Multimap.insert(make_pair('b', 5));

    // Countinng and Finding Keys
    cout << Multimap.count('a') << endl;

    auto mypair = Multimap.find('b');
    cout << mypair->first << ' ' << mypair->second << endl;

    // Lower and Upper Bound
    auto myrange = Multimap.lower_bound('a');
    cout << myrange->first << " " << myrange->second << endl;
    auto myrange2 = Multimap.upper_bound('a');
    cout << myrange2->first << " " << myrange2->second << endl;

    // Iterate over the multimap
    cout << "Print sorted multimap" << endl;
    for (auto &elm : Multimap)
        cout << elm.first << " " << elm.second << endl;

    // Get all the pairs of the given key
    cout << "Get all the pairs of the given key" << endl;
    // Just use the damn auto keyword
    pair<multimap<char, int>::iterator, multimap<char, int>::iterator> range = Multimap.equal_range('a');
    for (auto it = range.first; it != range.second; ++it)
        cout << it->first << " " << it->second << endl;
}