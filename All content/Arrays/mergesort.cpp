#include <iostream>
using namespace std;
/**
 * @brief Merge two sorted arrays into one
 * 
 * @param arr The original array
 * @param s The start index of the array
 * @param e The end index of the array
 * 
 * @details
 *      This function uses the merge sort algorithm to sort the given array
 *      in increasing order. It divides the array into two halves, sorts them
 *      and then merges them together in sorted order.
 * 
 *      The time complexity of this function is O(n log n) and the space complexity
 *      is O(n).
 */
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int mainArrayindex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayindex++];
    }
    mainArrayindex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayindex++];
    }

    int index1 = 0, index2 = 0;
    mainArrayindex = s;
    while (index1 < len1 && index2 < len2)
    { // copying value of array in sorted manner
        if (first[index1] < second[index2])
        {
            arr[mainArrayindex++] = first[index1++];
        }
        else
        {
            arr[mainArrayindex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayindex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayindex++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}
/**
 * @brief Sorts the given array in increasing order using the Merge Sort algorithm
 * 
 * @param arr The array to be sorted
 * @param s The start index of the array
 * @param e The end index of the array
 * 
 * @details
 *      Merge Sort is a divide and conquer algorithm. It divides the array into two halves, sorts them
 *      and then merges them together in sorted order. The time complexity of this function is O(n log n)
 *      and the space complexity is O(n).
 */
void mergesort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;

    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}

/**
 * @brief Driver program to test the Merge Sort algorithm
 * 
 * @details
 *      The user is prompted to enter 50 numbers, which are then sorted using the Merge Sort algorithm and printed out in sorted order.
 *      The time complexity of the Merge Sort algorithm is O(n log n) and the space complexity is O(n). The Merge Sort algorithm is a divide and
 *      conquer algorithm. It divides the array into two halves, sorts them and then merges them together in sorted order.
 */
int main()
{
    int arr[50];
    for (int i = 0; i < 50; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, 50);
    for (int i = 0; i < 50; i++)
    {
        cout << i[arr] << " ";
    }
}