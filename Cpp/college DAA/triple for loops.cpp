#include <iostream>
using namespace std;

int main()
{
    int i, j, k;
    // cin >> i >> j >> k;

    int x = 0, n = 10;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {

            for (k = 1; k <= j; k++)
            {
                cout << " i is " << i << " j is " << j << " k is " << k << endl;
                x = x + 1;
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "x value is" << x;
}