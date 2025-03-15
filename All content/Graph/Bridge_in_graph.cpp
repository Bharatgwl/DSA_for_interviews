#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, set<int>> adj;

    void addedge(int x, int y)
    {
        adj[x].insert(y);
        adj[y].insert(x);
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

void dfs(int node, int parent, unordered_map<int, set<int>> &adj,
         vector<bool> &vis, vector<int> &disc, vector<int> &low, int &time, vector<pair<int, int>> &bridges)
{
    vis[node] = true;
    disc[node] = low[node] = time++;

    for (auto neighbor : adj[node])
    {
        if (neighbor == parent)
            continue; 

        if (!vis[neighbor])
        {
            dfs(neighbor, node, adj, vis, disc, low, time, bridges);
            low[node] = min(low[node], low[neighbor]);

            if (low[neighbor] > disc[node])
            {
                bridges.push_back({node, neighbor});
            }
        }
        else
        {
            low[node] = min(low[node], disc[neighbor]); 
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
        g1.addedge(x, y);
    }

    vector<bool> vis(n, false);
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<pair<int, int>> bridges;
    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, g1.adj, vis, disc, low, time, bridges);
        }
    }

    g1.printAdjList();

    
    cout << "Bridges in the graph:\n";
    for (auto bridge : bridges)
    {
        cout << bridge.first << " --- " << bridge.second << endl;
    }

    return 0;
}
