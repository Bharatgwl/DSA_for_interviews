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
void Kth_Sum_tree(node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    Kth_Sum_tree(root->left, k, count, path);
    Kth_Sum_tree(root->right, k, count, path);
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    vector<int> path;
    int k = 4;
    int count = 0;
    Kth_Sum_tree(root, k, count, path);
    cout << count << endl;
}