#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *construct(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
Node *insatend(Node *head, int value)
{
    Node *newnode = construct(value);
    if (head == NULL)
    {
        return newnode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
Node *insertatbeg(Node *head, int value)
{
    Node *nn = construct(value);
    if (head == NULL)
    {
        return nn;
    }
    nn->next = head;

    return nn;
}
Node *delete(Node *head, int d)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    if (head->data == d)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp->data != d)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    temp->next = NULL;
    free(temp);

    return head;
}
Node *insmid(Node *head, int midvalue, int data)
{
    if (head == NULL)
    {
        Node *newnode = construct(data);
        return newnode;
    }
    Node *temp = head;
    while (temp->data != midvalue && temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newnode = construct(data);
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("NULL");
    }
    printf("\n");
    return;
}
int main()
{
    Node *head = NULL;
    head = insatend(head, 10);
    head = insatend(head, 20);
    head = insatend(head, 30);
    head = insatend(head, 40);
    head = insatend(head, 50);
    head = insatend(head, 60);
    head = insatend(head, 70);
    head = insatend(head, 80);
    head = insatend(head, 90);

    head = insertatbeg(head, 100);
    head = insertatbeg(head, 1000);
    head = insertatbeg(head, 120);
    head = insertatbeg(head, 130);

    print(head);

    head = insmid(head, 130, 90);
    head = insmid(head, 90, 5);
    head = insmid(head, 5, 90);
    head = insmid(head, 90, 1);
    head = insmid(head, 1, 90);
    head = insmid(head, 1000, 9000);

    print(head);
    head = delete (head, 130);
    print(head);
   
    
}