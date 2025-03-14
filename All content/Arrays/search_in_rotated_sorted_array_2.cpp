#include <iostream>

#include <vector>
using namespace std;
bool BS(vector<int> &arr, int target)
{
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        for (int i = s; i <= e; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        if (arr[mid] == target)
        {
            return true;
        }
        if (arr[s] == arr[e] == arr[mid])
        {
            s = s + 1;
            e = e - 1;
            continue;
        }
        if (arr[s] <= arr[mid])
        {
            if (target >= arr[s] && target <= arr[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (target >= arr[mid] && target <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        mid = s + (e - s) / 2;
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // cout << arr.size();
    int target = 13;
    cout << BS(arr, target);
}