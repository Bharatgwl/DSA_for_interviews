#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
vector<int> Max_of_window(vector<int> arr, int k)
{
    int i = 0, j = 0;
    queue<int> q;
    vector<int> ans;
    while (j < arr.size())
    {
        while (!q.empty() && q.front() < arr[j])
        {
            q.pop();
        }
        q.push(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            ans.push_back(q.front());
            if (arr[i] == q.front())
            {
                q.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    // vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    // vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> arr = {4,3,2,10,0};
    int k = 3;
    for (auto i : Max_of_window(arr, k))
    {
        cout << i << " ";
    }
    return 0;
}