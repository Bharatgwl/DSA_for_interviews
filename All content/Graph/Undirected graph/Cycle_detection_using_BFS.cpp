//Question Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <iostream>
#include <unordered_map>
#include <set> //to store in a sorted order
#include <vector>
#include <queue>
using namespace std;

/**
 * @brief Detects if a graph contains a cycle using BFS
 *
 * This program takes a graph as input and detects if it contains a cycle using BFS.
 * It works by traversing the graph using BFS and keeping track of the parent of each node.
 * If it encounters a node that is not the parent of the current node, it means that there is a cycle in the graph.
 * If it finishes traversing the graph without finding a cycle, it means that the graph does not contain a cycle.
 * The result is printed out at the end of the program.
 *
 * @param n The number of nodes in the graph.
 * @param m The number of edges in the graph.
 * @return True if the graph contains a cycle, false otherwise.
 */
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

/**
 * @brief Traverses the graph using BFS and checks for cycles.
 *
 * This function takes a graph and a starting node as input, and traverses the graph using BFS.
 * It keeps track of the parent of each node and checks if it encounters a node that is not the parent of the current node.
 * If it does, it means that there is a cycle in the graph, and it returns true.
 * If it finishes traversing the graph without finding a cycle, it means that the graph does not contain a cycle, and it returns false.
 *
 * @param node The starting node of the traversal.
 * @param adj The adjacency list of the graph, which is a map of nodes to sets of nodes.
 * @param adj The adjacency list of the graph.
 * @param visited A map of nodes to booleans, where the value of each node is true if it has been visited and false otherwise.
 * @return True if the graph contains a cycle, false otherwise.
 */
bool traverse(int node, unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited)
{
    // Create a queue to store the nodes to visit
    queue<int> q;

    // Push the starting node onto the queue
    q.push(node);

    // Mark the starting node as visited
    visited[node] = true;

    // Create a map to store the parent of each node
    unordered_map<int, int> parent;

    // Set the parent of the starting node to -1
    parent[node] = -1;

    // Loop until the queue is empty
    while (!q.empty())
    {
        // Get the front node from the queue
        int frontnode = q.front();

        // Pop the front node from the queue
        q.pop();

        // Loop through all the neighbors of the front node
        for (auto neighbour : adj[frontnode])
        {
            // If the neighbor has not been visited yet
            if (!visited[neighbour])
            {
                // Push the neighbor onto the queue
                q.push(neighbour);

                // Mark the neighbor as visited
                visited[neighbour] = true;

                // Set the parent of the neighbor to the front node
                parent[neighbour] = frontnode;
            }
            // If the neighbor is not the parent of the front node
            else if (neighbour != parent[frontnode])
            {
                // Return true, because a cycle has been found
                return true;
            }
        }
    }

    // If the loop finishes without finding a cycle, return false
    return false;
}
/**
 * @brief Checks if a graph contains a cycle using BFS.
 *
 * This function takes a graph as input and checks if it contains a cycle using BFS.
 * It works by traversing the graph using BFS and checking for cycles.
 * If it encounters a node that is not the parent of the current node, it means that there is a cycle in the graph.
 * If it finishes traversing the graph without finding a cycle, it means that the graph does not contain a cycle.
 * The result is printed out at the end of the program.
 *
 * @param n The number of nodes in the graph.
 * @param m The number of edges in the graph.
 * @param adj The adjacency list of the graph.
 * @return True if the graph contains a cycle, false otherwise.
 */
bool isCyclic(int n, unordered_map<int, set<int>> &adj)
{
    unordered_map<int, bool> visited;
    bool ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = traverse(i, adj, visited);
        }
    }
    return ans;
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
        g1.addEdge(x, y, 0);
    }

    vector<int> ans;

    if (isCyclic(n, g1.adj))
    {
        cout << "graph contains cycle" << endl;
    }
    else
    {
        cout << "graph does not contain cycle" << endl;
    }
    return 0;
}

/**
 * Test Case 1:
 * 4
 * 4
 * 0 1
 * 1 2
 * 2 3
 * 3 0
 * Output: graph contains cycle
 *
 * Test Case 2:
 * 3
 * 3
 * 0 1
 * 1 2
 * 2 0
 * Output: graph contains cycle
 *
 * Test Case 3:
 * 6
 * 8
 * 0 1
 * 1 2
 * 2 4
 * 4 5
 * 5 0
 * 3 4
 * 3 2
 * Output: graph contains cycle
 *
 * Test Case 4:
 * 5
 * 4
 * 0 1
 * 1 2
 * 2 3
 * 3 4
 * Output: graph does not contain cycle
 *
 */
