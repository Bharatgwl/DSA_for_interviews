#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &num, int target)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, target - num[i]);
    }
    return ans;
}
int solveMEM(vector<int> &num, int target, vector<int> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }
    if (dp[target] != -1)
    {
        return dp[target];
    }
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, target - num[i]);
    }
    dp[target] = ans;
    return dp[target];
}
int solveTAB(vector<int> &num, int target)
{
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 1;
    for (int i = 0; i < target; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (num[j] <= i)
            {
                dp[i] += dp[i - num[j]];
            }
        }
    }
    return dp[target];
}
int combination_Sum(vector<int> &num, int target)
{
    vector<int> dp(target + 1, -1);
    return solveMEM(num, target, dp);
    return solveTAB(num, target);
}
int main()
{
    vector<int> num = {1, 2};
    int target = 3;
    cout << "Number of combinations: " << combination_Sum(num, target) << endl;

    return 0;
}