#include<iostream>
#include<vector>
using namespace std;
bool searchInRow(vector<vector<int>> & matrix,int target ,int midRow) {
    int m = matrix.size(),n= matrix[0].size();

    int start = 0,end = n-1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(target == matrix[midRow][mid]) {
            return true;
        }
        else if(target > matrix[midRow][mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return false;
}


bool searchMatrix(vector<vector<int>> &matrix,int target) {
    int m = matrix.size(),n = matrix[0].size();
    int startRow = 0,endRow = m-1;

    while(startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2;

        if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
            return searchInRow(matrix,target,midRow);
        }
        else if(target >= matrix[midRow][n-1]) {
            startRow = midRow + 1;
        }
        else {
            endRow = midRow -1;
        }
    }
    return false;
}

int main() {

    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}}; 
    int target = 12;
    if(searchMatrix(mat,target)) {
        cout << "ELEMENT PRESENT IN MATRIX" << endl;
    }
    else {
        cout << "NOT PRESENT" <<endl;
    }

    return 0;
}