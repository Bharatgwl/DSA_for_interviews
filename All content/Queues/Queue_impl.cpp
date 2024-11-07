#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int(size);
        front = 0;
        rear = 0;
    }
    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full";
            return;
        }
        arr[rear++] = data;
    }
    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is empty";
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == rear)
        {
            cout << "Queue is empty";
            return -1;
        }
        return arr[front];
    }
    bool isempty()
    {
        return front == size;
    }
};
int main()
{
    Queue q1(5);
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();


    if (q1.isempty())
    {
        cout << "trtue";
    }
    else
    {
        cout << "false";
    }
}