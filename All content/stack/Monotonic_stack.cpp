#include <bits/stdc++.h>
using namespace std;
vector<int> monotonic_stack_increasing(vector<int> arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] > curr)
        {
            st.pop();
        }
        if (st.top() != -1)
        {
            result[i] = arr[st.top()];
        }
        st.push(i);
    }
    return result;
}

vector<int> monotonic_stack_decreasing(vector<int> arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] < curr)
        {
            st.pop();
        }
        if (st.top() != -1)
        {
            result[i] = arr[st.top()];
        }
        st.push(i);
    }
    return result;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> ans = monotonic_stack_increasing(arr);
    vector<int> res = monotonic_stack_decreasing(arr);
    cout << "Increasing monotonic stack: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\nDecreasing monotonic stack: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}