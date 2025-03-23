#include <bits/stdc++.h>
using namespace std;
class Graph
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

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

void Topological_sort(int node, stack<int> &st, unordered_map<int, set<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            Topological_sort(nbr, st, adj, vis);
        }
    }
    st.push(node);
}

void Transpose_Graph(unordered_map<int, set<int>> &adj, unordered_map<int, set<int>> &transpose_graph)
{
    for (auto &p : adj)
    {
        int node = p.first;
        for (auto nbr : p.second)
        {
            transpose_graph[nbr].insert(node);
        }
    }
}

void Dfs_of_transpose(int node, unordered_map<int, bool> &vis, unordered_map<int, set<int>> Transpose_Graph)
{
    cout << "Visiting node: " << node << endl;
    vis[node] = true;

    for (auto nbr : Transpose_Graph[node])
    {
        cout << "Visiting neighbour: " << nbr << endl;
        if (!vis[nbr])
        {
            Dfs_of_transpose(nbr, vis, Transpose_Graph);
        }
    }
}
int main()
{

    Graph g1;

    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y, 1);
    }
    unordered_map<int, bool> vis;
    stack<int> st;
    for (auto &node : g1.adj)
    {
        int n = node.first;
        if (!vis[n])
        {
            Topological_sort(n, st, g1.adj, vis);
        }
    }

    unordered_map<int, set<int>> transpose_graph;

    Transpose_Graph(g1.adj, transpose_graph);

    vis.clear();
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            count++;
            Dfs_of_transpose(top, vis, transpose_graph);
        }
    }

    cout << "Graph contains " << count << " number of Strongly connected component" << endl;

    return 0;
}