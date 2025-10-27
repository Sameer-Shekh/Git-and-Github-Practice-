#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------
// BRUTE FORCE APPROACH
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
// BETTER APPROACH (BINARY SEARCH ON EACH ROW)
// --------------------------------------------
bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[i][mid] == target) return true;
            else if (matrix[i][mid] < target) start = mid + 1;
            else end = mid - 1;
        }
    }
    return false;
}

// --------------------------------------------
// OPTIMIZED APPROACH (STAIRCASE SEARCH)
// --------------------------------------------
bool searchMatrixOptimized(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;

    while (row < m && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--;   // move left
        else row++;                                  // move down
    }
    return false;
}

// --------------------------------------------
// DRIVER FUNCTION
// --------------------------------------------
int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 16;

    cout << "Searching for: " << target << endl << endl;

    cout << "[Brute Force] Result: "
         << (searchMatrixBrute(matrix, target) ? "Found" : "Not Found") << endl;

    cout << "[Better - Binary Search Row-wise] Result: "
         << (searchMatrixBetter(matrix, target) ? "Found" : "Not Found") << endl;

    cout << "[Optimized - Staircase Search] Result: "
         << (searchMatrixOptimized(matrix, target) ? "Found" : "Not Found") << endl;

    return 0;
}
