#include <bits/stdc++.h>
using namespace std;
int minScoreTriangulation(vector<int> &values, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        int score = values[i] * values[j] * values[k] + minScoreTriangulation(values, i, k, dp) + minScoreTriangulation(values, k, j, dp);
        ans = min(ans, score);
    }
    return dp[i][j] = ans;
}
int tabulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                int score = values[i] * values[j] * values[k] + dp[i][k] + dp[k][j];
                ans = min(ans, score);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}
int main()
{

    vector<int> values = {1, 3, 1, 4, 1, 5};
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << minScoreTriangulation(values, 0, n - 1, dp) << endl;

    return 0;
}