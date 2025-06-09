#include <iostream>
#include <set>
#include <unordered_map>
#include <limits.h>
#include <vector>
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
vector<pair<pair<int, int>, int>> prims(int n, unordered_map<int, set<pair<int, int>>> adj)
{
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mst(n, false);
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int mini = INT_MAX;
        int u;
        // find the vertex with minimum key value
        for (int v = 0; v < n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }
        mst[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v]) 
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 1; i < n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}
int main()
{
    graph g1;
    g1.addEdge(0, 1, 2);
    g1.addEdge(0, 3, 6);
    g1.addEdge(1, 2, 3);
    g1.addEdge(1, 3, 8);
    g1.addEdge(1, 4, 5);
    g1.addEdge(2, 4, 7);

    g1.printAdjList();
    int minimum_cost = 0;
    for (auto i : prims(5, g1.adj))
    {
        cout << i.first.first << " " << i.first.second << " " << i.second << endl;
        minimum_cost += i.second;
    }
    cout << "Minimum cost of spanning tree is " << minimum_cost << endl;
    return 0;
}