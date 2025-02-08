#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
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

vector<int> shortestpath(int n, unordered_map<int, set<int>> adj, int src, int dest)
{
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;

    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto nb : adj[front])
        {
            if (!visited[nb])
            {
                visited[nb] = true;
                parent[nb] = front;
                q.push(nb);
            }
        }
    }
    vector<int> ans;
    int current = dest;
    ans.push_back(current);
    while (current != src)
    {
        current = parent[current];
        ans.push_back(current);
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
        g1.addEdge(x, y, 0);
    }

    int src, dest;
    cout << "Enter the source and destination: ";
    cin >> src >> dest;
    vector<int> ans = shortestpath(n, g1.adj, src, dest);
    cout << "Shortest path: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;

// 8
// 9
// 1 2
// 1 3
// 1 4
// 2 5
// 3 8
// 4 6
// 5 8
// 6 7
// 7 8
}