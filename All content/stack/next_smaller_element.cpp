#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> next_smaller(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > st.top())
        {
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        else
        {
            while (st.top() > arr[i])
            {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(arr[i]);
        }
    }
    int s = 0;
    int e = ans.size() - 1;
    while (s <= e)
    {
        swap(ans[s++], ans[e--]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 3, 5, 1};
    vector<int> ans = next_smaller(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}