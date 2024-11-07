#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverse_k_groups(queue<int> &q1, int k)
{
    stack<int> s1;
    for (int i = 0; i < k; i++)
    {
        int val = q1.front();
        q1.pop();
        s1.push(val);
    }
    for (int i = 0; i < k; i++)
    {
        int val = s1.top();
        s1.pop();
        q1.push(val);
    }
    for (int i = 0; i < (q1.size() - k); i++)
    {
        int val = q1.front();
        q1.pop();
        q1.push(val);
    }
}
int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    reverse_k_groups(q1, 3);
    cout << q1.front();
}