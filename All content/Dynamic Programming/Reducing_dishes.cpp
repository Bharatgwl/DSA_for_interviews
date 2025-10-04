#include <bits/stdc++.h>
using namespace std;
int reduce(vector<int> &satisfaction, int index, int time)
{
    if (index == satisfaction.size())
    {
        return 0;
    }
    int include = satisfaction[index] * (time + 1) + reduce(satisfaction, index + 1, time + 1);
    int exclude = 0 + reduce(satisfaction, index + 1, time);
    return max(include, exclude);
}
int reducememo(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
{
    if (index == satisfaction.size())
    {
        return 0;
    }
    if (dp[index][time] != -1)
    {
        return dp[index][time];
    }
    int include = satisfaction[index] * (time + 1) + reducememo(satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + reducememo(satisfaction, index + 1, time, dp);
    dp[index][time] = max(include, exclude);
    return dp[index][time];
}

int reducetab(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];
            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}
int reduceoptimised(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    int curr = 0;
    int prev = -1;
    int sum = 0;
    int i = n - 1;
    do
    {
        prev = curr;
        curr += sum; // mimic multiply by adding previous numbers 
        curr += satisfaction[i];
        sum += satisfaction[i];
        i--;
    } while (curr > prev && i >= 0);
    return max(prev, curr);
}
int main()
{
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    sort(satisfaction.begin(), satisfaction.end());
    cout << reduce(satisfaction, 0, 0) << endl;
    vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size(), -1));
    cout << reducememo(satisfaction, 0, 0, dp) << endl;
    cout << reducetab(satisfaction) << endl;
    cout << reduceoptimised(satisfaction) << endl;

    return 0;
}