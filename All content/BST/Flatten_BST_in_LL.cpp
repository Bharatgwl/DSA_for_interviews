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
void Inorder(node *root, vector<node *> &ans)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left, ans);
    ans.push_back(root);
    Inorder(root->right, ans);
}
/**
 * This function takes a vector of inorder nodes of a BST and flattens the BST into a linked list.
 * The function takes the root of the tree as the first element of the vector and then connects all the nodes in the vector as a LL.
 * The left pointer of each node is set to NULL and the right pointer is set to the next element of the vector.
 * The last node of the vector is set to NULL.*/
node *flatten_BST(vector<node *> &vec)
{
    node *root = vec[0];
    int size = vec.size();
    for (int i = 0; i < size - 1; i++)
    {
        vec[i]->left = NULL;
        vec[i]->right = vec[i + 1];
    }
    vec[size - 1]->left = NULL;
    vec[size - 1]->right = NULL;
    return root;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    vector<node *> ino;
    Inorder(root, ino);
    root = flatten_BST(ino);
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
} // 4 2 6 1 3 5 7 -1