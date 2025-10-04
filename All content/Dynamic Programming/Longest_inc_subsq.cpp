#include <bits/stdc++.h>
using namespace std;
int longest_inc_subsq(vector<int> arr)
{
    vector<int> dp(arr.size(), 1);
    int omax = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] > max)
                {
                    max = dp[j];
                }
            }
        }
        dp[i] = max + 1;
        if (dp[i] > omax)
        {
            omax = dp[i];
        }
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