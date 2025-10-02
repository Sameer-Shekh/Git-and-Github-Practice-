#include<iostream>
using namespace std;

void printNumber(int n){

    //BASE CASE
    if(n==1){
        cout<<n<<endl;
        return;
    }

    //PRINTING
    cout<<n<<",";

    //RECURSIVE CALL
    printNumber(n-1);
}

int main()
{
    int n;
    cout<<"ENTER NO"<<endl;
    cin>>n;
    printNumber(n);
    return 0;
}