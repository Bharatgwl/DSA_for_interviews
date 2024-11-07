#include <iostream>
#include <stack>
using namespace std;
bool isvalid(string sample)
{
    stack<int> check;

    for (int i = 0; i < sample.length(); i++)
    {
        if (sample[i] == '[' || sample[i] == '{' || sample[i] == '(')
            check.push(sample[i]);
        else
        {
            if (!check.empty())
            {
                char top = check.top();
                if (sample[i] == ']' && top == '[' || sample[i] == '}' && top == '{' || sample[i] == ')' && top == '(')
                {
                    check.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (check.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string validp = "{}}}}}";
    // cout << validp.length();
    if (isvalid(validp))
    {
        cout << "yes thats valid";
    }
    else
    {
        cout << "no";
    }
}