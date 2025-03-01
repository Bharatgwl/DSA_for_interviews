#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <limits.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int x, int y, int weight)
    {
        adj[x].push_back({y, weight});
        adj[y].push_back({x, weight});
    }

    void printAdjList()
    {
        for (auto &i : adj)
        {
            cout << i.first << " -> ";
            for (auto &j : i.second)
            {
                cout << "[" << j.first << ", " << j.second << "] ";
            }
            cout << endl;
        }
    }
};

vector<pair<pair<int, int>, int>> prims(int n, unordered_map<int, vector<pair<int, int>>> &adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    minHeap.push({0, 0});
    key[0] = 0;

    while (!minHeap.empty())
    {
        int u = minHeap.top().second; // get the vertex with the minimum key value
        minHeap.pop();

        inMST[u] = true;

        for (auto &it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                minHeap.push({key[v], v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> mstEdges;
    for (int i = 1; i < n; i++)
    {
        mstEdges.push_back({{parent[i], i}, key[i]});
    }
    return mstEdges;
}

int main()
{
    Graph g;
    // g.addEdge(0, 1, 2);
    // g.addEdge(0, 3, 6);
    // g.addEdge(1, 2, 3);
    // g.addEdge(1, 3, 8);
    // g.addEdge(1, 4, 5);
    // g.addEdge(2, 4, 7);
    int u,v,weight;
    int edges=3;
    for (int i =0; i<edges; i++){
        cin >> u >> v >> weight;
        g.addEdge(u,v,weight);
    }
    cout<<"adjacent list"<<endl;
    g.printAdjList();

    int minimum_cost = 0;
    auto result = prims(5, g.adj);
    cout<<"result path"<<endl;
    for (auto &edge : result)
    {
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
        minimum_cost += edge.second;
    }

    cout << "Minimum cost of spanning tree is " << minimum_cost << endl;
    return 0;
}
// Input:
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 1 4 5
// 2 4 7