#include <bits/stdc++.h>
using namespace std;
/**
 * @brief      Finds the maximum number of candies that can be allocated to k children.
 *
 * @details    This function uses a binary search approach to find the maximum number of candies
 *             that can be allocated to k children from the given array of candies. The binary
 *             search range is [1, max_element(candies.begin(), candies.end())]. The function
 *             calculates the number of candies each child can get if we divide each candy by
 *             the mid value of the binary search range. If the total number of candies allocated
 *             to all children is greater than or equal to k, then we can increase the number of
 *             candies each child can get and move the start index of the binary search range
 *             to mid+1. Otherwise, we decrease the number of candies each child can get and
 *             move the end index of the binary search range to mid.
 *
 * @param[in]  candies The vector of integers representing the number of candies in each pile.
 * @param[in]  k       The number of children to allocate the candies to.
 *
 * @return     The maximum number of candies that can be allocated to k children.
 */
int maximumCandies(vector<int> &candies, long long k)
{
    int n = candies.size();

    int l = 1;

    int r = *max_element(candies.begin(), candies.end());

    int ans = -1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            count += candies[i] / mid;
        }

        if (count >= k)
        {
            ans = mid;

            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    return ans;
}
int main()
{
    vector<int> candies = {5, 8, 6};
    int k = 3;

    cout << maximumCandies(candies, k);

    return 0;
}