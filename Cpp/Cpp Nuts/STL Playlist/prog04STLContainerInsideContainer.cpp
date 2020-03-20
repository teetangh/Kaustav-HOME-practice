// TOPIC: Container Inside Container

// In this video we will learn how to use container inside container, which could be any container in c++ stl.

// std::vector<int> v1;
// v1.resize(1000); //allocation + instance creation
// cout <<(v1.size() == 1000)<< endl;   //prints 1
// cout <<(v1.capacity()==1000)<< endl; //prints 1

// std::vector<int> v2;
// v2.reserve(1000); //only allocation
// cout <<(v2.size() == 1000)<< endl;   //prints 0
// cout <<(v2.capacity()==1000)<< endl; //prints 1

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<vector<int>> Tree;
    int edge, n1, n2;

    cin >> edge;
    Tree.resize(edge);
    for (int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2;
        Tree[n1].push_back(n2);
    }

    // Tree is a graph and this is the Adjacency List
    int t = edge - 1;
    for (const auto &e1 : Tree)
    {
        for (const auto &e2 : e1)
        {
            cout << (t--) << " : " << e2 << ' ' << endl;
        }
        cout << endl;
    }
    return 0;
}
