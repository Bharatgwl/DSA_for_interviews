#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int i)
{
    if (i < 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return nums[0];
    }
    int pick = nums[i] + solve(nums, i - 2);
    int notpick = solve(nums, i - 1);
    return max(pick, notpick);
}
int solveDP(vector<int> &nums, int i, vector<int> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return nums[0];
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int pick = nums[i] + solve(nums, i - 2);
    int notpick = solve(nums, i - 1);
    dp[i] = max(pick, notpick);
    return dp[i];
}
/*************  ✨ Windsurf Command 🌟  *************/
int solveTab(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int pick = (i - 2 >= 0) ? nums[i] + dp[i - 2] : 0;
        int notpick = dp[i - 1];
        dp[i] = max(pick, notpick);

    }
    return dp[nums.size() - 1];
}
/*******  f4b4d064-7d4c-42ed-90c8-ab300e49f7b5  *******/    
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    // int ans = solve(nums, nums.size() - 1);
    // return ans;

    // vector<int> dp(n, -1);

    // int ans = solveDP(nums, nums.size() - 1, dp);

    int ans = solveTab(nums);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int ans = maximumNonAdjacentSum(nums);
    cout << ans;

    return 0;
}