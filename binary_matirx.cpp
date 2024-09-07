#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>

using namespace std;
vector<int> next_smaller(int *arr, int n)
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

vector<int> prev_smaller(int *arr, int n)
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
int largestarea(int *height, int n)
{

    vector<int> next(n);
    next = next_smaller(height, n);
    vector<int> prev(n);
    next = prev_smaller(height, n);
    int area = INT_MIN;
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
int maxarea(int M[][4], int n, int m)
{
    int area = largestarea(M[0], n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        int newarea = largestarea(M[i], m);
        area = max(area, newarea);
    }
   return area; 
}
int main()
{
    int M[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {0, 1, 0, 0}};
    int n = 4;
    int m = 4;
    int ans = maxarea(M, n, m);
    cout<<ans;
}