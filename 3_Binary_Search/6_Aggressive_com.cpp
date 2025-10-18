// AGGRESSIVE COWS PROBLEM
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPossible(vector<int> &stalls, int N, int C, int minDistance) {
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < N; i++) {
        if (stalls[i] - lastPosition >= minDistance) {
            cowsPlaced++;
            lastPosition = stalls[i];
        }
        if (cowsPlaced == C) {
            return true;
        }
    }
    return false;
}

int getDistance(vector<int> &stalls,int N,int C) {
    sort(stalls.begin(),stalls.end());
    int minValue = stalls[0];
    int maxValue = stalls[N-1];
    int start = 1,end = maxValue - minValue;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(isPossible(stalls,N,C,mid)){
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int N = 5,C = 3;
    vector<int> stalls = {1,2,8,4,9};
    cout << "Maximum minimum distance: " << getDistance(stalls,N,C) << endl;
    return 0;
}