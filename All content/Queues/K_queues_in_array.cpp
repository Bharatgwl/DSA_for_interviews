#include <iostream>
using namespace std;
class Kqueue
{
public:
    int n;
    int k;
    int *front;
    int *rear;
    int *next;
    int *arr;
    int freespot;
    Kqueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        arr = new int[n];
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freespot = 0;
    }
    void enque(int data, int qn)
    {
        if (freespot == -1)
        {
            cout << "queue overflow" << endl;
            return;
        }
        int index = freespot;   // finding free index to push element
        freespot = next[index]; // updating next freespot for future elements
        // check whether the element came is first element or not
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index; // for first element set the front
        }

        next[rear[qn - 1]] = index; // link new element to previous element
        next[index] = -1;
        rear[qn - 1] = index; // push thorugh rear index as per queue nature
        arr[index] = data;
    }
    int deque(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "underflow" << endl;
            return -1;
        }
        int index = front[qn - 1];
        front[qn - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
int main()
{
    Kqueue q1(10, 3);
    q1.enque(10, 1);
    q1.enque(15, 2);
    q1.enque(20, 1);
    q1.enque(30, 1);
    cout << q1.deque(1) << endl;

    cout << q1.deque(1) << endl;
    cout << q1.deque(2) << endl;
    cout << q1.deque(1) << endl;
    cout << q1.deque(1) << endl;
}