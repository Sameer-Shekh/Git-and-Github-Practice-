// BOOK ALLOCATION PROBLEM USING BINARY SEARCH
#include <iostream>
#include <vector>
using namespace std;


bool isValid(vector<int> &arr,int n ,int m,int maxAllowedPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) {
            return false; // A single book has more pages than allowed
        }

        if (currentSum + arr[i] > maxAllowedPages) {
            studentsRequired++;
            currentSum = arr[i];
        } else {
            currentSum += arr[i];
        }
    }

    return studentsRequired > m ? false : true;
}

int allocateBooks(vector<int> &pages, int n, int m) {

    if(m > n) {
        return -1; // Not enough books for each student
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pages[i];
    }
    int start = 0, end = sum; // Maximum possible pages range
    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(isValid(pages,n,m,mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> pages = {2,1,3,4};
    int n = pages.size();
    int m = 2; // Number of students

    int minPages = allocateBooks(pages, n, m);
    cout << "Minimum number of pages allocated to a student: " << minPages << endl;

    return 0;
}


// arr = [15,17,20] // DRY RUN THIS HOMEWORK