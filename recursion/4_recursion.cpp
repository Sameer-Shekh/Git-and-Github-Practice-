// f(n) = f(n-1) + f(n-2)
// 0 1 1 2 3 5 8 ...

#include<iostream>
using namespace std;

int finonacciNumber(int n) {
    // BASE CASE
    if (n == 0 || n == 1)
    {   
        return n;
    }
    // RECURIVE CALL
    return finonacciNumber(n-1) + finonacciNumber(n-2);

}

int main(){

    cout << finonacciNumber(5) << endl;
    return 0;
}
