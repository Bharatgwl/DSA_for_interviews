#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
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
void dfs(int node, unordered_map<int, set<int>> adj, unordered_map<int, bool> &visited, stack<int> &s)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited, s);
        }
    }
    s.push(node);
    return;
}

void topological_sort(int n, unordered_map<int, set<int>> adj)
{
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, s);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
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
        g1.addEdge(x, y, 1);
    }
    topological_sort(n, g1.adj);

    // g1.printAdjset();
    return 0;
}