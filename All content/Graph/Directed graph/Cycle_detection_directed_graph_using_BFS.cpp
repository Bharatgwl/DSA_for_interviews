#include <iostream>
#include <unordered_map>
#include <set>
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

bool Kahns(int n, unordered_map<int, set<int>> &adj)
{
    unordered_map<int, int> indegree;
    // Initialize indegree of all nodes to 0
    for (auto &node : adj)
    {
        indegree[node.first] = 0;
    }

    // Calculate indegree
    for (auto &node : adj)
    {
        for (auto &neighbor : node.second)
        {
            indegree[neighbor]++;
        }
    }

    // Push nodes with indegree 0 into the queue
    queue<int> q;
    for (auto &node : indegree)
    {
        if (node.second == 0)
        {
            q.push(node.first);
        }
    }
    int count = 0;
    // Perform Kahn's algorithm
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        count++;

        for (auto neighbor : adj[temp])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // Check for a cycle
    if (count < n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    graph g1;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (format: x y): " << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y, 1);
    }

    if (Kahns(n, g1.adj))
    {
        cout << "Graph contains cycle";
    }
    else
    {
        cout << "Graph doesn't contain any cycle";
    }
    return 0;
}
// 8
// 9
// 1 2
// 2 3
// 2 4
// 3 7
// 3 8
// 4 5
// 5 6
// 6 4
// 8 7