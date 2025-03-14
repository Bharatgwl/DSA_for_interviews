#include <iostream>
#include <map>
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
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *temp = curr->next;
        Node *prev = curr;
        while (temp != nullptr)
        {

            if (curr->data == temp->data)
            {
                Node *save = temp->next;
                delete (temp);
                prev->next = save;

                temp = save;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

// Node*removeduplicate(Node*&head){
// map<Node,

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertattail(tail, 2);
    if (head == nullptr)
    {
        head = tail;
    }
    insertattail(tail, 2);

    insertattail(tail, 2);

    insertattail(tail, 2);
    insertattail(tail, 2);
    insertattail(tail, 2);
    print(head);
    removeduplicate(head);
    print(head);
}