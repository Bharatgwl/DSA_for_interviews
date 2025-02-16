#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> next_smaller(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < st.top())
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        else
        {
            while (st.top() < arr[i] && st.top() != -1)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 12, 5, 1, 2, 4, 6};
    vector<int> ans = next_smaller(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
