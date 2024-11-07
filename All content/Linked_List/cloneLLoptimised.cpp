#include <iostream>
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

void randomise(Node *&head)
{
    Node *curr = head;
    int count = 1;

    while (curr != NULL)
    {
        if (count == 1 && curr->next && curr->next->next) // For first node
        {
            curr->random = curr->next->next;
        }
        else if (count == 2 && curr->next && curr->next->next) // For second node
        {
            curr->random = curr->next->next;
        }
        else if (count == 3 && curr->next) // For third node
        {
            curr->random = head; // Wrap back to the head
        }
        else if (count == 4 && curr->next) // For fourth node
        {
            curr->random = head->next;
        }
        curr = curr->next;
        count++;
    }
}

void cloneLL(Node *&head, Node *&clonehead)
{
    Node *curr = head;
    // cloned nodes in between original nodes
    while (curr != NULL)
    {
        Node *temp = new Node(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
    }

    // Set the random pointers for the clone nodes
    curr = head;
    while (curr != NULL)
    {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Separate the cloned list from the original list
    curr = head;
    Node *cloneCurr = clonehead;
    while (curr != NULL)
    {
        Node *cloneNode = curr->next;
        curr->next = cloneNode->next;
        if (cloneCurr != NULL)
            cloneCurr->next = cloneNode;
        cloneCurr = cloneNode;
        curr = curr->next;
    }
}

int main()
{
    Node *tail = NULL;
    Node *head = NULL;

    insertattail(tail, 2);
    if (head == NULL)
        head = tail;

    insertattail(tail, 4);
    insertattail(tail, 6);
    insertattail(tail, 8);
    insertattail(tail, 10);

    randomise(head); // Assign random pointers as per logic

    // Cloning the linked list
    Node *clonehead = NULL;
    Node *clonetail = NULL;

    Node *curr = head;
    while (curr != NULL)
    {
        insertattail(clonetail, curr->data);
        if (clonehead == NULL)
            clonehead = clonetail;
        curr = curr->next;
    }

    cloneLL(head, clonehead);

    print(head);
    clonehead = clonehead->next;

    print(clonehead);
    cout << "Cloned list random pointers:" << endl;
    curr = clonehead;
    while (curr != NULL)
    {
        if (curr->random)
            cout << curr->data << " -> " << curr->random->data << endl;
        else
            cout << curr->data << " -> NULL" << endl;
        curr = curr->next;
    }

    return 0;
}
