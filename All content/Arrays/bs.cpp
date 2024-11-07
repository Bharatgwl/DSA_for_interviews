#include <iostream>
#include <math.h>
using namespace std;
int binary_search(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}
int main()
{
    int array[6] = {1, 2, 3, 4, 5, 6};
    int key;
    cin >> key;
    int index = binary_search(array, 6, key);
    cout << "index of key is" << index << endl;

    return 0;
}