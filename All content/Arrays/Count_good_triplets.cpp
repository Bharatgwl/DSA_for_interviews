#include <bits/stdc++.h>
using namespace std;
class BIT
{
public:
    vector<int> bit;
    BIT(int n)
    {
        bit.resize(n + 1, 0);
    }
    void update(int idx, int val)
    {
        while (idx < bit.size())
        {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }
    int query(int idx)
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};
int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {1, 2, 3};
    int n = nums1.size();
    int m = nums2.size();
    int ans = 0;
    BIT bit(1000000);
    for (int i = 0; i < n; i++)
    {
        bit.update(nums1[i], 1);
    }
    for (int i = 0; i < m; i++)
    {
        ans += bit.query(nums2[i], 1000000);
    }
    return 0;
}