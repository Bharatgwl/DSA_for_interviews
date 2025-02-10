#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// In backtracking, we modify the original input, make recursive calls, and then revert the changes (backtrack) to ensure that different recursive paths are not affected by changes from previous calls.
void permute(string &s, int i, vector<string> &ans)
{
    if (i == s.size())
    {
        ans.push_back(s);
        return;
    }
    unordered_set<char> us;
    for (int j = i; j < s.size(); j++)
    {
        if (us.find(s[j]) == us.end())
        {
            us.insert(s[j]);
            swap(s[i], s[j]);
            permute(s, i + 1, ans);
            swap(s[i], s[j]);// backtrack step
        }
    }
}
int main()
{
    string s = "abc";
    vector<string> ans;
    permute(s, 0, ans);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}