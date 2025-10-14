// ⚙️ The Core Idea

// DFS visits a node, then recursively (or using a stack) visits one of its unvisited neighbors, 
// and keeps going until it can’t go deeper. Then it backtracks and explores other unvisited paths.

// Conceptually:

// Pick a starting node.
// Visit it, mark it as visited.
// Go to the first unvisited neighbor and repeat.
// When you hit a dead end, backtrack.

// 🧠 DFS Example

// Let’s reuse the same graph:

// 0 — 1 — 2
// |   |
// 3 — 4


// Adjacency list:

// 0 -> 1, 3
// 1 -> 0, 2, 4
// 2 -> 1
// 3 -> 0, 4
// 4 -> 1, 3


// Start DFS at node 0:

// Traversal order:
// 0 → 1 → 2 → backtrack → 4 → backtrack → 3

// So final order: 0, 1, 2, 4, 3

// --------------------------------------------------------------------------------------------------------
// DFS USING RECURSION
// ---------------------------------------------------------------------------------------------------------
// #include <iostream>
// #include <vector>
// using namespace std;

// void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
//     visited[node] = true;
//     cout << node << " ";

//     for (int neighbor : adj[node]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, adj, visited);
//         }
//     }
// }

// int main() {
//     int V = 5;
//     vector<vector<int>> adj(V);

//     // Graph setup
//     adj[0] = {1, 3};
//     adj[1] = {0, 2, 4};
//     adj[2] = {1};
//     adj[3] = {0, 4};
//     adj[4] = {1, 3};

//     vector<bool> visited(V, false);

//     cout << "DFS Traversal: ";
//     dfs(0, adj, visited);
//     cout << endl;
// }

// --------------------------------------------------------------------------------------------------------
// 💼 Iterative DFS (using a stack)
// ---------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsIterative(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }

        // Push neighbors in reverse order to maintain correct order
        for (int i = adj[node].size() - 1; i >= 0; --i) {
            int neighbor = adj[node][i];
            if (!visited[neighbor])
                st.push(neighbor);
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 3};
    adj[1] = {0, 2, 4};
    adj[2] = {1};
    adj[3] = {0, 4};
    adj[4] = {1, 3};

    cout << "Iterative DFS: ";
    dfsIterative(0, adj, V);
    cout << endl;
}
