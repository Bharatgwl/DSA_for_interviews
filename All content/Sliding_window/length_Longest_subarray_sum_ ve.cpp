
// // -59 -25 58 -59 -25 58
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubarrayWithSumK(const vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumIndex; // Map to store prefix sum and its earliest index
    int maxLength = 0;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        currentSum += arr[i];

        // If the sum equals k the subarray starts from index 0
        if (currentSum == k) {
            maxLength = i + 1;
        }

        // If the (currentSum - k) exists in the map, update the maxLength
        // it means there is a number present in the map which exclusion can make
        // the sum
        if (prefixSumIndex.find(currentSum - k) != prefixSumIndex.end()) {
            maxLength = max(maxLength, i - prefixSumIndex[currentSum - k]);
        }

        // If currentSum is not already in the map, store its index
        if (prefixSumIndex.find(currentSum) == prefixSumIndex.end()) {
            prefixSumIndex[currentSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {-59, -25, 58 ,-59, -25, 58}; // Example array
    int k = -85; // Target sum
    cout << "Length of longest subarray: " << longestSubarrayWithSumK(arr, k) << endl;
    return 0;
}
