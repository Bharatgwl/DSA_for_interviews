#include <bits/stdc++.h>
using namespace std;
// int ZERO_ONE_knapsack(vector<int> &wt, vector<int> &val, int W, int n)
// {
//     if (W == 0 || n == 0)
//         return 0;

//     if (wt[n - 1] > W)
//         return ZERO_ONE_knapsack(wt, val, W, n - 1);

//     return max(
//         val[n - 1] + ZERO_ONE_knapsack(wt, val, W - wt[n - 1], n - 1),
//         ZERO_ONE_knapsack(wt, val, W, n - 1));
// }
int ZERO_ONE_knapsack_memo(vector<int> &wt, vector<int> &val, int W, int n, vector<vector<int>> &dp)
{
    if (W == 0 || n == 0)
        return 0;

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (wt[n - 1] > W)
        return dp[n][W] = ZERO_ONE_knapsack_memo(wt, val, W, n - 1, dp);

    return dp[n][W] = max(
               val[n - 1] + ZERO_ONE_knapsack_memo(wt, val, W - wt[n - 1], n - 1, dp),
               ZERO_ONE_knapsack_memo(wt, val, W, n - 1, dp));
}

int table(vector<int> &wt, vector<int> &val, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]); // j - wt[i - 1] this means that we are removing the weight of the current item from the total weight then the subtracted value is added to the current value of the item then check if it is greater than the value of the previous item or not
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    vector<vector<int>> dp(wt.size() + 1, vector<int>(W + 1, -1));
    cout << ZERO_ONE_knapsack_memo(wt, val, W, wt.size(), dp);

    return 0;
}