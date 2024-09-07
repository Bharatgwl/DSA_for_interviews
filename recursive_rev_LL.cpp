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
Node *reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head; // returning the head of new smallerr internal functioning LL
    }
    Node *newhead = reverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
Node *hasCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return nullptr;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertattail(tail, 9);
    if (head == NULL)
    {
        head = tail;
    }
    insertattail(tail, 8);

    insertattail(tail, 7);
    insertattail(tail, 6);
    insertattail(tail, 5);
    insertattail(tail, 4);
    print(head);
    head = reverse(head);
    print(head);
}