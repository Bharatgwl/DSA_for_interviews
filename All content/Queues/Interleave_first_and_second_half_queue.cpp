#include <bits/stdc++.h>
using namespace std;
queue<int> interleave(queue<int> q)
{
    stack<int> st;
    queue<int> ans;

    int n = q.size();

    for (int i = 0; i < n / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < n / 2; i++)
    {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        ans.push(st.top());
        st.pop();

        ans.push(q.front());
        q.pop();
    }

    return ans;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q = interleave(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}