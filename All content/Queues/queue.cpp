#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    q1.push(7);
    //  cout<<q1.size();
    cout << q1.front();
    cout << q1.back();
    cout << q1.empty();
    q1.pop();
    q1.emplace(5);
    cout << q1.front();
}