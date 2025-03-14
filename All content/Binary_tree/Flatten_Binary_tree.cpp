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
node *buildtree(node *&root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter for left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter for right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
node *Flatten_tree(node *root)
{
    // Start with the root node
    node *curr = root;
    
    // Traverse the tree using the right pointers
    while (curr != NULL)
    {
        // If the current node has a left child
        if (curr->left != NULL)
        {
            // Find the rightmost node of the left subtree (inorder predecessor)
            node *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            
            // Link the rightmost node of the left subtree to the current node's right child
            pred->right = curr->right;
            
            // Move the left subtree to the right, effectively flattening the tree
            node *temp = curr->left;
            curr->right = temp;
            
            // Set the left child of the current node to NULL
            curr->left = NULL;
        }
        
        // Move to the next node in the list (originally the right child)
        curr = curr->right;
    }
    
    // Return the root of the modified tree
    return root;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    root = Flatten_tree(root);
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
}