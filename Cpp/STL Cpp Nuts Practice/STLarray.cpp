// NOTICE:
// 1. std::array is a container that encapsulates fixed size arrays.
// 2. array size is needed at compile time.
// 3. Assign by value is actually by value.
// 4. Access Elements:
//    a. at()
//    b. []
//    c. front()
//    d. back()
//    e. data() // gives access to the underlying array

#include <iostream>
// #include <array>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // no dynamic memory allocation
    // int n;
    // cin >> n;

    // Declare
    std::array<int, 5> myarray;

    //Initialisation
    std::array<int, 5> myarray2 = {1, 2, 3, 4, 5}; // initialiser List
    std::array<int, 5> myarray3 = {1, 2, 3, 4, 5}; // uniform initialisation

    // Assign using initialiser list
    std::array<int, 5> myarray4;
    myarray4 = {1, 2, 3, 4, 5};
    cout << myarray4.at(3);
}
