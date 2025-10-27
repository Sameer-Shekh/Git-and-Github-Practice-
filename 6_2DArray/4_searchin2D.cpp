#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------
// 1️⃣ BRUTE FORCE
// --------------------------------------------
bool searchMatrixBrute(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == target) return true;
        }
    }
    return false;
}

// --------------------------------------------
// 2️⃣ BETTER APPROACH (BINARY SEARCH ON EACH ROW)
// --------------------------------------------
bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
            int start = 0, end = n - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] < target) start = mid + 1;
                else end = mid - 1;
            }
        }
    }
    return false;
}

// --------------------------------------------
// 3️⃣ OPTIMIZED APPROACH (FLATTENED MATRIX SEARCH)
// --------------------------------------------
bool searchMatrixOptimized(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m * n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

// --------------------------------------------
// DRIVER FUNCTION
// --------------------------------------------
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 16;

    cout << "Searching for: " << target << endl << endl;

    cout << "[Brute Force] Result: "
         << (searchMatrixBrute(matrix, target) ? "Found" : "Not Found") << endl;

    cout << "[Better - Row Binary Search] Result: "
         << (searchMatrixBetter(matrix, target) ? "Found" : "Not Found") << endl;

    cout << "[Optimized - Flattened Binary Search] Result: "
         << (searchMatrixOptimized(matrix, target) ? "Found" : "Not Found") << endl;

    return 0;
}
