#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> findTwoElement(vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (auto i : arr)
    {
        mp[i]++;
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
    vector<int> arr = {2,2};
    // vector<int> arr = {4, 3, 6, 2, 1, 1};
    // vector<int> arr = {4, 3, 2, 1, 5, 7, 7};
    for (auto i : findTwoElement(arr))
    {
        cout << i << " ";
    }

    return 0;
}