#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// static class
class Solution
{
public:
    static int count;
    int a;
    int b;
    int c;

    Solution(int a = 0, int b = 0, int c = 0)
    {

        count++;
        if (count > 1)
        {
            cout << "Object already created" << endl;
            return;
        }
        // else
        // {
        //     Solution(1, 2, 3);
        // }
        this->a = a;
        this->b = b;
        this->c = c;
    };

    void print()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};

int Solution::count = 0;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    //     freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
    // #endif

    fastio;

    Solution s1;
    // Solution s2;

    s1.print();
    // s2.print();

    return 0;
}