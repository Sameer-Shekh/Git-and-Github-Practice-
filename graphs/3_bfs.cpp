// BFS BREADTH FIRST SEARCH
// ---------------------------------------------------------------------------------------------------------
// 🚀 What BFS Does
//     BFS explores a graph level by level — it starts from a given node(the “source”) and
//     visits all its immediate neighbors first,
//     then the neighbors’ neighbors, and so on.It’s like ripples spreading from a stone dropped in a pond.
// ---------------------------------------------------------------------------------------------------------
// 🧠 Core Concept
//  BFS uses a queue data structure — First In, First Out (FIFO).
//  Algorithm (conceptually)
//  Start from the source vertex s.
//  Mark s as visited and push it into the queue.
//  While the queue is not empty:
//  Pop a vertex v from the queue.
//  Visit all its unvisited neighbors and push them into the queue.

// GRAPH

// 0 — 1 — 2
// |   |
// 3 — 4

// ADJACENCY LIST REPRESENTATION

// 0 -> 1, 3
// 1 -> 0, 2, 4
// 2 -> 1
// 3 -> 0, 4
// 4 -> 1, 3

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfsTraversal(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Graph edges
    adj[0] = {1, 3};
    adj[1] = {0, 2, 4};
    adj[2] = {1};
    adj[3] = {0, 4};
    adj[4] = {1, 3};

    cout << "BFS Traversal: ";
    bfsTraversal(0, adj, V);
    return 0;
}
