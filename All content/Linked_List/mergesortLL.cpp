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
Node *findmid(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
Node *merge(Node *left, Node *right)
{

    Node *newlist = new Node(0);
    Node *tail = newlist;

    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if (left != NULL)
    {
        tail->next = left;
    }
    else
    {
        tail->next = right;
    }

    Node *mergedlist = newlist->next;
    delete newlist;

    return mergedlist;
}
Node *mergesort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *left = head;
    Node *mid = findmid(head);
    Node *right = mid->next;
    mid->next=NULL;
    left = mergesort(left);
    right = mergesort(right);
    Node *result = merge(left, right);
    return result;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertattail(tail, 4);
    if (head == nullptr)
    {
        head = tail;
    }
    insertattail(tail, 6);
    insertattail(tail, 1);
    insertattail(tail, 0);
    insertattail(tail, 20);
    print(head);
    Node*result = mergesort(head);
    print(result);
}