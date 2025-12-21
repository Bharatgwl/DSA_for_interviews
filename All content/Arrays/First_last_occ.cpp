#include <bits/stdc++.h>
using namespace std;
int firstOcc(vector<int> arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int lastOcc(vector<int> arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int n = arr.size();
    int k = 2;
    cout << firstOcc(arr, n, k) << endl;
    cout << lastOcc(arr, n, k) << endl;
    

    return 0;
}