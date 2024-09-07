#include <iostream>
#include <vector>
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
bool checkpalindrome(vector<int> arr)
{

    int s = 0;
    int n = arr.size();
    int e = n - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertattail(tail, 5);
    if (head == NULL)
    {
        head = tail;
    }
    insertattail(tail, 5);
    insertattail(tail, 5);
    insertattail(tail, 51);
    print(head);
    Node *temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    checkpalindrome(arr);
    if (checkpalindrome(arr))
    {
        cout << "Linked list is palindrome :";
        print(head);
    }
    else
    {
        cout << "Linked list is not palindrome :";
        print(head);
        return 0;
    }
}
