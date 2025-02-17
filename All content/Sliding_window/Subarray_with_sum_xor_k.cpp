#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int subarray_xor_k(vector<int> &arr, int k)
{
    int count = 0;
    int xr = 0;
    unordered_map<int, int> mp;
    mp[xr]++;
    for (int i = 0; i < arr.size(); i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ k;
        count += mp[x];
        mp[xr]++;
    }
    return count;
}
int main()
{
    vector<int> arr = {4, 2, 6};
    int k = 6;
    int a = 6, b = 2;
    cout << subarray_xor_k(arr, k);
}
