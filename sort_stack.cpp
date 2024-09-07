#include <iostream>
#include <stack>
using namespace std;

void pushsort(stack<int> &s1, int num)
{
    if (s1.empty() || (!s1.empty() && s1.top() < num))
    {
        s1.push(num);
        return;
    }
    int save = s1.top();
    s1.pop();
    pushsort(s1, num);
    s1.push(save);
}
void sort(stack<int> &s1)
{
    if (s1.empty())
    {
        return;
    }
    int num = s1.top();
    s1.pop();
    sort(s1);
    pushsort(s1, num);
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
    stack<int>s2=s1;
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