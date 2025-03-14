#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v); // Add v to u's list
    adjList[v].push_back(u); // Add u to v's list (for undirected graph)
}

void printGraph(const vector<vector<int>> &adjList)
{
    for (int i = 0; i < adjList.size(); ++i)
    {
        cout << "Node " << adjList[i][0] << ": ";
        for (int neighbor : adjList[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numNodes = 5; // Example: Graph with 5 nodes (0 to 4)
    vector<vector<int>> adjList(numNodes);

    // Add edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    // Print the adjacency list
    printGraph(adjList);

    return 0;
}
