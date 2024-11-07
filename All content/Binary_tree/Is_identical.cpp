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
bool is_identical(node *r1, node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    bool left = is_identical(r1->left, r2->left);
    bool right = is_identical(r1->right, r2->right);
    bool value = r1->data == r2->data;
    if (left && right && value)
    {

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *root;
    node *root2;
    root = buildtree(root);
    root2 = buildtree(root2);
    Level_order_traversal(root);
    Level_order_traversal(root2);
    if (is_identical(root, root2))
    {
        cout << "trees are identical" << endl;
    }
    else
    {
        cout << "trees are not identical" << endl;
    }
}
// 1 2 3 -1 -1 4 -1 -1 5 -1 6 7 -1 -1 8 -1 -1