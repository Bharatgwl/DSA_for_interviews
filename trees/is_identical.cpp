#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node() {}
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *&r1)
{
    cout << "enter the data" << endl;
    int data;
    cin >> data;
    r1 = new node(data);
    if (data == -1)
    {
        return nullptr;
    }
    cout << " enter the for left of " << data << endl;
    r1->left = buildtree(r1->left);
    cout << "for right of " << data << endl;
    r1->right = buildtree(r1->right);
    return r1;
}
void levelorderTraversal(node *r1)
{
    queue<node *> q;
    q.push(r1);
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
    if (r1 == nullptr && r2 == nullptr)
        return true;

    if (r1 != nullptr && r2 == nullptr)
        return false;

    if (r1 == nullptr && r2 != nullptr)
        return false;

    bool leftside = is_identical(r1->left, r2->left);
    bool rightside = is_identical(r1->right, r2->right);
    bool value = r1->data == r2->data;
    if (leftside && rightside && value)
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
    node *r2;
    node *r1;
    r1 = buildtree(r1);
    r2 = buildtree(r2);
    levelorderTraversal(r2);
    levelorderTraversal(r1);
    if (is_identical(r1, r2))
    {
        cout << "tree is identical";
    }
    else
    {
        cout << "tree is not identical";
    }
} // 1 2 -1 -1 3 -1 -1 input 1
// 1 10 5 11 -1 -1 -1 -1 30 -1 -1 input 2