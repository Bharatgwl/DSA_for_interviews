#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node *next;

        Node(T val) : data(val), next(nullptr) {}
    };

    Node *head;

    Node *Sort(Node *node);
    Node *merge(Node *left, Node *right);

    // Helper function for deep copy
    void copyList(const LinkedList &other);

public:
    LinkedList() : head(nullptr) {}

    // Deep Copy Constructor
    LinkedList(const LinkedList &other)
    {
        head = nullptr;
        copyList(other);
    }

    // Destructor
    ~LinkedList();

    // Insert function
    void insert(T data);

    // Display function
    void display() const;

    // Remove function
    void remove(T data);

    // Reverse function
    void reverse();

    // Rotate function
    Node *rotateLL(int k);

    // Sort function
    void Sort();
};

// Deep copy helper function
template <typename T>
void LinkedList<T>::copyList(const LinkedList &other)
{
    if (other.head == nullptr)
    {
        head = nullptr;
        return;
    }

    head = new Node(other.head->data);
    Node *tempOther = other.head->next;
    Node *tempThis = head;

    while (tempOther != nullptr)
    {
        tempThis->next = new Node(tempOther->data);
        tempThis = tempThis->next;
        tempOther = tempOther->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
void LinkedList<T>::insert(T data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <typename T>
void LinkedList<T>::display() const
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "->nullptr" << endl;
}

template <typename T>
void LinkedList<T>::remove(T data)
{
    if (head == nullptr)
        return;

    if (head->data == data)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->data != data)
    {
        current = current->next;
    }

    if (current->next == nullptr)
        return;

    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}

template <typename T>
void LinkedList<T>::reverse()
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::rotateLL(int k)
{
    if (head == nullptr || k == 0)
        return head;

    Node *temp = head;
    int len = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        len++;
    }

    temp->next = head;

    k = k % len;
    int skip = len - k;

    Node *newHeadPrev = head;
    for (int i = 1; i < skip; i++)
    {
        newHeadPrev = newHeadPrev->next;
    }

    head = newHeadPrev->next;
    newHeadPrev->next = nullptr;

    return head;
}

template <typename T>
void LinkedList<T>::Sort()
{
    head = Sort(head);
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Sort(Node *node)
{
    if (node == nullptr || node->next == nullptr)
        return node;

    Node *slow = node;
    Node *fast = node->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *right = slow->next;
    slow->next = nullptr;

    Node *left = Sort(node);
    right = Sort(right);

    return merge(left, right);
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::merge(Node *left, Node *right)
{
    Node dummy(0);
    Node *current = &dummy;

    while (left != nullptr && right != nullptr)
    {
        if (left->data <= right->data)
        {
            current->next = left;
            left = left->next;
        }
        else
        {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left != nullptr)
        current->next = left;
    else
        current->next = right;

    return dummy.next;
}

#endif
