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

// Function to reverse the linked list
void reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

Node *add(Node *head)
{
    Node *temp = head;
    int carry = 1;

    while (temp != NULL && carry > 0)
    {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if (temp->next == NULL && carry > 0)
        {
            temp->next = new Node(carry);
            carry = 0;
        }
        temp = temp->next;
    }

    return head;
}

Node *addOne(Node *head)
{
    reverse(head);
    head = add(head);
    reverse(head);
    return head;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    for (int i = 0; i < 3; i++)
    {
        cin >> value;
        insertattail(tail, value);
        if (head == NULL)
        {
            head = tail;
        }
    }
    print(head);
    head = addOne(head);
    print(head);
}
