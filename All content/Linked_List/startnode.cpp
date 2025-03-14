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
Node *loopexist(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            //cout << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}
Node *getintersectnode(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *INTERSECTIONNODE = loopexist(head);
    while (slow != INTERSECTIONNODE)
    {
        slow = slow->next;
        INTERSECTIONNODE = INTERSECTIONNODE->next;
    }
    return slow;
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
    
   cout<<"node where loop start :"<< getintersectnode(head)->data;
}
