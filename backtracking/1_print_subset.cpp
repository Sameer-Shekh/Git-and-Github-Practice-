#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int> &arr, vector<int> &ans, int i)
{
    if (i == arr.size())
    {
        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // INCLUDE
    ans.push_back(arr[i]);
    printSubset(arr, ans, i + 1);

    // BACKTRACK STEP
    ans.pop_back();

    // EXCLUDE
    printSubset(arr, ans, i + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans; // to store result

    printSubset(arr, ans, 0);
    return 0;
}