#include <iostream>
#include <queue>
using namespace std;
void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int save = q.front();
    q.pop();
    reverse(q);
    q.push(save);
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.front() << endl;
    reverse(q);
    cout << q.front() << endl;
}
