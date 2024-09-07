#include <iostream>
#include <vector>
using namespace std;
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