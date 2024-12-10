#include <iostream>
#include <climits>
using namespace std;

#define V 100 // Maximum number of vertices (changeable as per need)

int parent[V];

// Find set of vertex i
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Perform union of i and j
void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Find MST using Kruskal's algorithm
void kruskalMST(int cost[][V], int n) {
    int mincost = 0;

    // Initialize sets of disjoint sets
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < n - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] != 0 && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        printf("Edge %d: (%d, %d) cost: %d\n", edge_count++, a, b, min);
        mincost += min;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    int cost[V][V];

    cout << "Enter the cost adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX; // Convert 0 to INT_MAX internally
            }
        }
    }

    kruskalMST(cost, n);

    return 0;
}

