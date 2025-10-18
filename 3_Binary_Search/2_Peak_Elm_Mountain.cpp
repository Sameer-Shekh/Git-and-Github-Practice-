#include<iostream>
#include<vector>
using namespace std;

// USING LINEAR SEARCH
void findPeakElementInMountainLinearSearch(vector<int> &arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        if(arr[i] > arr[i+1] && arr[i] > arr[i-1]) {
            cout<<"PEAK ELEMENT IS PRESENT AT INDEX "<<i<<endl;
        }
    }
}

// USING BINARY SEARCH
void findPeakBinarySearch(vector<int> &arr,int start,int end) {
    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
            cout << "PEAK ELEMENT IS PRESENT AT INDEX USING BINARY SEARCH(O(LOG(N))): "<<mid<<endl;
            return ;
        }
        else if(arr[mid] > arr[mid-1]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << "ERROR HAPPENED"<<endl;
}

int main() {

    vector<int> arr = {1, 3, 5, 7, 9, 5, 4, 1};
    findPeakElementInMountainLinearSearch(arr);
    // int end = arr.size() - 1;
    // findPeakBinarySearch(arr,0,end);
    // OPTIMIZATION AS START = 0 AND END = ARR.SIZE() -1 CAN NEVER BE A PEAK ELEMENT
    int end = arr.size() - 2;
    int start= 1;
    findPeakBinarySearch(arr,start,end);

    return 0;
}