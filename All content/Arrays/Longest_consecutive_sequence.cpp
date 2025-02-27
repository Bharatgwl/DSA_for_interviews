#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet)
    {
        if (numSet.find(num - 1) == numSet.end())
        {
            int length = 1;

            while (numSet.find(num + length) != numSet.end())
            {
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}
int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(arr) << endl;
    unordered_set<int> numSet(arr.begin(), arr.end());

    for (int num : numSet)
    {
        cout << num << " ";
    }

    return 0;
}