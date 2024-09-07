#include <iostream>
using namespace std;
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