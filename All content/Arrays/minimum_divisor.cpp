#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();
    int threshold = 5;

    int left = 1, right = *max_element(arr.begin(), arr.end());
    int ans = right;
    while (left <= right)
    {

        int mid = left + (right - left) / 2;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            count += ceil(arr[i] / double(mid)); // ceil(arr[i]/mid)
        }

        if (count <= threshold)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}