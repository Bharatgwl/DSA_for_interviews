#include <iostream>
#include <unordered_map>
#include <set> //to store in a sorted order
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, set<pair<int, int>>> adj;
    void addEdge(int x, int y, int weight, int directed)
    {
        if (directed == 0)
        {
            adj[x].insert(make_pair(y, weight));
            adj[y].insert(make_pair(x, weight));
        }
        else
        {
            adj[x].insert(make_pair(y, weight));
        }
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
vector<int> dijkstra(int n, unordered_map<int, set<pair<int, int>>> adj, int src)
{
    // Initialize distances vector with infinity
    // Set the distance to the source node to 0
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    // Use a set to store and fetch nodes in order of their current known distance
    set<pair<int, int>> s;
    s.insert({0, src}); //

    // Process nodes until there are no nodes left to process in the set
    while (!s.empty())
    {
        // Fetch the node with the minimum distance
        auto top = *(s.begin());
        int distance = top.first; // Minimum distance to this node
        int node = top.second;    // Node index
        s.erase(s.begin());       // Remove this entry from the set

        // Explore all adjacent nodes (neighbors) of the current node
        for (auto neighbor : adj[node])
        {
            // Calculate the new possible distance to the neighbor
            if (distance + neighbor.second < dist[neighbor.first])
            {
                // Find if there's already an entry for this neighbor in the set
                auto newentry = s.find(make_pair(dist[neighbor.first], neighbor.first));
                // If found, erase the old entry
                if (newentry != s.end())
                {
                    s.erase(newentry);
                }
                // Update the distance of the neighbor to the new minimum distance
                dist[neighbor.first] = distance + neighbor.second;
                // Insert the updated distance and node pair back into the set
                s.insert(make_pair(dist[neighbor.first], neighbor.first));
            }
        }
    }
    // Return the vector containing the shortest distances from the source to each node
    return dist;
}
int main()
{
    graph g1;

    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, weight;
        cout << "Enter the edge: ";
        cin >> x >> y;
        cout << "Enter the weight of the edge: " << x << " " << y <<": ";
        cin >> weight;
        g1.addEdge(x, y, weight, 0);
    }

    // g1.printAdjList();
    vector<int> ans = dijkstra(n, g1.adj, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// Time complexity: O(ElogV)
// Space complexity: O(V)
// input
// 6
// 9
// 1 2
// 7
// 1 3
// 9
// 1 6
// 14
// 2 3
// 10
// 2 4
// 15
// 3 6
// 2
// 3 4
// 11
// 4 5
// 8
// 5 6
// 9
// // output
// 0->[1,7][3,9][6,14]
// 1->[2,7][3,9][6,14][0,7]
// 2->[1,7][3,9][6,14][0,7][4,10]
// 3->[1,7][2,7][6,14][0,7][4,10][5,11]
// 4->[2,7][3,9][6,14][0,7][5,11]
// 5->[3,9][4,10][6,14][0,7]
// 6->[1,7][3,9][5,11][0,7]

