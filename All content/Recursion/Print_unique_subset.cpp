#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void solve(string s, vector<string> &ans, string temp, unordered_map<string, int> &mp)
{
    if (s.length() == 0)
    {

        mp[temp]++;
        return;
    }

    string op1 = temp;
    string op2 = temp;
    op2.push_back(s[0]);
    s.erase(s.begin() + 0);
    solve(s, ans, op1, mp);
    solve(s, ans, op2, mp);
    return;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans;
    unordered_map<string, int> mp;
    solve(s, ans, "", mp);
    for (auto i : mp)
    {

        ans.push_back(i.first);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}