#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    int n = arr.size();
    sort012(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}


// time complexity of this program  is o(n) and space complexity is o(1)