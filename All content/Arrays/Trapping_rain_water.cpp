// Leetcode 42. Trapping Rain Water
// Difficulty : Hard
// Link : https://leetcode.com/problems/trapping-rain-water/
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Trapping Rain Water: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 *
 * @param height A vector of integers representing the elevation map.
 * @return The amount of rain water that can be trapped.
 */
int Trapping(vector<int> &height)
{
    /**
     * Initialize the boundaries of the elevation map.
     * left: The left boundary of the elevation map.
     * right: The right boundary of the elevation map.
     */
    int n = height.size();
    int left = 0;
    int right = n - 1;

    /**
     * Initialize the maximum height of the left and right boundaries.
     * leftmax: The maximum height of the left boundary.
     * rightmax: The maximum height of the right boundary.
     */
    int leftmax = height[left];
    int rightmax = height[right];

    /**
     * Initialize the amount of rain water that can be trapped.
     * ans: The amount of rain water that can be trapped.
     */
    int ans = 0;

    /**
     * Iterate over the elevation map from left to right and right to left.
     * If the height of the left boundary is less than the height of the right boundary,
     * move the left boundary to the right and update the maximum height of the left boundary.
     * If the height of the right boundary is less than the height of the left boundary,
     * move the right boundary to the left and update the maximum height of the right boundary.
     * Add the difference between the maximum height of the boundary and the height of the current
     * boundary to the answer.
     */
    while (left < right)
    {
        if (leftmax < rightmax)
        {
            left++;
            leftmax = max(leftmax, height[left]);
            ans += leftmax - height[left];
        }
        else
        {
            right--;
            rightmax = max(rightmax, height[right]);
            ans += rightmax - height[right];
        }
    }
    return ans;
}
int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Trapping(height) << endl;
    return 0;
}