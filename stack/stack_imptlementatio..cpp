#include <iostream>
#include <vector>
using namespace std;
class stack
{
public:
    int size;
    int *arr;
    int top;
    stack(int size)
    {
        this->size = size;
        arr = new int(size);
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Caused Stack Overflow" << endl;
            return;
        }
    }
    int pop()
    {
        if (top >= 0)
        {
            return arr[top];
            top--;
        }
        else
        {

            return -1;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    stack *st = new stack(5);
    int arr[5] = {1, 2, -1, -1, 2};
    vector<int> ans;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < 0)
        {
            int save = st->pop();
            ans.push_back(save);
        }
        else if (arr[i] == 0)
        {
            ans.push_back(st->peek());
        }
        else
        {
            st->push(arr[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)

        {

            cout << "se";
        }
        else
        {
            cout << ans[i];
        }
    }
}