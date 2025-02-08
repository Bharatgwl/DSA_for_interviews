#include <iostream>
#include <unordered_map>
#include <set> //to store in a sorted order
#include <vector>
#include <queue>
using namespace std;

class graph
{
public:
    unordered_map<int, set<int>> adj;
    void addEdge(int x, int y, int directed)
    {
        adj[x].insert(y);
        if (directed == 0)
        {
            adj[y].insert(x);
        }
    }
    void printAdjset()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
void DFSUtil(int srcnode, unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
{
    visited[srcnode] = true;
    ans.push_back(srcnode);
    for (int i : adj[srcnode])
    {
        if (!visited[i])
        {
            DFSUtil(i, adj, visited, ans);
        }
    }
}
vector<int> DFS(int n, unordered_map<int, set<int>> &adj)
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i, adj, visited, ans);
        }
    }
    return ans;
}
int main()
{
    graph g1;
    int n;
    cout << "enter the number of nodes" << endl;
    cin >> n;
    int m;
    cout << "enter the number of edges" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y, 0);
    }
    vector<int> ans = DFS(n, g1.adj);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    // g1.printAdjset();
}