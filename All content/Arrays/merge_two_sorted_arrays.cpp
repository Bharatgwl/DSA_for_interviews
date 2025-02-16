#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    vector<int> v3(m + n);
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            v3[k++] = nums1[i++];
        }
        else
        {
            v3[k++] = nums2[j++];
        }
    }
    while (i < m)
    {
        v3[k++] = nums1[i++];
    }
    while (j < n)
    {
        v3[k++] = nums2[j++];
    }

    nums1.clear();
    nums1 = v3;
    v3.clear();
}
int main()
{
    vector<int> arr1{1, 2, 3, 0, 0, 0};
    vector<int> arr2{-1, 6, 7};
    // vector<int> arr1{2, 0};
    // vector<int> arr2{1};
    merge(arr1, 3, arr2, 3);
    for (auto i : arr1)
    {
        cout << i << " ";
    }
}