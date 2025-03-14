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
Node *findmid(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr&&fast->next!=nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        head = curr;
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
bool ispalindrome(Node *head1, Node *&head2)
{
    while (head2 != nullptr)
    {
        if (head1->data != head2->data)
        {
      
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insertattail(tail, value);
        if (head == nullptr)
        {
            head = tail;
        }
    }

    print(head);
    Node *mid = findmid(head);
    // print(mid);

    Node *temp = mid->next;
    mid->next = reverse(temp);

    if (ispalindrome(head, mid->next))
    {
        cout << "LL is palindrome " <<endl;
       
    }
    else
    {
        cout << "LL is not palindrome "<<endl;
    }
   mid->next= reverse(temp);
    cout<<"your original LL is : "; print(head);
}
