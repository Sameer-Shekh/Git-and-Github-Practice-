#include <iostream>
using namespace std;

bool linearSearch(int mat[][3], int rows, int cols,int target)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(mat[i][j] == target) return true;
        }
    }
    return false;
}

int main()
{

    // int mat[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int mat[3][3];
    int rows = 3;
    int cols = 3;
    int target = 4;

    // INPUT
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }

    // OUTPUT
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    if(linearSearch(mat, rows, cols,target)) {
        cout << "TARGET ELEMENT "<< target << " IS PRESENT IN 2D ARRAY"; 
    }
    else {
        cout << "TARGET ELEMENT "<< target << " NOT FOUND IN 2D MATRIX";
    }

    return 0;
}