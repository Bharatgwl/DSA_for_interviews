#include <iostream>
#include <stack>
using namespace std;
void deletenum(stack<int> &st, int size, int count)
{

    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int save = st.top();//befor removing,saves it first which automatically saves in func call stack
    st.pop();//removing top elment from stack to penetrate upto target
    count++;
    deletenum(st, size, count++);//recursive call
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

    deletenum(st, st.size(), 0);
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
}
