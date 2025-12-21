#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> arr = {0, 0, 0, 0, 0};
    vector<vector<int>> queries = {{0, 2, 5}};
    for (int i = 0; i < queries.size(); i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];
        int inc = queries[i][2];
        arr[start] += inc;
        if (end + 1 < arr.size())
        {
            arr[end + 1] -= inc;
        }
    }
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}