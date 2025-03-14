#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildbst(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = buildbst(root->left, data);
    }
    else
    {
        root->right = buildbst(root->right, data);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = buildbst(root, data);
        cin >> data;
    }
}
/**
 * This function takes a Binary Search Tree (BST) and converts it into a Doubly Linked List (DLL).
 * The function takes the root of the BST and the head of the DLL as parameters.
 * It first recursively calls itself on the right subtree of the BST and then on the left subtree.
 * It then sets the right pointer of each node in the BST to point to the next node in the DLL.
 * If the head of the DLL is not NULL, it sets the left pointer of the next node in the DLL to point to the current node in the BST.
 * It then sets the head of the DLL to the current node in the BST.
 * Finally, it recursively calls itself on the left subtree of the BST.
 */
void convert_to_DLL(node *root, node *&head)
{
    if (root == NULL)
    {
        return;
    }
    // Recursively call the function on the right subtree of the BST
    convert_to_DLL(root->right, head);
    // Set the right pointer of the current node in the BST to point to the head of the DLL
    root->right = head;
    // If the head of the DLL is not NULL, set the left pointer of the next node in the DLL to point to the current node in the BST
    if (head != NULL)
    {
        head->left = root;
    }
    // Set the head of the DLL to the current node in the BST
    head = root;
    // Recursively call the function on the left subtree of the BST
    convert_to_DLL(root->left, head);
}

/**
 * This function merges two sorted doubly linked lists into a single sorted doubly linked list.
 * It takes two node pointers, h1 and h2, as parameters, which are the heads of the two doubly linked lists to be merged.
 * It returns a pointer to the head of the merged doubly linked list.
 */
node *merge_LL(node *h1, node *h2)
{
    // If either of the two lists is empty, return the other list
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }

    // Initialize the head and tail pointers of the merged list
    node *head = NULL;
    node *tail = NULL;

    // Iterate over both lists until one of them is exhausted
    while (h1 != NULL && h2 != NULL)
    {
        // If the current node in list 1 is smaller than the current node in list 2, add the node from list 1 to the merged list
        if (h1->data < h2->data)
        {
            if (head == NULL)
            {
                // Set the head of the merged list to the current node in list 1
                head = h1;
                // Set the tail of the merged list to the current node in list 1
                tail = h1; // chota sa error h2
            }
            else
            {
                // Set the right pointer of the current node in the merged list to the current node in list 1
                tail->right = h1;
                // Set the left pointer of the current node in list 1 to the current node in the merged list
                h1->left = tail;
                // Set the tail of the merged list to the current node in list 1
                tail = h1;
            }
            // Move to the next node in list 1
            h1 = h1->right;
        }
        // If the current node in list 2 is smaller than the current node in list 1, add the node from list 2 to the merged list
        else
        {
            if (head == NULL)
            {
                // Set the head of the merged list to the current node in list 2
                head = h2;
                // Set the tail of the merged list to the current node in list 2
                tail = h2;
            }
            else
            {
                // Set the right pointer of the current node in the merged list to the current node in list 2
                tail->right = h2;
                // Set the left pointer of the current node in list 2 to the current node in the merged list
                h2->left = tail;
                // Set the tail of the merged list to the current node in list 2
                tail = h2;
            }
            // Move to the next node in list 2
            h2 = h2->right;
        }
    }

    // If there are remaining nodes in list 1, add them to the merged list
    while (h1 != NULL)
    {
        tail->right = h1;
        h1->left = tail;
        tail = h1;
        h1 = h1->right;
    }

    // If there are remaining nodes in list 2, add them to the merged list
    while (h2 != NULL)
    {
        tail->right = h2;
        h2->left = tail;
        tail = h2;
        h2 = h2->right;
    }

    // Return the head of the merged list
    return head;
}
/**
 * @brief Counts the number of nodes in a linked list.
 * @param head The head of the linked list.
 * @return The number of nodes in the linked list.
 */
int countnodes(node *head)
{
    // Initialize a counter to keep track of the number of nodes
    int count = 0;
    // Traverse the linked list until we reach the end
    while (head != NULL)
    {
        // Increment the counter for each node we visit
        count++;
        // Move to the next node in the linked list
        head = head->right;
    }
    // Return the number of nodes in the linked list
    return count;
}
/**
 * @brief Converts a sorted doubly linked list into a balanced binary search tree.
 * @param head The head of the sorted doubly linked list.
 * @param n The number of nodes in the linked list.
 * @return The root of the balanced binary search tree.
 *
 * This function takes a sorted doubly linked list and converts it into a balanced binary search tree.
 * The function takes two parameters, head and n. The head parameter is the head of the sorted doubly linked list.
 * The n parameter is the number of nodes in the linked list.
 * The function returns the root of the balanced binary search tree.
 */
void log(int n, string callType)
{
    static int depth = 0;
    if (callType == "enter")
    {
        cout << string(depth, '-') << "Entering: n = " << n << endl;
        depth++;
    }
    else if (callType == "exit")
    {
        depth--;
        cout << string(depth, '-') << "Exiting: n = " << n << endl;
    }
}
node *convert_LL_to_BST(node *&head, int n)
{
    // If the number of nodes in the linked list is 0 or less, or if the head of the linked list is NULL, return NULL
    log(n, "enter");
    if (n <= 0 || head == NULL)
    {
        log(n, "exit");
        return NULL;
    }
    // Recursively call the function on the left part of the linked list
    node *leftpart = convert_LL_to_BST(head, n / 2);
    // Set the root of the binary search tree to the current node in the linked list
    node *root = head;
    // Set the left pointer of the root of the binary search tree to the left part of the linked list
    root->left = leftpart;
    // Move to the next node in the linked list
    head = head->right;
    // Recursively call the function on the right part of the linked list
    root->right = convert_LL_to_BST(head, n - n / 2 - 1);
    // Return the root of the balanced binary search tree
    return root;
}

void Level_order_traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// merge_2_bst question link : (https://www.geeksforgeeks.org/merge-two-bsts-with-limited-extra-space/)
int main()
{
    node *root1 = NULL;
    takeinput(root1);
    node *root2 = NULL;
    takeinput(root2);
    node *head1 = NULL;
    node *head2 = NULL;
    convert_to_DLL(root1, head1);
    head1->left = NULL;
    convert_to_DLL(root2, head2);
    head2->left = NULL;
    node *head = merge_LL(head1, head2);
    node *root3 = convert_LL_to_BST(head, countnodes(head));
    Level_order_traversal(root3);
    cout << endl;
    inorder(root3);
    return 0;
}

// 5 3 7 2 4 6 8 -1
// 10 6 14 4 8 12 16 -1