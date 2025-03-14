
#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class stack
{
private:
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int value)
    {
        node *newnode = new node(value);
        newnode->next = top;
        top = newnode;
    }
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }
    bool isempty()
    {
        return top == nullptr;
    }
    ~stack()
    {
        while (top != NULL)
        {
            pop();
        }
    }
};
int main()
{

    stack s1;
    s1.push(5);
    s1.push(19);
    s1.push(70);
    s1.push(50);
    cout << s1.peek() << endl;
    s1.pop();
    cout << s1.peek() << endl;
    s1.pop();
    cout << s1.peek() << endl;
    s1.pop();
    cout << s1.peek() << endl;
    s1.pop();
    s1.pop();
   
}
