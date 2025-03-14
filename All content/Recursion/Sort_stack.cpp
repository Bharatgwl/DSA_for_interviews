#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &st, int temp)
{
    if (st.empty() || (!st.empty() && st.top() <= temp))
    {
        st.push(temp);
        return;
    }
    int value = st.top();
    st.pop();
    insert(st, temp);
    st.push(value);
}
void sort(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sort(st);
    insert(st, temp);
}
int main()
{
    stack<int> s1;
    s1.push(4);
    s1.push(7);
    s1.push(2);
    s1.push(3);
    s1.push(1);
    s1.push(5);
    s1.push(6);
    stack<int> s2 = s1;
    while (!s2.empty())
    {
        cout << s2.top() << endl;
        s2.pop();
    }
    sort(s1);
    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }
}