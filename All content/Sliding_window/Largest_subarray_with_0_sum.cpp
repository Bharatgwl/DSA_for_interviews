#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int maxLen(vector<int> &arr)
{
    int i = 0, j = 0;
    int sum = 0;
    int maxlen = 0;
    unordered_map<int, int> mp;
    while (j < arr.size())
    {
        sum += arr[j];
        if (sum == 0)
        {
            maxlen = max(maxlen, j + 1);
        }
        else
        {
            if (mp.find(sum) != mp.end())
            {
                maxlen = max(maxlen, j - mp[sum]);
            }
            else
            {
                mp[sum] = j;
            }
        }
        j++;
    }
    return maxlen;
}
int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLen(arr);
    return 0;
}