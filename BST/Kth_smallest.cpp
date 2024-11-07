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
int kth_smallest(node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = kth_smallest(root->left, i, k);

    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return kth_smallest(root->right, i,k);
}
int main()
{
    node *root = NULL;
    takeinput(root);
    int i=0, k=3;
    cout << "kth smallest element: "<< kth_smallest(root,i,k);
   
}