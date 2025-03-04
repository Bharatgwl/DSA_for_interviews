#include <iostream>
#include <vector>
using namespace std;
//  https://www.geeksforgeeks.org/convert-bst-to-min-heap/
// Time complexity: O(n) where n is the number of nodes in the tree

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
node *BuildBST(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = BuildBST(root->left, data);
    }
    else
    {
        root->right = BuildBST(root->right, data);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        BuildBST(root, data);
        cin >> data;
    }
}
void inorder(node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);


    //  helllo 
}

// This function transforms a binary tree into a min-heap using an array of values.
// It takes a pointer to the root node of the tree, a reference to a vector containing
// the values in the desired order (in this case, sorted to satisfy min-heap property),
// and a reference to an integer index which tracks the position in the vector.
// this function is creating heap from inorder traversal of BST which is already sorted
// in increasing order so that it can be transformed into min-heap 
// but to follow the min-heap extra property for the question
//  property we need to make sure that the left child is always smaller 
// than the right child so we replace existing tree values with the values from the array in sorted order
// in the *PREORDER FASHION* 


void createminheap(node *root, vector<int> &arr, int &i)
{
    // Base case: If the current node is NULL, return immediately as there's nothing to process.
    if (root == NULL)
    {
        return;
    }

    // Assign the current element from the array to the node's data field.
    // This effectively places the value from the array into the tree node,
    // adhering to the order defined in the array.
    root->data = arr[i++];

    // Recursively transform the left subtree into a min-heap.
    // The left child is processed next to ensure the heap property is maintained.
    createminheap(root->left, arr, i);

    // Recursively transform the right subtree into a min-heap.
    // The right child is processed after the left child.
    createminheap(root->right, arr, i);
}
int main()
{
    node *root = NULL;
    takeinput(root);
    vector<int> arr;
    inorder(root, arr);
    int i = 0;
    for (auto i : arr)
    {
        cout << i << " ";
    }cout<<endl;
    createminheap(root, arr, i);
    arr.clear();
    inorder(root, arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    
}