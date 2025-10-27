#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ---------- 1. BRUTE FORCE ----------
void rotateBrute(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }

    matrix = rotated;
}

// ---------- 2. BETTER (Transpose + Reverse) ----------
void rotateBetter(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// ---------- 3. OPTIMAL (Layer-by-Layer Rotation) ----------
void rotateOptimal(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;

        for (int i = first; i < last; i++) {
            int offset = i - first;

            int top = matrix[first][i]; // save top

            // left -> top
            matrix[first][i] = matrix[last - offset][first];

            // bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset];

            // right -> bottom
            matrix[last][last - offset] = matrix[i][last];

            // top -> right
            matrix[i][last] = top;
        }
    }
}

// ---------- Utility Function ----------
void printMatrix(const vector<vector<int>> &matrix) {
    for (auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << endl;
}

// ---------- DRIVER CODE ----------
int main() {
    vector<vector<int>> original = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(original);

    // Brute Force
    auto brute = original;
    rotateBrute(brute);
    cout << "After Brute Force Rotation:\n";
    printMatrix(brute);

    // Better
    auto better = original;
    rotateBetter(better);
    cout << "After Better (Transpose + Reverse) Rotation:\n";
    printMatrix(better);

    // Optimal
    auto optimal = original;
    rotateOptimal(optimal);
    cout << "After Optimal (Layer Rotation):\n";
    printMatrix(optimal);

    return 0;
}
