#include <bits/stdc++.h>
using namespace std;
int hamming(string &a, string &b)
{
    int dis = 0;
    for (auto i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            dis++;
        }
    }
    return dis;
}
vector<string> longest_unequal_subsequence(vector<string> &words, vector<int> &groups)
{
    int n = words.size();
    vector<int> DP(n, 1);
    vector<int> parent(n, -1);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (words[i].size() == words[j].size() && hamming(words[i], words[j]) == 1 && groups[i] != groups[j])
            {
                if (DP[i] + 1 > DP[j])
                {
                    DP[j] = DP[i] + 1;
                    parent[j] = i;
                }
                
            }
        }
    }
    int index = max_element(DP.begin(), DP.end()) - DP.begin();
    vector<string> ans;
    while (index != -1)
    {
        ans.push_back(words[index]);
        index = parent[index];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<string> words = {"bab","dab","cab"};
    vector<int> groups = {1, 2, 2};
    vector<string> ans = longest_unequal_subsequence(words, groups);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}