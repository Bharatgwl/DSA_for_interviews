#include <iostream>
#include <vector>
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
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void Bst_to_Gst(node *&root, int &sum)
{
    if (root == NULL)
    {
        return;
    }
    Bst_to_Gst(root->right, sum);
    sum += root->data;
    root->data = sum;
    Bst_to_Gst(root->left, sum);
    return;
}
int main()
{

    node *root = NULL;
    takeinput(root);
    int sum = 0;
    inorder(root);
    Bst_to_Gst(root, sum);
     cout<<endl;
    inorder(root);
    
}
