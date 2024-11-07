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
Node *unionll(Node *head1, Node *head2)
{

    Node *neww = new Node(0);
    Node *tail = neww;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL)
    {
        tail->next = head1;
    }
    else
    {
        tail->next = head2;
    }

    Node *mergedlist = neww->next;
    delete neww;

    return mergedlist;
}
int main()
{
    int value;
    Node *head1 = NULL;

    Node *tail1 = NULL;

    Node *head2 = NULL;

    Node *tail2 = NULL;
    for (int i = 0; i < 3; i++)
    {
        cin >> value;
        insertattail(tail1, value);
        if (head1 == NULL)
        {
            head1 = tail1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> value;
        insertattail(tail2, value);
        if (head2 == NULL)
        {
            head2 = tail2;
        }
    }

    print(head1);
    print(head2);
    unionll(head1, head2);

    // 1 print(head1);
    print(head1);
}