#include <iostream>
#include <vector>
using namespace std;

// https://practice.geeksforgeeks.org/problems/merge-two-max-heaps/1
// Time complexity: O(nlogn) where n is the total number of elements in both heaps
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void Merge2heaps(vector<int> &result, vector<int> h1, vector<int> h2)
{
    for (auto I : h1)
    {
        result.push_back(I);
    }
    for (auto I : h2)
    {
        result.push_back(I);
    }
    for (int i = (result.size() / 2 - 1); i >= 0; i--)
    {
        heapify(result, result.size(), i);
    }
}
int main()
{
    vector<int> h1 = {10,5,6,3,1,4,2};
    vector<int> h2 = {15,12,13,7,8,11,9};
    vector<int> result;
    Merge2heaps(result, h1, h2);
    for (auto I : result)
    {
        cout << I << " ";
    }
    return 0;
}