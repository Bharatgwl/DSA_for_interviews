#include <bits/stdc++.h>
using namespace std;

bool equal_subset_sum_partition_rec(vector<int> &arr, int target)
{

    if (target == 0)
        return true; // Found a subset with the required sum
    if (arr.empty() || target < 0)
        return false; // No valid subset found

    int last = arr.back();
    arr.pop_back(); // Remove the last element for recursion

    // Include the last element in the subset or exclude it
    bool include = equal_subset_sum_partition_rec(arr, target - last);
    bool exclude = equal_subset_sum_partition_rec(arr, target);

    arr.push_back(last);       // Restore the last element for further calls
    return include || exclude; // Return true if either inclusion or exclusion leads to a solution
}

bool helper(int i, int t, vector<int> &arr, vector<vector<int>> &dp)
{
    if (t == 0)
        return true; // Found a subset with the required sum
    if (i == 0 || t < 0)
        return false; // No valid subset found

    if (dp[i][t] != -1)
        return dp[i][t]; // Return cached result

    // Include the current element in the subset or exclude it
    bool include = helper(i - 1, t - arr[i - 1], arr, dp);
    bool exclude = helper(i - 1, t, arr, dp);

    return dp[i][t] = include || exclude; // Cache and return the result
}
bool equal_subset_sum_partition_memo(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    return helper(n, target, arr, dp); // Start recursion with the full array and target
}

int main()
{
    vector<int> arr = {1, 5, 11, 5};
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 != 0)
    {
        cout << "Not possible to partition into two equal subsets" << endl;
    }
    else
    {
        int target = sum / 2;
        if (equal_subset_sum_partition_rec(arr, target))
        {
            cout << "Possible to partition into two equal subsets" << endl;
        }
    }

    vector<int> arr2 = {1, 5, 11, 5};
    int sum2 = accumulate(arr2.begin(), arr2.end(), 0);
    if (sum2 % 2 != 0)
    {
        cout << "Not possible to partition into two equal subsets" << endl;
    }
    else
    {
        int target2 = sum2 / 2;
        if (equal_subset_sum_partition_memo(arr2, target2))
        {
            cout << "Possible to partition into two equal subsets using memoization" << endl;
        }
    }

    return 0;
}