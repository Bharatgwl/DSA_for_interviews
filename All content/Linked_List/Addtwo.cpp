#include <bits/stdc++.h>
using namespace std;

// Node structure
template <typename T>
class Node
{
public:
    T val;
    Node *next;
    Node(T val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

// Function to reverse a linked list
Node<int> *reverse(Node<int> *head)
{
    Node<int> *prev = nullptr, *curr = head, *forward = nullptr;
    while (curr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Function to add two numbers represented as linked lists
Node<int> *addTwoNumbers(Node<int> *l1, Node<int> *l2)
{
    Node<int> *h1 = reverse(l1);
    Node<int> *h2 = reverse(l2);
    Node<int> *dummy = new Node<int>(0);
    Node<int> *h3 = dummy;
    int carry = 0;

    while (h1 || h2 || carry)
    {
        int sum = (h1 ? h1->val : 0) + (h2 ? h2->val : 0) + carry;
        carry = sum / 10;
        h3->next = new Node<int>(sum % 10);
        h3 = h3->next;

        if (h1)
            h1 = h1->next;
        if (h2)
            h2 = h2->next;
    }

    Node<int> *result = reverse(dummy->next);
    delete dummy; // Free unused memory
    return result;
}

// Function to insert a node at the end
void insert(Node<int> *&head, int val)
{
    Node<int> *newNode = new Node<int>(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node<int> *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print a linked list
void printList(Node<int> *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main()
{
    Node<int> *l1 = nullptr;
    Node<int> *l2 = nullptr;

    // Insert values into l1
    insert(l1, 2);
    insert(l1, 4);
    insert(l1, 9);
   

    // Insert values into l2
    insert(l2, 5);
    insert(l2, 6);
    insert(l2, 4);
    insert(l2, 9);

    // Perform addition
    Node<int> *l3 = addTwoNumbers(l1, l2);

    // Print result
    printList(reverse(l3));

    return 0;
}
