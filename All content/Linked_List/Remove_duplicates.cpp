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
    Node *prev = nullptr;
    map<int, int> mymap;
    while (curr != NULL)
    {
        mymap[curr->data]++;
        curr = curr->next;
    }
    curr = head;
    while (curr != nullptr)
    {
        if (mymap[curr->data] > 1)
        {
            if (prev == nullptr)
            {
                head = curr->next;
                delete curr;
                curr = head;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        mymap[curr->data]--;
            prev = curr;
            curr = curr->next;
        
    }
    return head;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertattail(tail, 2);
    if (head == nullptr)
    {
        head = tail;
    }
    insertattail(tail, 1);

    insertattail(tail, 1);

    insertattail(tail, 2);
    insertattail(tail, 1);
    insertattail(tail, 3);
    print(head);
    removeduplicate(head);
    print(head);
}