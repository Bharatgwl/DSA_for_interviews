#include <iostream>
#include <stack>

using namespace std;
class SpecialStack
{
public:
    stack<int> s;
    int mini;

    void Push(int x)
    {
        if (s.empty())
        {
            s.push(x); // handling first element and updating mini
            mini = x;
        }
        else
        {
            if (x < mini) // here we get new mini element
            {
                s.push(2 * x - mini);
                mini = x;
            }
            else
            {
                s.push(x); // normal push
            }
        }
    }
    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        s.pop();

        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevmin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevmin;
        }
    }
    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }
    bool isempty()
    {
        return s.empty();
    }
    int getmin()
    {
        if (s.empty())
            return -1;
        return mini;
    }
};
int main()
{
    SpecialStack s1;
    s1.Push(5);
    s1.Push(3);
    s1.Push(8);
    s1.Push(2);
    s1.Push(4);
    cout << s1.getmin();
}