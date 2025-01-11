#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Finds the kth missing number in a sorted vector of integers.
 *
 * @details
 *      This function takes a sorted vector of integers, the size of the vector, and an integer k as input.
 *      It then finds the kth missing element in the vector and returns it.
 *
 *      The function works by using a binary search approach to find the kth missing element.
 *      It starts by considering the first and last elements of the vector as the low and high indices
 *      respectively. The low index is the index of the first element in the vector, and the high index is
 *      the index of the last element in the vector.
 *
 *      It then calculates the mid index of the range and checks the number of missing elements at the mid index.
 *      The number of missing elements at the mid index is the difference between the element at the mid index
 *      and the index of the mid element plus one (i.e., the expected value of the element at the mid index).
 *
 *      If the number of missing elements at the mid index is less than k, then we know that the kth missing
 *      element must be in the right half of the range. Therefore, we move the low index to mid+1.
 *
 *      If the number of missing elements at the mid index is greater than or equal to k, then we know that
 *      the kth missing element must be in the left half of the range. Therefore, we move the high index to mid-1.
 *
 *      We continue this process until the low index is greater than the high index. At this point, we know that
 *      the kth missing element is the one at the index of high+1.
 *
 *      Finally, we return the kth missing element.
 */
int missingK(vector < int > vec, int n, int k) {
    // Set the low and high indices to the start and end of the vector, respectively.
    int low = 0, high = n - 1;
    // Continue the loop until the low index is greater than the high index.
    while (low <= high) {
        // Calculate the mid index of the range.
        int mid = (low + high) / 2;
        // Calculate the number of missing elements at the mid index.
        int missing = vec[mid] - (mid + 1);
        // If the number of missing elements at the mid index is less than k, then move the low index to mid+1.
        if (missing < k) {
            low = mid + 1;
        }
        // If the number of missing elements at the mid index is greater than or equal to k, then move the high index to mid-1.
        else {
            high = mid - 1;
        }
    }
    // Return the kth missing element.
    return k + high + 1;
}


int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
