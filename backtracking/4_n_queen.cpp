#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{

    // HORIZONTALLY SAFE
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    // VERTICALLY SAFE
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // LEFT DIAGNAL
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // RIGHT DIAGNAL
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{

    if (row == n)
    {
        ans.push_back({board});
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    return ans;
}

int main()
{
    vector<vector<string>> actualAns = solveNQueens(5);

    // Print all solutions in grid format
    if (!actualAns.empty())
    {
        int count = 1;
        for (const auto &solution : actualAns)
        {
            cout << "Solution " << count++ << ":\n";
            int n = solution.size();
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    cout << solution[i][j] << " ";
                }
                cout << endl;
            }
            cout << string(n * 2, '-') << endl; // separator line
        }
    }
    else
    {
        cout << "No solution found." << endl;
    }
    return 0;
}