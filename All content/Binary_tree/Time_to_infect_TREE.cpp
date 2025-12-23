#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    void make_adj(unordered_map<int, vector<int>> &mp, int parent,
                  TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (parent != -1)
        {
            mp[root->val].push_back(parent);
        }
        if (root->left)
        {
            mp[root->val].push_back(root->left->val);
        }
        if (root->right)
        {
            mp[root->val].push_back(root->right->val);
        }
        make_adj(mp, root->val, root->left);
        make_adj(mp, root->val, root->right);
    }
    int solve(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> mp;
        make_adj(mp, -1, root);

        queue<int> q;
        unordered_set<int> seen;
        seen.insert(start);
        q.push(start);
        int count = 0;

        while (!q.empty())
        {
            int n = q.size();

            // processing the all level nodes first
            while (n--)
            {
                int front = q.front();
                q.pop();
                for (auto ngbr : mp[front])
                {
                    if (seen.find(ngbr) == seen.end())
                    {
                        q.push(ngbr);
                        seen.insert(ngbr);
                    }
                }
            }
            count++;
        }
        return count;
    }

    TreeNode *createmapping(TreeNode *root, int target,
                            map<TreeNode *, TreeNode *> &mapping)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res = NULL;
        mapping[root] = NULL;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->val == target)
            {
                res = temp;
            }
            if (temp->left)
            {
                mapping[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                mapping[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return res;
    }
    int burnTree(TreeNode *targetnode, map<TreeNode *, TreeNode *> mapping)
    {
        int ans = 0;
        map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(targetnode);
        visited[targetnode] = true;
        while (!q.empty())
        {

            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left && !(visited[front->left]))
                {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && !(visited[front->right]))
                {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if (mapping[front] && !(visited[mapping[front]]))
                {
                    flag = true;
                    q.push(mapping[front]);
                    visited[mapping[front]] = true;
                }
            }
            if (flag == true)
            {
                ans++;
            }
        }
        return ans;
    }
    int res = INT_MIN;
    int solveDFS(TreeNode *root, int start)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = solveDFS(root->left, start);
        int right = solveDFS(root->right, start);

        if (root->val == start)
        {
            res = max(left, right);
            return -1; // infected node yaha se start h
        }
        else if (left >= 0 && right >= 0)
        {
            return max(left, right) + 1;
        }
        else
        {
            int total = abs(left) + abs(right);
            res = max(res, total);
            return min(left, right) - 1;
        }
        return 0;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        // BFS Approach 1
        // map<TreeNode*, TreeNode*> nodeTOparent;

        // TreeNode* targetNode = createmapping(root, start, nodeTOparent);

        // int ans = burnTree(targetNode, nodeTOparent);
        // return ans;

        // BFS Approach 2
        // return solve(root, start) - 1;
        solveDFS(root, start);
        return res;
    }
};

int main()
{
    Solution s;
    
    return 0;
}
