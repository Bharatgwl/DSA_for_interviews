#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int primeScore(int n)
{
    int score = 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ++score;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ++score;
    return score;
}

int maxScore(vector<int> &nums, int k)
{
    int n = nums.size();
    set<pair<int, int>> used;
    priority_queue<tuple<int, int, int>> pq;

    // Step 1: Store prime scores
    vector<int> ps(n);
    for (int i = 0; i < n; ++i)
        ps[i] = primeScore(nums[i]);

    // Step 2: Generate all subarrays
    for (int l = 0; l < n; ++l)
    {
        int bestIdx = l, maxPS = ps[l];
        for (int r = l; r < n; ++r)
        {
            // Update best element in this subarray
            if (ps[r] > maxPS || (ps[r] == maxPS && r < bestIdx))
            {
                bestIdx = r;
                maxPS = ps[r];
            }
            if (!used.count({l, r}))
            {
                pq.push({nums[bestIdx], maxPS, -bestIdx}); // max heap
                used.insert({l, r});
            }
        }
    }

    long long ans = 1;
    while (k-- && !pq.empty())
    {
        tuple<int, int, int> topElement = pq.top();
        pq.pop();
        int val = get<0>(topElement);
        ans = (ans * val) % MOD;
    }

    return ans;
}

int main()
{
    vector<int> nums = {8, 3, 9, 3, 8};
    int k = 2;
    cout << maxScore(nums, k) << endl; // ✅ Should print 81
    return 0;
}
