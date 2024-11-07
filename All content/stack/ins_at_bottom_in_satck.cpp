#include <iostream>
#include <stack>
using namespace std;
void insert(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int save = st.top();
    st.pop();
    insert(st, x);
    st.push(save);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int x = 0;
    // cout << st.top();
    // st.pop();
    // cout << st.top();
    // st.pop();
    // cout << st.top();
    // st.pop();
    // cout << st.top();
    // st.pop();
    // cout << st.top();
    // st.pop();
    insert(st, x);
    cout << endl;
    cout << st.top();
    st.pop();
    cout << st.top();
    st.pop();
    cout << st.top();
    st.pop();
    cout << st.top();
    st.pop();
    cout << st.top();
    st.pop();
    cout << st.top();
    st.pop();
}