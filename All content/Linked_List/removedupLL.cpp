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
Node *removeduplicate(Node *&head)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *curr = head;
    while (curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            Node *save = curr->next->next;
            Node *ntodelete = curr->next;
            
            delete (ntodelete);
            curr->next = save;
            
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertattail(tail, 1);
    if (head == nullptr)
    {
        head = tail;
    }
    insertattail(tail, 2);

    insertattail(tail, 2);

    insertattail(tail, 3);
    print(head);
    removeduplicate(head);
    print(head);
}
