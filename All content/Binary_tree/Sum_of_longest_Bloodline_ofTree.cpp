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
void Sum_of_longest_Bloodline_of_Tree(node *root, int sum, int &maxsum, int len, int &maxlen)
{
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxsum = sum;
            maxlen = len;
        }
        else if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
            maxlen = max(len, maxlen);
        }
        return;
    }
    sum += root->data;
    Sum_of_longest_Bloodline_of_Tree(root->left, sum, maxsum, len + 1, maxlen);
    Sum_of_longest_Bloodline_of_Tree(root->right, sum, maxsum, len + 1, maxlen);
}
int main()
{
    int maxsum = 0, len = 0, maxlen = 0, sum = 0;
    node *root = NULL;
    root = buildtree(root);
    Sum_of_longest_Bloodline_of_Tree(root, sum, maxsum, len, maxlen);
    cout << "<" << maxsum << "," << maxlen << ">" << endl;
  
}