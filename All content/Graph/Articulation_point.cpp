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
/**
 * @brief This function performs a Depth-First Search (DFS) on the graph
 * starting from the given node. It's used to find the Articulation Points in
 * the graph.
 *
 * @param node The node from which the DFS should start.
 * @param parent The parent node of the current node. This is used to detect
 * cycles.
 * @param adj The adjacency list of the graph.
 * @param vis A boolean array to keep track of visited nodes.
 * @param disc A vector to store the discovery time of each node.
 * @param low A vector to store the lowest discovery time reachable from each
 * node.
 * @param time A variable to keep track of the current time.
 * @param Ap A vector to store the Articulation Points.
 */
void dfs(int node, int parent, unordered_map<int, set<int>> &adj,
         unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low,
         int &time, vector<int> &Ap)
{
    // Mark the current node as visited
    vis[node] = true;

    // Set the discovery time and the lowest reachable time of the current node
    disc[node] = low[node] = time++;

    // Initialize the number of children of the current node
    int child = 0;

    // Iterate over all the neighbours of the current node
    for (auto nbr : adj[node])
    {
        // If the neighbour is the parent node, skip it
        if (nbr == parent)
        {
            continue;
        }

        // If the neighbour has not been visited before, recursively call the
        // dfs function on it
        if (!vis[nbr])
        {
            dfs(nbr, node, adj, vis, disc, low, time, Ap);

            // Update the lowest reachable time of the current node
            low[node] = min(low[node], low[nbr]);

            // If the current node is an Articulation Point, mark it
            if (low[nbr] >= disc[node] && parent != -1)
            {
                Ap[node] = 1;
            }

            // Increment the number of children
            child++;
        }
        else
        {
            // If the neighbour has already been visited, update the lowest
            // reachable time of the current node
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // If the current node is the root node and has more than one child, it's
    // an Articulation Point
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
        if (Ap[p.first]    != 0)
        {
            cout << p.first    << " ";
            found = true   ;
        }
    }
    if (!found)
        cout << "None";
    return 0;
}