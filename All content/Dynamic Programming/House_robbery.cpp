#include <bits/stdc++.h>
using namespace std;
// int house_robbery(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     dp[0] = nums[0];
//     dp[1] = max(nums[0], nums[1]);
//     for (int i = 2; i < n; i++)
//     {
//         int pick = nums[i] + dp[i - 2];
//         int notpick = dp[i - 1];
//         dp[i] = max(pick, notpick);
//     }
//     return dp[n - 1];
// }
int house_robbery(vector<int> &nums)
{
    int n = nums.size();
    int prev2 =0;
    int prev1 =nums[0];
    for(int i=1;i<n;i++)
    {
        int incl = nums[i]+prev2;
        int excl = prev1;
        int curr = max(incl,excl);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    vector<int> nums = {1, 3, 2, 7};
    vector<int> first, second;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums.size() - 1)
        {
            first.push_back(nums[i]);
        }
        if (i != 0)
        {
            second.push_back(nums[i]);
        }
    }
    cout << max(house_robbery(first), house_robbery(second));

    return 0;
}