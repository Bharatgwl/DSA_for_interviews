#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(node *&tail, int data)
{
    if (tail == NULL)
    {
        tail = new node(data);
        return;
    }
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        
    }
    cout <<"NULL"<< endl;
}

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

node *merge_K_sorted_Linked_list(vector<node *> llheads)
{
    int k = llheads.size();
    priority_queue<node *, vector<node *>, compare> mini;

    // Push the first node of each list into the min-heap
    for (int i = 0; i < k; i++)
    {
        if (llheads[i] != NULL) // Check if the list is not empty
        {
            mini.push(llheads[i]);
        }
    }

    node *head = NULL;
    node *tail = NULL;

    // Process the nodes from the min-heap
    while (!mini.empty())
    {
        node *topnode = mini.top(); // Extracting the node with the smallest value
        mini.pop();

        // If the next node exists, push it to the heap
        if (topnode->next != NULL)
        {
            mini.push(topnode->next);
        }

        // Initialize the head and tail of the merged linked list
        if (head == NULL)
        {
            head = topnode;
            tail = topnode;
        }
        else
        {
            tail->next = topnode;
            tail = tail->next; // Update the tail to the newly added node
        }
    }

    return head;
}

int main()
{
    node *t1 = NULL;
    node *h1 = NULL;
    node *t2 = NULL;
    node *h2 = NULL;
    node *t3 = NULL;
    node *h3 = NULL;

    // Creating 3 sorted linked lists
    for (int i = 1; i <= 5; i++)
    {
        insertattail(t1, i);     // 1 -> 2 -> 3 -> 4 -> 5
        insertattail(t2, i + 1); // 2 -> 3 -> 4 -> 5 -> 6
        insertattail(t3, i * 3); // 3 -> 6 -> 9 -> 12 -> 15
        if (h1 == NULL || h2 == NULL || h3 == NULL)
        {
            h1 = t1;
            h2 = t2;
            h3 = t3;
        }
    }

    vector<node *> heads = {h1, h2, h3};

    node *head = merge_K_sorted_Linked_list(heads);
    print(head); // Expected output: 1 2 2 3 3 4 4 5 5 6 6 9 12 15

    return 0;
}
