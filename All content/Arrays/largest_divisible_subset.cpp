#include <bits/stdc++.h>
using namespace std;

vector<int> get_subset(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return {};

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex])
        {
            maxIndex = i;
        }
    }

    vector<int> result;
    while (maxIndex != -1)
    {
        result.push_back(nums[maxIndex]);
        maxIndex = prev[maxIndex];
    }

    reverse(result.begin(), result.end());
    return result;
}

void get_subset(vector<int> &arr, int i, vector<int> &current, vector<int> &result)
{
    if (i == arr.size())
    {
        if (current.size() > result.size())
        {
            result = current; // store the longest subset found
        }
        return;
    }

    // Include current element if divisible
    if (current.empty() || arr[i] % current.back() == 0)
    {
        current.push_back(arr[i]);
        get_subset(arr, i + 1, current, result);
        current.pop_back();
    }

    // Or skip current element
    get_subset(arr, i + 1, current, result);
}

int main()
{
    vector<int> arr = {2, 4, 6, 8};
    vector<int> current, result;
    sort(arr.begin(), arr.end()); // Sorting may help for divisibility chains
    get_subset(arr, 0, current, result);
    cout << "Largest Divisible Subset (Recursive): ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    vector<int> subset = get_subset(arr);
    cout << "Largest Divisible Subset: (Dynamic Programming): ";
    for (int num : subset)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
