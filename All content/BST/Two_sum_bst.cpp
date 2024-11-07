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
void Inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}
bool Twosum(int key, vector<int> Inorder)
{
    int sum = 0;
    int i = 0;
    int j = Inorder.size() - 1;
    while (i < j)
    {
        sum = Inorder[i] + Inorder[j];
        if (sum == key)
        {
            return true;
        }
        else if (sum < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}
int main()
{
    node *root = NULL;
    takeinput(root);
    int a = 50;
    vector<int> inorder;
    Inorder(root, inorder);
    if (Twosum(a, inorder))
    {
        cout << "sum exist : " << endl;
    }
    else
    {
        cout << "sum doesn't exist : " << endl;
    }
} // 10 6 12 2 8 11 15 -1