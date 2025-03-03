#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    unordered_set<int> s;
    for (auto i : nums)
    {
        if (s.find(i) == s.end())
            s.insert(i);
    }
    int k = s.size();
    return k;
}
int removeDuplicates_2(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (nums[i] != nums[j])
        {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}
int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums) << endl;
    cout << removeDuplicates_2(nums);

    return 0;
}