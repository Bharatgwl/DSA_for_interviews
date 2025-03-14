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
Node* reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        head = curr;
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertattail(tail, 6);
    if(head==NULL)
    head=tail;
    insertattail(tail, 5);
    insertattail(tail, 4);

    print(head);
    head = reverse(head);
    print(head);

    return 0;
}
