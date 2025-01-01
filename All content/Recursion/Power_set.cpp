#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(string ip, string op, vector<string> &ans)
{
    if (ip.length() == 0)
    {
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1, ans);
    solve(ip, op2, ans);
    return;
}
int main()
{

    string ip = "ab";
    string op = " ";
    vector<string> ans;
    solve(ip, op, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}