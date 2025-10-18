// Painters Partition Problem
#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &boards, int n, int m, int maxAllowedTime) {
    int paintersRequired = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime + boards[i] <= maxAllowedTime) {
            currentTime += boards[i];
        }
        else {
            paintersRequired++;
            currentTime = boards[i];
        }
    }
    return paintersRequired <= m;
}


int minTimeToPaint(vector<int> &boards,int n,int m){
    int sum = 0,maxValue = INT8_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        maxValue = max(maxValue,boards[i]);
    }

    int start = maxValue;
    int end = sum;
    int ans = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(isPossible(boards,n,m,mid)){
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}


int main() {
    vector<int> boards = {40,30,10,20};
    int n = 4;
    int m = 2;
    cout << "Minimum time to paint all boards: " << minTimeToPaint(boards, n, m) << endl;
    return 0;
}