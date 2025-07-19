#include <bits/stdc++.h>
using namespace std;
string reorganise(string s)
{
    map<char, int> mp;
    priority_queue<pair<int, char>> q;
    for (auto i : s)
    {
        mp[i]++;
    }
    for (auto i : mp)
    {
        q.push({i.second, i.first});
    }
    string ans = "";
    
    while (q.size() > 1)
    {
        pair<int, char> first = q.top();
        q.pop();
        pair<int, char> second = q.top();
        q.pop();
        first.first--;
        second.first--;
        ans += first.second;
        ans += second.second;

        if (first.first > 0)
        {
            q.push(first);
        }
        if (second.first > 0)
        {
            q.push(second);
        }
    }

    if (!q.empty())
    {
        pair<int, char> last = q.top();
        if (last.first > 1)
        {
            return "";
        }
        else
        {
            ans += last.second;
        }
    }
    return ans;
}
int main()
{
    string s = "vvvlo";
    cout << reorganise(s);

    return 0;
}