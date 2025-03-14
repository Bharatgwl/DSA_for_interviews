#include <iostream>
using namespace std;
void solve(string s, string op)
{
    if (s.length() == 0)
    {
        cout << op << endl;
        return;
    }
    if (isalpha(s[0]))
    {

        string op1 = op;
        string op2 = op;
        op1.push_back(toupper(s[0]));
        op2.push_back(tolower(s[0]));
        s.erase(s.begin() + 0);
        solve(s, op1);
        solve(s, op2);
    }
    else
    {
        string op1 = op;
        op1.push_back(s[0]);
        s.erase(s.begin() + 0);
        solve(s, op1);
    }
}
int main()
{
    string s;
    cin >> s;
    string op = "";
    solve(s, op);
    return 0;
}