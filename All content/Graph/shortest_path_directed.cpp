#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;
class graph
{
public:
    unordered_map<int, set<pair<int, int>>> adj;
    void addEdge(int u, int v, int dist)
    {
        adj[u].insert(make_pair(v, dist));
    }
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "]";
            }
            cout << endl;
        }
    }
};
void dfs(int node, unordered_map<int, set<pair<int, int>>> adj, unordered_map<int, bool> &visited, stack<int> &toposort)
{
    visited[node] = true;

    for (auto neigbour : adj[node])
    {
        if (!visited[neigbour.first])
        {
            dfs(neigbour.first, adj, visited, toposort);
        }
    }
    toposort.push(node);
}
void getshortestpath(int src, stack<int> &topologicalsort, vector<int> &dist, unordered_map<int, set<pair<int, int>>> adj)
{
    dist[src] = 0;
    while (!topologicalsort.empty())
    {
        int top = topologicalsort.top();
        topologicalsort.pop();

        if (dist[top] != INT_MAX)
        {
            for (auto nb : adj[top])
            {
                if (dist[top] + nb.second < dist[nb.first])
                {
                    dist[nb.first] = dist[top] + nb.second;
                }
            }
        }
    }
}
int main()
{
    graph g1;
    g1.addEdge(0, 1, 5);
    g1.addEdge(0, 2, 3);
    g1.addEdge(1, 2, 2);
    g1.addEdge(1, 3, 6);
    g1.addEdge(2, 3, 7);
    g1.addEdge(2, 4, 4);
    g1.addEdge(3, 4, -1);
    g1.addEdge(2, 5, 2);
    g1.addEdge(4, 5, -2);
    g1.printAdjList();

    unordered_map<int, bool> visited;
    stack<int> toposort;
    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
        {
            dfs(i, g1.adj, visited, toposort);
        }
    }
    vector<int> dist(6, INT_MAX);
    int src = 1;
    getshortestpath(src, toposort, dist, g1.adj);
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "[ \"inf\" ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
    cout<<"]" << endl;

    return 0;
}