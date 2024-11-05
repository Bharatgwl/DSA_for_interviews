#include <iostream>
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
pair<int, int> Predecessor_and_successor(node *root, int key)
{
    node *temp = root;
    int pred = -1;
    int succ = -1;
    // find key
    while (temp->data != key)
    {
        if (temp->data < key)
        {
            pred = temp->data;
            temp = temp->right;
        }
        else
        {
            succ = temp->data;
            temp = temp->left;
        }
    }
    // find pred and succ after finding key
    node *left = temp->left;
    while (left != NULL)
    {
        pred = left->data;
        left = left->right; // finding left maximum
    }
    node *right = temp->right;
    while (right != NULL)
    {
        succ = right->data;
        right = right->left; // finding right minimum
    }
    return {pred, succ};
}
int main()
{
    node *root = NULL;
    takeinput(root);
    int key = 8;
    pair<int, int> ans = Predecessor_and_successor(root, key);
    cout << ans.first << " " << ans.second << endl;
}