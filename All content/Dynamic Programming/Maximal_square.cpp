#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &mat, int i, int j, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    int row = solve(mat, i + 1, j, maxi);
    int diag = solve(mat, i + 1, j + 1, maxi);
    int down = solve(mat, i, j + 1, maxi);

    if (mat[i][j])
    {
        int ans = 1 + min(row, min(diag, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
    return maxi;
}
int solveMEM(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int row = solve(mat, i + 1, j, maxi);
    int diag = solve(mat, i + 1, j + 1, maxi);
    int down = solve(mat, i, j + 1, maxi);

    if (mat[i][j])
    {
        dp[i][j] = 1 + min(row, min(diag, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return 0;
    }
    return maxi;
}

int solveTAB(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    int maxi = 0;
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int row = dp[i + 1][j];
            int diag = dp[i + 1][j + 1];

            int down = dp[i][j + 1];

            if (mat[i][j])
            {
                dp[i][j] = 1 + min(row, min(diag, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}
int solveSO(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<int> prev(col + 1, 0);
    vector<int> curr(col + 1, 0);
    int maxi = 0;
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int row = prev[j];
            int diag = prev[j + 1];

            int down = curr[j + 1];

            if (mat[i][j])
            {
                curr[j] = 1 + min(row, min(diag, down));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return maxi;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    int maxi = 0;
    cout << solve(matrix, 0, 0, maxi) << endl;
    vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size(), -1));
    maxi = 0;
    cout << solveMEM(matrix, 0, 0, maxi, dp) << endl;
    cout << solveTAB(matrix) << endl;
    cout << solveSO(matrix) << endl;

    return 0;
}