#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;
vector<int> next_smaller(vector<int> arr, int n)
{

    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] > curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prev_smaller(vector<int> arr, int n)
{

    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] > curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}
int largestarea(vector<int> &height)
{
    int n = height.size();
    vector<int> next(n);
    next = next_smaller(height, n);
    vector<int> prev(n);
    next = prev_smaller(height, n);
    int area =INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = height[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newarea = l * b;
        area = max(newarea, area);
    }
    return area;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = largestarea(height);
    cout << ans;
}