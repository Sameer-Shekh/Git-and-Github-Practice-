#include<iostream>
using namespace std;

double powerOfXbyN(double x,int n) {

    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;

    if(x == -1 && n%2 == 0) return 1.0;
    if(x == -1 && n%2 != 0) return -1.0;

    long binForm = n;

    if(n < 0) {
        x = 1/x;
        binForm = -binForm;
    }

    double ans = 1;

    while(binForm > 0) {
        ans *= x;
    }
    x *= x;
    binForm = binForm / 2;

    return ans;
}

int main() {

    double x=5;
    int n=3;

    double ans;
    ans = powerOfXbyN(x,n);
    cout<< "THE POWER OF"<<x<<"TO THE "<<n<<"IS: "<<ans<<endl;   

    return 0;
}