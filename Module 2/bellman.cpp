#include <iostream>
#include <limits.h>
using namespace std;

#define V 9 // Number of vertices in the graph

struct Edge {
    int src, dest, weight;
};

// Function to print the solution
void printSolution(int dist[], int n) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Bellman-Ford algorithm
void bellmanFord(Edge edges[], int edgeCount, int src, int n) {
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0; // Distance from source to itself is 0

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    printSolution(dist, n);
}

int main() {
    // Graph represented as an array of edges
   Edge edges[] = {
    {0, 1, -1},
    {0, 2, 4},
    {1, 2, 3},
    {1, 3, 2},
    {1, 4, 2},
    {3, 2, 5},
    {3, 1, 1},
    {4, 3, -3},
    {4, 0, 1},
    {2, 5, 1},  
    {5, 6, 2}, 
    {6, 7, 1},  
    {7, 8, 3},  
    {5, 8, 5}   
};

    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    bellmanFord(edges, edgeCount, 0, V);

    return 0;
}


