#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
void insertattail(Node *&tail, Node *&head, int data)
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
void randomis(Node *&head)
{
    Node *curr = head;
    Node *prev = head;
    int count = 1;
    while (curr != NULL)
    {
        if (count == 1)
        {
            curr->random = curr->next->next;
            count++;
            curr = curr->next;
        }
        if (count == 2)
        {
            curr->random = prev;
            curr = curr->next;
            count++;
        }
        if (count == 3)
        {
            curr->random = curr->next->next;
            prev = curr;
            curr = curr->next;

            count++;
        }
        if (count == 4)
        {
            curr->random = prev;
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (count == 5)
        {
            curr->random = prev;
            prev = curr;
            curr = curr->next;
        }
    }
    return;
}
Node *clone(Node *&head)
{
    Node *curr = head;
    Node *clonehead = NULL;
    Node *clonetail = NULL;
    while (curr != NULL)
    {
        insertattail(clonetail, clonehead, curr->data);
        if (clonehead == NULL)
        {
            clonehead = clonetail;
        }
        curr = curr->next;
    }
    return clonehead;
}
void copyLinkedL(Node *&head, Node *&clone_head)
{
    map<Node *, Node *> mapping; // tracking backside
    Node *orginalhead = head;
    Node *clonehead = clone_head;
    while (orginalhead != NULL)
    {
        mapping[orginalhead] = clonehead;
        orginalhead = orginalhead->next;
        clonehead = clonehead->next;
    }
    orginalhead = head;
    clonehead = clone_head;
    while (orginalhead != NULL)
    {
        clone_head->random = mapping[orginalhead->random];
        orginalhead = orginalhead->next;
        clonehead = clonehead->next;
        return;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertattail(tail, head, 1);
    if (head == NULL)
    {
        head = tail;
    }
    insertattail(tail, head, 2);
    insertattail(tail, head, 3);
    insertattail(tail, head, 4);
    insertattail(tail, head, 5);
    randomis(head);
    Node *clone_head = clone(head);

    copyLinkedL(head, clone_head);
    cout << clone_head->random->data;
}
