#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class graph
{
public:
    unordered_map<int, unordered_set<int>> adj;
    void addEdge(int x, int y, int directed)
    {
        adj[x].insert(y);
        if (directed == 0)
        {
            adj[y].insert(x);
        }
    }
    void printAdjunordered_set()
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
bool UTIL(int node, unordered_map<int, unordered_set<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &callmap)
{
    visited[node] = true;
    callmap[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (UTIL(neighbour, adj, visited, callmap))
            {
                return true;
            }
        }
        else if (callmap[neighbour])
        {
            return true;
        }
    }
    callmap[node] = false;
    return false;
}
bool isCyclic_directed(int n, unordered_map<int, unordered_set<int>> &adj)
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> callmap;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (UTIL(i, adj, visited, callmap))
            {
                return true;
            }
        }
    }
    return false;
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

    if (isCyclic_directed(n, g1.adj))
    {
        cout << "Graph contains cycle" << endl;
    }
    else
    {
        cout << "Graph does not contain cycle" << endl;
    }
    // g1.printAdjunordered_set();
    return 0;
    /*Sample Input
    7
    8
    1 2
    1 3
    2 4
    2 5
    3 6
    4 7
    5 7
    */

    //    1 2
    //    2 3
    //    2 4
    //    3 7
    //    3 8
    //    4 5
    //    5 6
    //    6 4
    //    8 7
}