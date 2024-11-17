#include <bits/stdc++.h>
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
void insertattail(node *&tail, int data)
{
    if (tail == NULL)
    {
        tail = new node(data);
        return;
    }
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}
void insertathead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *kreverse(node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    node *forward = NULL;
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (count < k && curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL)
    {
        head->next = kreverse(forward, k);
    }
    return prev;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        insertattail(tail, data);
        cin >> data;
        if (head == NULL)
        {
            head = tail;
        }
    }
    print(head);

    head = kreverse(head, 2);
    print(head);
}
