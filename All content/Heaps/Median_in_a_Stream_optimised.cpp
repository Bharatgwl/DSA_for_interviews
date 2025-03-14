#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int signum(int a, int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}
void callmedian(int element, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int &median)
{
    switch (signum(maxheap.size(), minheap.size()))
    {
    case 0:
        if (element > median)
        {
            minheap.push(element);
            median = minheap.top();
        }
        else
        {
            maxheap.push(element);
            median = maxheap.top();
        }
        break;
    case 1:
        if (element > median)
        {
            minheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        else
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        break;
    case -1:
        if (element > median)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        else
        {
            maxheap.push(element);
            median = (maxheap.top() + minheap.top()) / 2;
        }
        break;
    }
}
vector<int> find_median(vector<int> arr, int n)
{
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = 0;
    for (int i = 0; i < n; i++)
    {
        callmedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }
    return ans;
}
int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    int element;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }
    vector<int> ans = find_median(arr, arr.size());
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
// 20 14 13 16 17 16 16 14 16 16
// 10
// 20 8 13 19 17 16 12 0 19 20