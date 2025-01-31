#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> first_negative_integer(vector<int> &arr, int k)
{
    int i = 0, j = 0;
    queue<int> q;
    vector<int> ans;
    while (j < arr.size())
    {
        if (arr[j] < 0)
        {
            q.push(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (q.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
                if (arr[i] == q.front())
                {
                    q.pop();
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> vec = {12, -1, -7, 8, -16, 30, 16, 28};
    // vector<int> vec = {10, 5, 2, 7, 1,-10};
    int k = 3;
    for (auto i : first_negative_integer(vec, k))
    {
        cout << i <<" ";
    }
}