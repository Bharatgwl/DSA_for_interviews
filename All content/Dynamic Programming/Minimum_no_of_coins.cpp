#include <bits/stdc++.h>
using namespace std;
int solverec(int x, vector<int> &nums)
{
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solverec(x - nums[i], nums);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}
int solveMemo(int x, vector<int> &nums, vector<int> &dp)
{
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return INT_MAX;
    }
    if (dp[x] != INT_MAX)
    {
        return dp[x];
    }
    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solveMemo(x - nums[i], nums, dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    dp[x] = mini;
    return mini;
}
/**
 * @brief      Solves the problem using tabulation approach.
 *
 * @details    This function uses a tabulation approach to solve the problem.
 *             It creates a vector dp of size x+1 and initializes it with INT_MAX.
 *             dp[i] stores the minimum number of coins needed to make amount i.
 *             dp[0] is set to 0 as 0 coins are needed to make 0 amount.
 *             It then iterates over the coins and for each coin, it checks if
 *             i - nums[j] >= 0. If it is, it checks if dp[i - nums[j]] is not
 *             INT_MAX. If it is not, it updates dp[i] with the minimum of dp[i]
 *             and 1 + dp[i - nums[j]].
 *             Finally, it returns dp[x] which is the minimum number of coins
 *             needed to make amount x.
 *
 * @param[in]  x     The amount for which we need to find the minimum number of coins.
 * @param[in]  nums  The vector of coin denominations.
 *
 * @return     The minimum number of coins needed to make amount x.
 */
int solveTab(int x, vector<int> &nums)
{
    // Create a vector dp of size x+1 and initialize it with INT_MAX
    vector<int> dp(x + 1, INT_MAX);

    // dp[0] is set to 0 as 0 coins are needed to make 0 amount
    dp[0] = 0;

    // Iterate over the coins
    for (int i = 1; i <= x; i++)
    {
        // Iterate over the coins
        for (int j = 0; j < nums.size(); j++)
        {
            // Check if i - nums[j] >= 0
            if (i - nums[j] >= 0)
            {
                // Check if dp[i - nums[j]] is not INT_MAX
                if (dp[i - nums[j]] != INT_MAX)
                {
                    // Update dp[i] with the minimum of dp[i] and 1 + dp[i - nums[j]]
                    dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
                }
            }
        }
    }
    // Consolas, 'Courier New', monospace

    // Return dp[x] which is the minimum number of coins needed to make amount x
    return dp[x];
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int target = 11;
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;                                                       // Base case: 0 coins needed to make 0 amount
    cout << "tabulation: " << solveTab(target, coins) << endl;       // Tabulation approach
    cout << "Memoization: " << solveMemo(target, coins, dp) << endl; // Memoization approach

    cout << "recursive: " << solverec(target, coins) << endl; // Recursive approach

    return 0;
}