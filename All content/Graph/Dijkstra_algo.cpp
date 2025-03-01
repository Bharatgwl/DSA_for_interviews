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
    void addEdge(int x, int y, int weight)
    {
        adj[x].insert(make_pair(y, weight));
        adj[y].insert(make_pair(x, weight));
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
    vector<int> dist(n, INT_MAX);
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
    // g1.addEdge(0, 1, 5);
    // g1.addEdge(0, 2, 8);
    // g1.addEdge(1, 0, 5);
    // g1.addEdge(1, 2, 9);
    // g1.addEdge(1, 3, 2);
    // g1.addEdge(2, 0, 8);
    // g1.addEdge(2, 1, 9);
    // g1.addEdge(2, 3, 6);
    // g1.addEdge(3, 1, 2);
    // g1.addEdge(3, 2, 6);

    g1.addEdge(0, 1, 0);
    g1.addEdge(0, 2, 0);
    g1.addEdge(0, 2, 0);
    g1.printAdjList();
    vector<int> ans = dijkstra(4, g1.adj, 0);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}