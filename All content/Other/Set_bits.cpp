#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 13;
    int count = 0;
    if (x == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    while (x != 0)
    {
        if (x & 1)
        {
            count++;
        }
        x = x >> 1;
    }
    cout << count << endl;
    return 0;
}
