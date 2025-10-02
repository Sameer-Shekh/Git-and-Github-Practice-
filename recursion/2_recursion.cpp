#include <iostream>
using namespace std;

int fatorialOfNumber(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * fatorialOfNumber(n - 1);
}
int main()
{
    cout << "ENTER A NUMBER ";
    int n;
    cin >> n;
    int a = fatorialOfNumber(n);
    cout << "FACTORIAL OF NUMBER " << n << " IS : " << a;
    return 0;
}