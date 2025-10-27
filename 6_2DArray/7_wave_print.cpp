#include <iostream>
#include <vector>
using namespace std;

void printWavePattern(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int col = 0; col < cols; col++) {
        // Even column -> top to bottom
        if (col % 2 == 0) {
            for (int row = 0; row < rows; row++) {
                cout << matrix[row][col] << " ";
            }
        }
        // Odd column -> bottom to top
        else {
            for (int row = rows - 1; row >= 0; row--) {
                cout << matrix[row][col] << " ";
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Wave Pattern: ";
    printWavePattern(matrix);
    cout << endl;

    return 0;
}
