#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> findTwoElement(vector<vector<int>> &arr)
{
    unordered_map<int, int> mp;
    for (auto i : arr)
    {
        for (auto j : i)
        {
            mp[j]++;
        }
    }
    int missing = 0;
    int repeating = 0;
    for (int i = 1; i <= arr.size(); i++)
    {
        if (mp.find(i) == mp.end())
        {
            missing = i;
        }
        if (mp[i] > 1)
        {
            repeating = i;
        }
    }
    return {repeating, missing};
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 2}};
    // vector<int> arr = {4, 3, 6, 2, 1, 1};
    // vector<int> arr = {4, 3, 2, 1, 5, 7, 7};
    unordered_map<int, int> mp;
    for (auto i : arr)
    {
        for (auto j : i)
        {
            mp[j]++;
        }
    }
    for (auto i : mp)
    {
        cout << i.first << ' ' << i.second;
    }
    // for (auto i : findTwoElement(arr))
    // {
    //     cout << i << " ";
    // }
    // return 0;
}
