#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
/**
 * https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/
 * https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356
 * Time Complexity: O(N log K)
 */
class node
{
public:
    int data;
    int row;
    int cols;
    node(int data, int row, int cols)
    {
        this->data = data;
        this->row = row;
        this->cols = cols;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
/**
 * @brief Finds the smallest range in a K-sorted list
 * @details This function takes a 2D vector as input, where each row is a sorted list.
 *          It will return the smallest range of elements in the sorted list.
 *          The range is defined as the difference between the maximum and minimum element.
 *          The range is calculated by keeping track of the minimum and maximum elements
 *          in the priority queue as we iterate through the list.
 * @param arr A 2D vector containing the sorted lists
 * @param k The number of sorted lists
 * @return The smallest range of elements in the sorted list
 */
int Smallest_range_in_KsortredList(vector<vector<int>> &arr, int k)
{
    // Initialize the minimum and maximum values to INT_MAX and INT_MIN, respectively
    int mini = INT_MAX, maxi = INT_MIN;

    // Initialize the size of the 2D vector
    int n = arr.size();

    // Create a priority queue and push the first element of each sorted list into it
    priority_queue<node *, vector<node *>, compare> pq;
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        pq.push(temp);

        // Update the minimum and maximum values
        mini = min(mini, arr[i][0]);
        maxi = max(maxi, arr[i][0]);
    }

    // Initialize the start and end of the range to the minimum and maximum values, respectively
    int start = mini, end = maxi;

    // Calculate the range

    // Iterate through the sorted list and update the minimum and maximum values
    while (!pq.empty())
    {
        node *temp = pq.top();
        pq.pop();

        // Update the minimum value
        mini = temp->data;

        // If the current range is smaller than the previous range, update the start and end of the range
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // If the current element is not the last element in its sorted list, push the next element into the priority queue
        if (temp->cols + 1 < arr[temp->row].size())
        {
            maxi = max(maxi, arr[temp->row][temp->cols + 1]);
            node *temp2 = new node(arr[temp->row][temp->cols + 1], temp->row, temp->cols + 1);
            pq.push(temp2);
        }
        else
        {
            break;
        }
    }

    // Return the smallest range
    return (end - start) + 1;
}
int main()
{
    int k = 3;
    vector<vector<int>> arr = {{1, 10, 11}, {2, 3, 20}, {5, 6, 12}};  
    cout << Smallest_range_in_KsortredList(arr, k);
}