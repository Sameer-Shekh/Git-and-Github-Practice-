#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<int>> &grid,int row,int col,int n, int expVal) {

    // 1. BASE CASE
    if(row<0 || col<0 || row>=n || col>=n || grid[row][col]!=expVal) {
        return false;
    }
    // 2. BASE CASE
    if(expVal == n*n -1) {
        return true;  
    }

    // 8 POSITIONS MOVES
    int ans1 = isValid(grid, row - 2, col + 1, n, expVal + 1);
    int ans2 = isValid(grid, row - 1, col + 2, n, expVal + 1);
    int ans3 = isValid(grid, row + 1, col + 2, n, expVal + 1);
    int ans4 = isValid(grid, row + 2, col + 1, n, expVal + 1);
    int ans5 = isValid(grid, row + 2, col - 1, n, expVal + 1);
    int ans6 = isValid(grid, row + 1, col - 2, n, expVal + 1);
    int ans7 = isValid(grid, row - 1, col - 2, n, expVal + 1);
    int ans8 = isValid(grid, row - 2, col - 1, n, expVal + 1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

int main()
{
    // vector<vector<int>> grid = {{0,3,6},{5,8,1},{2,7,4}};
    vector<vector<int>> grid = {{0, 13, 8, 19, 2},{23, 18, 1, 14, 9},{12, 7, 24, 3, 20},{17, 22, 5, 10, 15},{6, 11, 16, 21, 4}};
    cout<< (isValid(grid, 0, 0, grid.size(), 0) ? "true" : "false") <<endl;
    return 0;
}