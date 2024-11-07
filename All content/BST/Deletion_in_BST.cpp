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
int min_value(node *root)
{
    node *curr = root;
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr->data;
}
void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
node *Delete(node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->data == x)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL) // Right minimum approach to delete a node from BST
        {
            int minivalue = min_value(root->right);
            root->data = minivalue;
            root->right = Delete(root->right, minivalue);
            return root;
        }
    }
    else if (x < root->data)
    {
        root->left = Delete(root->left, x);
        return root;
    }
    else
    {
        root->right = Delete(root->right, x);
        return root;
    }
}
int main()
{
    node *root = NULL;
    takeinput(root);
    cout << "before deleting : " << endl;
    cout << "inorder: " << endl;
    Inorder(root);
    cout << endl;
    cout << "Level order: " << endl;
    Level_order_traversal(root);

    root = Delete(root, 25);

    cout << "after deleting : " << endl;
    cout << "inorder: " << endl;
    Inorder(root);
    cout << endl;

    cout << "Level order: " << endl;
    Level_order_traversal(root);
}
