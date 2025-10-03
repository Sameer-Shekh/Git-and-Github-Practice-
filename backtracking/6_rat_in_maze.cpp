#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans, vector<vector<bool>> &visited)
{

    // BASE CASES
    int n = maze.size();

    // 1.
    if (row < 0 || col < 0 || row >= n || col >= n || visited[row][col] == true)
    {
        return;
    }
    // 2.
    if (maze[row][col] == 0)
    {
        return;
    }
    // 3.
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // BEFORE HAVING THE CHOICES

    visited[row][col] = true;

    // UPWORD CALL
    helper(maze, row - 1, col, path + "U", ans, visited);

    // DOWNWORD CALL
    helper(maze, row + 1, col, path + "D", ans, visited);

    // RIGHT CALL
    helper(maze, row, col + 1, path + "R", ans, visited);

    // LEFT CALL
    helper(maze, row, col - 1, path + "L", ans, visited);

    visited[row][col] = false;
}

vector<string> findPath(vector<vector<int>> &maze)
{
    vector<string> ans;
    string path = "";
    int n = maze.size();

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    helper(maze, 0, 0, path, ans, visited);
    return ans;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 1},
                                {1, 1, 1, 1},
                                {1, 0, 0, 1},
                                {1, 1, 1, 1}};

    vector<string> ans = findPath(maze);

    for (string path : ans)
    {
        cout << path << endl;
    }
    return 0;
}
