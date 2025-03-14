#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
/**
 * @brief      This function implements the Kadane's algorithm to find the
 *             maximum contiguous subarray sum of a given array.
 *
 * @param[in]  arr   The input array
 *
 * @details    This function iterates the array and at each step, it adds the
 *             current element to a running sum. If the sum becomes negative,
 *             the sum is reset to zero and the start index is incremented.
 *             The maximum sum, start index and end index are kept track of.
 *             At the end, it prints the subarray with maximum sum.
 */
void kadanes_algo(vector<int> arr)
{
    int sum = 0;
    int maxi = INT_MIN;
    int start = 0, end = 0, s = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            start = s;
            end = i;
        }

        if (sum < 0)
        {
            sum = 0;
            s = i + 1;
        }
    }
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    return;
}
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    kadanes_algo(arr);
}