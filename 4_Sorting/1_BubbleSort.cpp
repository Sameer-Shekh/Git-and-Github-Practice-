#include <iostream>
#include <algorithm>
using namespace std;

// SWAP ADJACENT ELEMENT BY COMPARING THEM
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if(!isSwap) return;
    }
}

// ASSUME ARRAY AS UNSORTED ARRAY AND MAKE FIRST ELEM AS SMALLEST ELEM AND FIND OUT THE SMALLEST INDEX FROM REST AND SWAP IT WITH FIRST ELEM
void SelectionSort(int arr[],int n) 
{
    for(int i=0;i<n-1;i++) {
        int smallestIdx = i; // unsorted part starting
        for(int j = i + 1; j<n;j++) {
            if(arr[j] < arr[smallestIdx]) {
                smallestIdx = j;
            }
        }
        swap(arr[i],arr[smallestIdx]);
    }
}

void InsertionSort(int arr[],int n) {
    for(int i = 1; i<n;i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
} 


void printArray(int arr[],int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{

    int arr[] = {4,1,5,7,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, n);
    printArray(arr,n);
    cout<<endl;
    SelectionSort(arr,n);
    printArray(arr,n);
    cout<<endl;
    InsertionSort(arr,n);
    printArray(arr,n);
    return 0;
}