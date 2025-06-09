#include <bits/stdc++.h>
using namespace std;
int perfectSquare(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {

        ans = min(ans, 1 + perfectSquare(n - (i * i))); // Recursive call to check for the remaining value
    }
    return ans;
}
int perfectSquareMemo(int n, vector<int> &dp)
{
    if (n <= 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + perfectSquareMemo(n - (i * i), dp)); // Recursive call to check for the remaining value
    }
    dp[n] = ans;
    return dp[n];
}
int perfectSquareTAB(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
                dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
    }
    return dp[n];
}

int main()
{
    cout << "This is a placeholder for the Perfect Square problem solution." << endl;
    int n = 12; // Example input, you can change this value to test with different inputs
    cout << perfectSquare(n) << endl;
    vector<int> dp(n + 1, -1);                // Assuming perfectSquare is a function that calculates the minimum number of perfect squares that sum to n
    cout << perfectSquareMemo(n, dp) << endl; // Assuming perfectSquare is a function that calculates the minimum number of perfect squares that sum to n
    cout << perfectSquareTAB(n) << endl;      // Assuming perfectSquare is a function that calculates the minimum number of perfect squares that sum to n
    // cout << return 0;
}