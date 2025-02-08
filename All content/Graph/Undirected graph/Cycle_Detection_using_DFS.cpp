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
bool traverse(int node, int parent, unordered_map<int, set<int>> adj, unordered_map<int, bool> visited)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycledeteced = traverse(neighbour, node, adj, visited);
            return cycledeteced;
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
}
bool isCyclicDFS(int n, unordered_map<int, set<int>> &adj)
{
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (traverse(i, -1, adj, visited))
            {
                return true;
            }
        }
    }
    return false;
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
    if (isCyclicDFS(n, g1.adj))
    {
        cout << "graph contains cycle" << endl;
    }
    else
    {
        cout << "graph does not contain cycle" << endl;
    }
}