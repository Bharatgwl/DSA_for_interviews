#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/**
 * @brief Finds the kth largest sum of a subarray from a given array of integers.
 *
 * @param arr the input array of integers
 * @param n the size of the array
 * @param k the kth largest sum to be found
 *
 * @return the kth largest sum of a subarray
 */
int kth_largest_subarray_sum(vector<int> arr, int n, int k)
{
    /**
     * minheap is a priority queue that stores the kth largest sums of subarrays
     * It is a min heap, so the smallest element (i.e. the kth largest sum) is at the top
     * The heap is implemented as a vector, and the elements are ordered in ascending order
     * The heap has a maximum size of k, so once it reaches size k, it will start popping the smallest element
     * whenever a new element is added that is larger than the top element
     */
    priority_queue<int, vector<int>, greater<int>> minheap;

    /**
     * Iterate over the array and calculate the sum of each subarray
     * For each subarray, check if the sum is larger than the top element of the minheap
     * If it is, pop the top element and push the new sum onto the heap
     * If the heap is not full (i.e. its size is less than k), simply push the new sum onto the heap
     */
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            /**
             * If the heap is not full, push the new sum onto the heap
             */
            if (minheap.size() < k)
            {
                minheap.push(sum);
            }
            else
            {
                /**
                 * If the heap is full, pop the smallest element (i.e. the kth largest sum)
                 * and push the new sum onto the heap if it is larger than the top element
                 */
                if (sum > minheap.top())
                {
                    minheap.pop();
                    minheap.push(sum);
                }
            }
        }
    }

    /**
     * Return the kth largest sum, which is the top element of the minheap
     */
    return minheap.top();
}
int main()
{
    vector<int>arr={6,1,3,2,5,4};
    cout<<kth_largest_subarray_sum(arr, arr.size(), 3);
}