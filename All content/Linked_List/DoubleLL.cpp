#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertattail(Node *&tail, Node *&head, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
        head = tail;
        return;
    }
    Node *temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void insertathead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    else
    {
        tail = temp;
    }
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
void printreverse(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    insertathead(head, tail, 0);

    insertattail(tail, head, 1);
    insertattail(tail, head, 2);
    insertattail(tail, head, 3);
    insertattail(tail, head, 4);
    insertattail(tail, head, 5);
    print(head);
    printreverse(head);
    return 0;
}

