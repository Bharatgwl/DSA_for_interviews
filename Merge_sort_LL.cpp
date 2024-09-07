#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertattail(Node *&tail, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *sort(Node *&head)
{
    Node *temp = head;
    int zeroscount = 0;
    int Onescount = 0;
    int twoscount = 0;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zeroscount++;
        }
        else if (temp->data == 1)
        {
            Onescount++;
        }
        else if (temp->data == 2)
        {
            twoscount++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (zeroscount != 0)
        {
            temp->data = 0;
            zeroscount--;
        }
        else if (Onescount != 0)
        {
            temp->data = 1;
            Onescount--;
        }
        else if (twoscount != 0)
        {
            temp->data = 2;
            twoscount--;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int value;

    for (int i = 0; i <6; i++)
    {
        cin >> value;
        insertattail(tail, value);
        if (head == nullptr)
        {
            head = tail;
        }
    }
    cout << "before sorting"<<endl;
    print(head);
    sort(head);
    cout << "after sorting"<<endl;
    print(head);
}