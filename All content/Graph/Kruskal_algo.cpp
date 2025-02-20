// Graph Kruskal algorithm
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dest, weight;
};

class Graph
{
public:
    int V, E;
    Edge *edge;
};

Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

class subset
{
public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph *graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    subset *subsets = new subset[V];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "Following are the edges in the MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        cout << result[i].src << " -- " << result[i].dest
             << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;

    delete[] subsets;
}

void updateGraph(int s, int d, int w, int idx, Graph *graph)
{
    graph->edge[idx].src = s;
    graph->edge[idx].dest = d;
    graph->edge[idx].weight = w;
}

// Driver code
int main()
{
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph *graph = createGraph(V, E);

    // // add edge 0-1
    // updateGraph(0, 1, 10, 0, graph);

    // // add edge 0-2
    // updateGraph(0, 2, 6, 1, graph);

    // // add edge 0-3
    // updateGraph(0, 3, 5, 2, graph);

    // // add edge 1-3
    // updateGraph(1, 3, 15, 3, graph);

    // // add edge 2-3
    // updateGraph(2, 3, 4, 4, graph);
    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        updateGraph(u, v, w, i, graph);
    }

    KruskalMST(graph);

    delete[] graph->edge;
    delete graph;

    return 0;
}
// 0 1 10 
// 0 2 6 
// 0 3 5 
// 1 3 15
// 2 3 4