#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> printfirstneg_NUM(vector<int> a, int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        if (a[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.size() > 0)
    {
        ans.push_back(a[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    for (int i = k; i < n; i++)
    {
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (a[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.size() > 0)
        {
            ans.push_back(a[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    vector<int> a;
    a.push_back(-8);
    a.push_back(2);
    a.push_back(3);
    a.push_back(-6);
    a.push_back(10);
    vector<int> ans = printfirstneg_NUM(a, 5, 2);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}