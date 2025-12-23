#include <bits/stdc++.h>
using namespace std;

int longest_inc_subsq(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 1);
    int omax = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        omax = max(omax, dp[i]);
    }
    return omax;
}

int lis(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return 0;
    }
    vector<int> sub;
    sub.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > sub.back())
        {
            sub.push_back(arr[i]);
        }
        else
        {
            int index = lower_bound(sub.begin(), sub.end(), arr[i]) - sub.begin();
            sub[index] = arr[i];
        }
    }
    return sub.size();
}
int main()
{
    vector<int> arr = {5, 8, 3, 7, 9, 1};
    cout << longest_inc_subsq(arr) << endl;
    cout << lis(arr);

    return 0;
}