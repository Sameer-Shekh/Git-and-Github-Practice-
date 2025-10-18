#include<iostream>
#include<vector>
using namespace std;


// BRUTE FORCE APPROACH - O(N^2) TIME COMPLEXITY
int containerWithMostWaterBruteForce(vector<int> &height) {
    int maxArea = 0;
    int n = height.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int heightLeft = height[i];
            int heightRight = height[j];
            int width = j - i;
            int currentArea = min(heightLeft, heightRight) * width;
            maxArea = max(maxArea, currentArea);
        }
    }

    cout << "Maximum Area of Water Container (Brute Force): " << maxArea << endl;
    return maxArea;
}
// OPTIMIZED APPROACH - O(N) TIME COMPLEXITY
int containerWithMostWater(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
        int heightLeft = height[left];
        int heightRight = height[right];
        int width = right - left;
        int currentArea = min(heightLeft, heightRight) * width;
        maxArea = max(maxArea, currentArea);

        if (heightLeft < heightRight) {
            left++;
        } else {
            right--;
        }
    }

    cout << "Maximum Area of Water Container: " << maxArea << endl;
    return maxArea;
}

int main() {

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    containerWithMostWaterBruteForce(height);
    containerWithMostWater(height);

    return 0;
}