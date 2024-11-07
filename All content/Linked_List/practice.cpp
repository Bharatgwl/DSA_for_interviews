#include <iostream>
#include"LinkedList.h"
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    Node(int data)
    {
        this->data = data;
    }
};
Node *insertattail(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        head->next = head;
        return head;
    }
    else
    {
        Node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
     
        curr->next = temp;
           temp->next = head;
    }
    return head;
}
void print(Node *head)
{
    Node *curr = head;
    do
    {
        cout << curr->data;
        curr = curr->next;
    } while (curr!= head);
}
int main()
{
    // Node *head = NULL;
    // insertattail(head, 1);
    // insertattail(head, 2);
    // insertattail(head, 3);
    // insertattail(head, 4);
    // insertattail(head, 5);
    // print(head);
    LinkedList<int> l1;
    l1.insert(2);
    l1.insert(3);
    l1.insert(3);
    l1.insert(3);
    l1.insert(3);
    l1.insert(1);
    l1.reverse();
    l1.display();

    
}