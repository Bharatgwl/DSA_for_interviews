#include <iostream>
#include <stack>
using namespace std;
void insatbottom(stack<int> &s1, int s)
{
    if (s1.empty())
    {
        s1.push(s);
        return;
    }
    int save = s1.top();
    s1.pop();
    insatbottom(s1, s);
    s1.push(save);
}
void reverse(stack<int> &s1)
{
    if (s1.empty())
    {
        return;
    }
    int s = s1.top();
    s1.pop();
    reverse(s1);
    insatbottom(s1, s);
}

int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.top() << endl;
    reverse(s1);
    cout << s1.top() << endl;
    /*    ||   5   ||      
          ||   4   ||
          ||   3   ||
          ||   2   ||
          ||   1   ||
          ||=======||
          normal stack


          ||   1   ||
          ||   2   ||
          ||   3   ||
          ||   4   ||
          ||   5   ||
          ||=======||
          reversed stack
    */
 
}