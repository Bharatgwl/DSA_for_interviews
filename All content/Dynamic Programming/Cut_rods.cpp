#include <bits/stdc++.h>
using namespace std;
int solveREC(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    int a = solveREC(n - x, x, y, z) + 1;
    int b = solveREC(n - y, x, y, z) + 1;
    int c = solveREC(n - z, x, y, z) + 1;
    return max(a, max(b, c));
}

int solveMEM(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int a = solveMEM(n - x, x, y, z, dp) + 1;
    int b = solveMEM(n - y, x, y, z, dp) + 1;
    int c = solveMEM(n - z, x, y, z, dp) + 1;
    dp[n] = max(a, max(b, c));
    return dp[n];
}

int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    if (dp[n] < 0)
    {
        return 0;
    }
    else
    {
        return dp[n];
    }
}
int main()
{
    int n = 7;
    int x = 5, y = 2, z = 2;

    int ans = solveREC(n, x, y, z);
    cout << "solve REC" << " " << ans << endl;

    vector<int> dp(n + 1, -1);
    ans = solveMEM(n, x, y, z, dp);
    cout << "solve MEM" << " " << ans << endl;

    ans = solveTab(n, x, y, z);
    cout << "solve Tab" << " " << ans << endl;
}