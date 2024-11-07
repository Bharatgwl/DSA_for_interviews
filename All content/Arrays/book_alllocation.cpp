#include <iostream>
#include <vector>
using namespace std;
bool ispossible(vector<int> arr, int size, int m, int mid)
{
    int stdcount = 1;
    int pagesum = 0;
    for (int i = 0; i < size; i++)
    {
        if (pagesum + arr[i] > mid)
        {
            stdcount++;
            pagesum = arr[i];
            if (stdcount > m || arr[i] > mid)
            {
                return false;
            }
        }
        else
        {
            pagesum += arr[i];
        }
    }
    return true;
}
int allocatebooks(vector<int> arr, int size, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (ispossible(arr, size, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> arr = {10, 20, 30, 40,60};
    int n = arr.size();
    int m = 3;
    int answers = allocatebooks(arr, n, m);
    cout << answers << endl;
    return 0;
}