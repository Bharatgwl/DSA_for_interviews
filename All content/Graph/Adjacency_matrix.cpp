#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices

// Function to initialize the adjacency matrix
void initializeMatrix(int matrix[MAX][MAX], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int matrix[MAX][MAX], int i, int j, int isUndirected)
{
    matrix[i][j] = 1;
    if (isUndirected)
    {
        matrix[j][i] = 1; // Add reverse edge for undirected graphs
    }
}

// Function to remove an edge from the graph
void removeEdge(int matrix[MAX][MAX], int i, int j, int isUndirected)
{
    matrix[i][j] = 0;
    if (isUndirected)
    {
        matrix[j][i] = 0; // Remove reverse edge for undirected graphs
    }
}
// Function to print the adjacency matrix
void printMatrix(int matrix[MAX][MAX], int vertices)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void directneighbours(int matrix[MAX][MAX], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (matrix[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main()
{
    int vertices = 5; // Number of vertices
    int adjMatrix[MAX][MAX];

    // Initialize the matrix
    initializeMatrix(adjMatrix, vertices);

    // Adding edges
    addEdge(adjMatrix, 0, 1, 1); // Undirected edge between 0 and 1
    addEdge(adjMatrix, 0, 4, 1); // Undirected edge between 0 and 4
    addEdge(adjMatrix, 1, 2, 1); // Undirected edge between 1 and 2
    addEdge(adjMatrix, 1, 3, 1); // Undirected edge between 1 and 3
    addEdge(adjMatrix, 1, 4, 1); // Undirected edge between 1 and 4
    addEdge(adjMatrix, 2, 3, 1); // Undirected edge between 2 and 3
    addEdge(adjMatrix, 3, 4, 1); // Undirected edge between 3 and 4

    // Print the adjacency matrix
    printMatrix(adjMatrix, vertices);
    directneighbours(adjMatrix,5);

    return 0;
}
