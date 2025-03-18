#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, set<int>> adj;
    void addEdge(int u, int v)
    {
        adj[u].insert(v);
        adj[v].insert(u);
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
void dfs(int node, int parent, unordered_map<int, set<int>> &adj, unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low, int &time, vector<int> &Ap)
{
    vis[node] = true;
    disc[node] = low[node] = time++;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, adj, vis, disc, low, time, Ap);

            low[node] = min(low[node], low[nbr]);
            if (low[nbr] >= disc[node] && parent != -1)
            {
                Ap[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if (parent == -1 && child > 1)
    {
        Ap[node] = 1;
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
        g1.addEdge(x, y);
    }

    vector<int> disc(n, -1);
    vector<int> parent(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> vis;
    vector<int> Ap(n, 0);
    int time = 0;

    for (auto &p : g1.adj)
    {
        int node = p.first;
        if (!vis[node])
        {
            dfs(node, -1, g1.adj, vis, disc, low, time, Ap);
        }
    }

    bool found = false;
    cout << "Articulation Points: ";
    for (auto &p : g1.adj)
    {
        if (Ap[p.first] != 0)
        {
            cout << p.first << " ";
            found = true;
        }
    }
    if (!found)
        cout << "None";
    return 0;
}