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
bool loopexist(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
int hasCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 0;
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

            Node *temp = slow->next;
            int count = 1;
            while (temp != slow)
            {
                temp = temp->next;
                count++;
            }
            return count;
        }
    }
}
int main()
{
    Node *n = new Node(5);
    Node *head = n;
    Node *tail = n;
    insertattail(tail, 9);
    insertattail(tail, 6);
    insertattail(tail, 3);
    insertattail(tail, 92);
    insertattail(tail, 3);

    print(head);
    tail->next = head->next; // print(head);

    cout<<hasCycle(head);
    // if (loopexist(head))
    // {
    //     cout << "loop exist:";
    // }
    // else
    // {
    //     cout << "loop does'nt exist:";
    // }
}
