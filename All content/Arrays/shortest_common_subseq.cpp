#include <bits/stdc++.h>
using namespace std;
string shortestCommonSupersequence(string str1, string str2)
{
    int m = str1.length(), n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Step 1: Compute LCS using DP
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Step 2: Construct the SCS using LCS
    int i = m, j = n;
    string scs = "";

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            scs += str1[i - 1]; // Add common character
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            scs += str1[i - 1]; // Take from str1
            i--;
        }
        else
        {
            scs += str2[j - 1]; // Take from str2
            j--;
        }
    }

    // Step 3: Append remaining characters from str1 or str2
    while (i > 0)
    {
        scs += str1[i - 1];
        i--;
    }
    while (j > 0)
    {
        scs += str2[j - 1];
        j--;
    }

    reverse(scs.begin(), scs.end()); // Reverse to get correct order
    return scs;
}

int main()
{
    string str1 = "abac", str2 = "cab";

    cout << shortestCommonSupersequence(str1, str2);

    return 0;
}