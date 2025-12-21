#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abc";
    vector<int> shifts = {0, 1, 2};

    for (int i = 0; i < s.size(); i++)
    {
        s[i] = shifts[i] % 26 + s[i];
        if (s[i] > 'z')
        {
            s[i] = s[i] - 26;
        }
    }   
    cout << s;
    return 0;
}