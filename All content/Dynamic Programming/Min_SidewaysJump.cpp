#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &obstacles, int currlane, int currpos)
{
    int n = obstacles.size() - 1;
    if (currpos == n)
    {
        return 0;
    }

    if (obstacles[currpos + 1] != currlane)
    {
        return solve(obstacles, currlane, currpos + 1);
    }
    else
    {
        int ans = INT_MAX;

        for (int i = 1; i <= 3; i++)
        {
            if (obstacles[currpos] != i &&
                currlane !=
                    i)
            { // iska matlb currlane me jump nai karna h or jaha
              // pe obstacles h waha bhi jump nahi karna
                ans = min(ans, 1 + solve(obstacles, i, currpos + 1));
            }
        }
        return ans;
    }
}
int solveMEM(vector<int> &obstacles, int currlane, int currpos,
             vector<vector<int>> &dp)
{
    int n = obstacles.size() - 1;
    if (currpos == n)
    {
        return 0;
    }
    if (dp[currlane][currpos] != -1)
    {
        return dp[currlane][currpos];
    }

    if (obstacles[currpos + 1] != currlane)
    {
        return solveMEM(obstacles, currlane, currpos + 1, dp);
    }
    else
    {
        int ans = INT_MAX;

        for (int i = 1; i <= 3; i++)
        {
            if (obstacles[currpos] != i &&
                currlane !=
                    i)
            { // iska matlb currlane me jump nai karna h or jaha
              // pe obstacles h waha bhi jump nahi karna
                ans = min(ans, 1 + solveMEM(obstacles, i, currpos + 1, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}

int minSideJumps(vector<int> &obstacles)
{
    vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));

    cout << solve(obstacles, 2, 0) << endl;
    return solveMEM(obstacles, 2, 0, dp);
}

int main()
{

    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << minSideJumps(obstacles) << endl;

    return 0;
}