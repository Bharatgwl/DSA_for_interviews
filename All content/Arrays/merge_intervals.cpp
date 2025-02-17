#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief Merges overlapping intervals in a vector of intervals
 * 
 * @param intervals A vector of intervals where each interval is a vector of two integers
 *                  representing the start and end points of the interval.
 * @return A vector of non-overlapping intervals
 * 
 * @details
 *      The function takes a vector of intervals as input and merges overlapping intervals
 *      to create a new vector of non-overlapping intervals. The input vector is sorted
 *      in-place and the output vector is created by iterating through the input vector.
 *      If an interval overlaps with the previous interval in the output vector, the
 *      end point of the previous interval is updated to be the maximum of the two end
 *      points. Otherwise, the current interval is added to the output vector.
 */
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans; // The output vector of non-overlapping intervals
    sort(intervals.begin(), intervals.end()); // Sort the input vector in-place in row order

    // Add the first interval to the output vector
    ans.push_back(intervals[0]);

    // Iterate through the input vector starting from the second interval
    for (int i = 1; i < intervals.size(); i++)
    {
        // If the current interval overlaps with the previous interval in the output vector
        if (ans.back()[1] >= intervals[i][0])
        {
            // Update the end point of the previous interval to be the maximum of the two end points
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {
            // Add the current interval to the output vector
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {0, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
