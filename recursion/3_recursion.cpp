#include <iostream>
using namespace std;

int SumOfNumber(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + SumOfNumber(n - 1);
}
int main()
{
    cout << "ENTER A NUMBER ";
    int n;
    cin >> n;
    int a = SumOfNumber(n);
    cout << "FACTORIAL OF NUMBER " << n << " IS : " << a;
    return 0;
}