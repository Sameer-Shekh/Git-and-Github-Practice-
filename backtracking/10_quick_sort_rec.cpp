#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int start,int end) {
    int pivot = arr[end];
    int i = start - 1; // smaller element index than pivot
    int j = start;
    while(j<end) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

void quickSort(vector<int> &arr,int start, int end) {
    if(start<end) {
        int pivotIndex = partition(arr,start,end);
        // LEFT PARTITION
        quickSort(arr,start,pivotIndex-1);
        // RIGHT PARTITION
        quickSort(arr,pivotIndex+1,end);
    }
}

int main() {
    vector<int> arr = {12,32,55,1,66,21};
    int n = arr.size()-1;
    quickSort(arr,0,n);
    for(int val : arr) {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}