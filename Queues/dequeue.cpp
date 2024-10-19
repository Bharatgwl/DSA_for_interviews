#include <iostream>
using namespace std;
class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int size)
    {
        this->size = size;

        arr = new int[this->size];
        front = -1;
        ;
        rear = -1;
    }
    void pushfront(int data)
    {
        if (isfull())
        {
            cout << "queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
        return;
    }
    void pushrear(int data)
    {
        if (isfull())
        {
            cout << "queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
        return;
    }
    int popfront()
    {
        if (isempty()) // queue is empty already
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) // for single element is ther in queue
        {
            front = rear = -1;
        }
        else if (front == size - 1) // when front at last position by cyclic nature
        {
            front = 0;
        }
        else // for normal flow
        {
            front++;
        }
        return ans;
    }
    int poprear()
    {
        if (isempty()) // queue is empty already
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) // for single element is ther in queue
        {
            front = rear = -1;
        }
        else if (rear == 0) // when rear at first position by cyclic nature
        {
            rear = size - 1;
        }
        else // for normal flow
        {
            rear--;
        }
        return ans;
    }
    bool isempty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    {
        if (front == 0 && rear == size - 1 || (rear == (front - 1) % (size - 1)))
        {

            return true;
        }
        return false;
    }
    int getfront()
    {
        if (isempty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    int getrear()
    {
        if (isempty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }
};
int main()
{
    Deque d1(5);
    d1.pushfront(1);
    d1.pushfront(2);
    d1.pushfront(3);
    d1.pushfront(4);

    cout << d1.popfront() << " ";
    cout << d1.popfront() << " ";
    cout << d1.popfront() << " ";
    cout << d1.popfront() << " ";
    cout << d1.popfront() << " ";

    cout << d1.isempty() << endl;
    cout << d1.isfull() << endl;
    cout << d1.getfront() << endl;
    cout << d1.getrear() << endl;

    cout << d1.poprear() << endl;
    cout << d1.popfront() << endl;
}