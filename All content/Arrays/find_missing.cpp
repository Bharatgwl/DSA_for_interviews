#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    unordered_set<int> presenceSet;
    for (int num : nums)
    {
      presenceSet.insert(num);
    }

    int missing = 1;
    while (presenceSet.find(missing) != presenceSet.end())
    {
      missing++;
    }

    return missing;
}

int main()
{
  vector<int> nums = {3, 4, -1, 1};
  cout << firstMissingPositive(nums);

  return 0;
}
