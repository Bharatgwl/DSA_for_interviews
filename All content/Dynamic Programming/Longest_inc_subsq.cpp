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
int main()
{

    // vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
    // cout << longest_inc_subsq(arr);


    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        cout << *arr + i << " ";
        // cout << i[arr] << " ";
        // cout << arr[i] << " ";
        // cout << *(i + (arr)) << " ";
    }

    return 0;
}