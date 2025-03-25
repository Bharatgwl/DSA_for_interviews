#include <bits/stdc++.h>
using namespace std;
int fibTop_Down(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        dp[n]=n; // to get the series
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fibTop_Down(n - 1, dp) + fibTop_Down(n - 2, dp);
    return dp[n];
}
int fibBotton_up(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int fiboptimised(int n)
{
    int prev1 = 0;
    int prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
int fibrecursive(int n)
{
    if (n <= 1)
        return n;
    return fibrecursive(n - 1) + fibrecursive(n - 2);
}
int main()
{
    int n = 6;
    vector<int> dp(n + 1, -1);
    cout << fibTop_Down(n, dp) << endl;
    cout << fibBotton_up(n) << endl;
    cout << fiboptimised(n) << endl;
    cout << fibrecursive(n) << endl;
    for (auto i : dp)
    {
        cout << i << " ";
    }

    return 0;
}