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
int getlength(Node *&head1)
{
    Node *temp = head1;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *getintersection(Node *&head1, Node *&head2, int difference)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (difference--)
    {
        temp1 = temp1->next;
    }
    while (temp1 != NULL, temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
}
int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    insertattail(tail1, 5);
    if (head1 == NULL)
    {
        head1 = tail1;
    }
    insertattail(tail1, 9);
    insertattail(tail1, 6);
    insertattail(tail1, 19);
    insertattail(tail1, 5);
    insertattail(tail1, 1);
    insertattail(tail1, 6);
    insertattail(tail1, 10);

    insertattail(tail2, 5);
    if (head2 == NULL)
    {
        head2 = tail2;
    }
    insertattail(tail2, 6);
    head2->next->next = head1->next->next->next->next;
    int len1 = getlength(head1);
    int len2 = getlength(head2);
    int difference = len1 - len2;
    Node *intersection = getintersection(head1, head2, difference);
    cout<<"first linked list : ";
    print(head1);
    cout<<"second linked list : ";
    print(head2);

    cout <<"This is a point of intersection in both of list : "<<intersection->data;
}