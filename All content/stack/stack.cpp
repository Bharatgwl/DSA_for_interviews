#include <iostream>
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
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Caused Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            cout << arr[top] << endl;
            return 0;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
};
int main()
{
    stack s1(5);
    s1.push(2);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(9);
    //s1.push(1);
    s1.peek();
}