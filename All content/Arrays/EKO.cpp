#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possible(vector<int> &arr, int mid, int m)
{

    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > mid)
        {
            sum += arr[i] - mid;
        }
    }
    if (sum >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int EKO(vector<int> &arr, int m)
{

    int maxi = arr[0];
    int mini = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }

    int ans = -1;
    int i = mini;
    int j = maxi;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (possible(arr, mid, m))
        {
            ans = mid;
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
        mid = (i + j) / 2;
    }
    return ans;
}

int main()
{

    vector<int> arr = {4, 42 ,40 ,26 ,46};
    int k = 20;
    cout << EKO(arr, k);
}
// 4 7
// 20 15 10 17

// 5 20
// 4 42 40 26 46