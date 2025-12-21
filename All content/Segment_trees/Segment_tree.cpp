#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
    vector<int> tree;
    int n;

    void buildTree(const vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int queryTree(int node, int start, int end, int L, int R)
    {
        if (R < start || end < L)
        {
            return 0; // Out of range
        }
        if (L <= start && end <= R)
        {
            return tree[node]; // Current segment is totally within range
        }
        int mid = (start + end) / 2;
        int p1 = queryTree(2 * node + 1, start, mid, L, R);
        int p2 = queryTree(2 * node + 2, mid + 1, end, L, R);
        return p1 + p2;
    }
    int main() 
    {

        return 0;
    }