#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief Rotates the elements of the given array to the right by k positions.
 * 
 * @param arr The input array to be rotated.
 * @param n The number of elements in the array.
 * @param k The number of positions to rotate the array to the right.
 * 
 * @return The rotated array with elements shifted to the right by k positions.
 * 
 * @details This function creates a temporary copy of the input array and shifts
 *          each element of the original array to its new position based on the
 *          given number of positions k. The rotation is performed in a circular
 *          manner using modulo arithmetic.
 */
vector<int> rotatearray(vector<int> &arr, int n, int k)
{
    vector<int> temp = arr;
    int index;
    for (int i = 0; i < n; i++)
    {
        index = (i + k) % n;
        arr[i] = temp[index];
    }
    return arr;
} 
int main()
{
    vector<int> arr = {1 ,5 ,3 ,4 ,2};
    int k = 3;
    rotatearray(arr, arr.size(), k);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}