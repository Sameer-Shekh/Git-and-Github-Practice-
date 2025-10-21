// MAXIMUM ROW SUM
#include<iostream>
using namespace std;

int getMaxSum(int arr[][3],int row,int col) {
    int maxSum = INT8_MIN;
    for(int i=0;i<row;i++) {
        int maxRowSumI = 0;
        for(int j=0;j<col;j++) {
            maxRowSumI += arr[i][j];
        }
        maxSum = max(maxSum,maxRowSumI);
    }

    return maxSum;
}

int diagnalSum(int arr[3][3],int row,int col,int n) {
    int sum = 0;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if( i == j ) {
                // PRIMARY DIAGNAL
                sum += arr[i][j];
            }
            else if(j = n - i - 1) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

int main() {

    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int row = 3;
    int col = 3;
    int n = 3;

    
    cout << "MAX ROW SUM" << endl;

    cout << getMaxSum(arr,row,col) << endl;

    cout << "DIAGNAL SUM" << endl;

    cout << diagnalSum(arr,row,col,n) << endl;

    return 0;
}