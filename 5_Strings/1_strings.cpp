#include<iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3};
    cout << arr <<endl;

    // char ch[] = {'a','b','c'};   // length = 3
    char ch[] = {'a','b','c','\0'}; // length = 3
    cout<< ch <<endl;

    char str[] = "HELLO WORLD";     // STRING LITERALS
    cout<< str<<endl;

    cout<< str[0] <<endl;
    cout<< str[1] <<endl;
    cout<< str[2] <<endl;

    // TAKING INPUT IN CHAR ARRAY IF SPACE COMES IT IGNORE THE UPCOMING CHAR
    char ar[12];
    // cin >> ar;
    // cout<< "OUTPUT CHAR ARRAY : " <<ar<<endl;

    // TAKING INPUT IN CHAR ARRAY USING FUNCTION 
    cin.getline(ar,12,'$');
    cout<< "OUTPUT CHAR ARRAY " <<ar<<endl;

    // TRAVERSING CHAR ARRAY
    for(char val:ar) {
        cout <<val<< " ";
    }

    // CALCULATE LENGTH OF CHAR ARRAY
    int len = 0;
    for(int i=0;i<ar[i] != '\0';i++) {
        len++;
    }

    cout<<"\nLENGHT OF CHAR ARRAY " << len <<endl;

    return 0;
}