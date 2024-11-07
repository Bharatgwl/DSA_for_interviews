#include <iostream>
#include <vector>
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
void insertathead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
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
Node *rotateLL(Node *&head, Node *&tail, int k)
{

    Node *temp = head;
    int len = 1;
    while (temp->next)
    {
        temp = temp->next;
        len++;
    }
    k = k % len;
    if (k == 0)
        return head;

    temp = head;
    for (int i = 1; i < len - k; i++)
    {
        temp = temp->next;
    }
    tail->next = head;
    head = temp->next;
    temp->next = NULL;
    tail = temp;

    return head;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertattail(tail, 1);
    if (head == NULL)
    {
        head = tail;
    }
    insertattail(tail, 2);
    insertattail(tail, 4);
    insertattail(tail, 3);
    insertattail(tail, 4);
    insertattail(tail, 4);
    insertattail(tail, 4);
    insertattail(tail, 5);
    insertattail(tail, 4);
    insertattail(tail, 6);
    insertattail(tail, 4);
    insertattail(tail, 7);
    insertattail(tail, 4);
    insertattail(tail, 8);
    insertattail(tail, 9);
    print(head);
    int k;
    cin >> k;
    Node *newhead = rotateLL(head, tail, k);
    print(head);
}