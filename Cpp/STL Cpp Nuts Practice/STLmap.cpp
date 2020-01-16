// TOPIC: Map In C++

// NOTES:
// 1. std::map is associative container that store elements in key value combination
//    where key should be unique, otherwise it overrides the previous value.
// 2. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
// 3. It store key value pair in sorted order on the basis of key (assending/decending).
// 4. std::map is generally used in Dictionay type problems.

#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <vector>
#include <list>
using namespace std;

typedef float X;
typedef float Y;

int main()
{
    //Mapping strings to integers
    cout << " Mapping strings to integers" << endl;
    std::map<string, int, std::less<string>> Map;
    Map["Chotu"] = 90666950;
    Map["Amit"] = 456456456;
    Map.insert(std::make_pair("Bot", 73453459));

    // Loop through the map
    for (auto &el1 : Map)
        cout << el1.first << " " << el1.second << endl;

    cout << "Accessing using [] operator" << endl;
    cout << Map["Chotu"] << endl;

    // Mapping strings to vectors
    cout << " Mapping strings to vectors" << endl;
    std::map<string, vector<int>> Map2;
    Map2["Example1"].push_back(10303304);
    Map2["Example2"].push_back(345345345);
    Map2["Example2"].push_back(345645744);
    Map2["Example3"].push_back(34534536);
    Map.insert(std::make_pair("Example4", 34536434)); // WONT WORK its a vector

    // Loop through the map
    for (auto &el1 : Map2)
    {
        cout << el1.first << endl;
        for (auto &el2 : el1.second)
        {
            cout << el2 << " " << endl;
        }

        cout << endl;
    }

    // Other possible declarations
    std::map<X, Y>;
    std::list<std::pair<X, Y>>;
}
