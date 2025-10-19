#include <iostream>
#include <vector>
using namespace std;

// MERGE TWO SORTED ARRAYS IN PLACE HERE WE TRAVERSE FROM THE END OF BOTH THE ARRAYS AND PLACE THE LARGER ELEMENT AT THE END OF FIRST ARRAY
void merge(vector<int> &A, int m, vector<int> &B, int n) // SC O(1) TC O(M+N)
{
    int idx = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (A[i] >= B[j])
        {
            A[idx--] = A[i--];
        }
        else
        {
            A[idx--] = B[j--];
        }
    }

    while (j >= 0)
    {
        A[idx] = B[j];
        idx--;
        j--;
    }


    for (int x : A) {
        cout << x << " ";
    }

}  

int main()
{

    vector<int> vec1 = {1, 2, 3, 0, 0, 0};
    vector<int> vec2 = {2, 5, 6};

    int m = vec1.size() - vec2.size();
    int n = vec2.size();

    merge(vec1, m, vec2, n);

    return 0;
}