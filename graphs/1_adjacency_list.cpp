#include <iostream>
#include <map>
#include <vector>
using namespace std;

//----------------------------------------
// Graph implemented using map<int, vector<int>>
//----------------------------------------
class MapGraph {
private:
    map<int, vector<int>> adjList;

public:
    void addEdge(int u, int v, bool directed) {
        adjList[u].push_back(v);
        if (!directed)
            adjList[v].push_back(u);
    }

    void printList() {
        cout << "\nGRAPH USING MAP<int, vector<int>>:\n";
        for (auto &node : adjList) {
            cout << node.first << " -> ";
            for (auto &nbr : node.second) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

//----------------------------------------
// Graph implemented using vector<vector<int>>
//----------------------------------------
class VectorGraph {
private:
    vector<vector<int>> adjList;
    int V;

public:
    VectorGraph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, bool directed) {
        adjList[u].push_back(v);
        if (!directed)
            adjList[v].push_back(u);
    }

    void printList() {
        cout << "\nGRAPH USING vector<vector<int>>:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto &nbr : adjList[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

//----------------------------------------
// Main driver
//----------------------------------------
int main() {
    int n, m;
    cout << "ENTER NUMBER OF NODES: ";
    cin >> n;

    cout << "ENTER NUMBER OF EDGES: ";
    cin >> m;

    MapGraph gMap;
    VectorGraph gVec(n);

    cout << "ENTER " << m << " EDGES (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gMap.addEdge(u, v, false);
        gVec.addEdge(u, v, false);
    }

    gMap.printList();
    gVec.printList();

    return 0;
}
