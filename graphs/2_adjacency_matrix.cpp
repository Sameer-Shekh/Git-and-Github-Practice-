#include <iostream>
#include <vector>
using namespace std;

//-------------------------------------------------------------
// Class: Graph
// Purpose: Represent a graph using an adjacency matrix.
//-------------------------------------------------------------
class Graph {
public:
    int V;  // number of vertices (nodes)
    vector<vector<int>> adjMatrix;  // 2D matrix representing edges

    //---------------------------------------------------------
    // Constructor: Initialize graph with given number of vertices
    // Each cell adjMatrix[i][j] = 0 initially (no edge)
    //---------------------------------------------------------
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));  // create VxV matrix filled with 0s
    }

    //---------------------------------------------------------
    // Function: addEdge
    // Purpose: Add an edge between node u and v.
    // If 'directed' = false, add both ways (undirected graph)
    //---------------------------------------------------------
    void addEdge(int u, int v, bool directed) {
        adjMatrix[u][v] = 1;  // mark edge from u → v
        if (!directed)
            adjMatrix[v][u] = 1;  // also mark edge from v → u (for undirected graph)
    }

    //---------------------------------------------------------
    // Function: printMatrix
    // Purpose: Display adjacency matrix with headers for clarity
    //---------------------------------------------------------
    void printMatrix() {
        cout << "\nADJACENCY MATRIX REPRESENTATION\n\n";

        // Print column headers (node numbers)
        cout << "    ";
        for (int i = 0; i < V; i++) {
            cout << i << " ";
        }
        cout << "\n   ";
        for (int i = 0; i < V; i++) cout << "--";
        cout << "\n";

        // Print rows with row headers
        for (int i = 0; i < V; i++) {
            cout << i << " | ";  // row header
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

//-------------------------------------------------------------
// Main Function
// Purpose: Build and display the graph
//-------------------------------------------------------------
int main() {
    int n, m;
    cout << "ENTER THE NUMBER OF NODES: ";
    cin >> n;

    cout << "ENTER THE NUMBER OF EDGES: ";
    cin >> m;

    // Create a graph object with n vertices
    Graph g(n);

    cout << "ENTER " << m << " EDGES (u v):\n";
    // Take m pairs of edges as input
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false);  // 'false' → undirected graph
    }

    // Print the adjacency matrix
    g.printMatrix();

    return 0;
}
