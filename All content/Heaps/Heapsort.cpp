#include <iostream>
#include <vector>
using namespace std;
// Time complexity: O(nlog(n))
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
void Heapsort(vector<int> &arr, int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(arr, size, 0);
    }
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    Heapsort(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}