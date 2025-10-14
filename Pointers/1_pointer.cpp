#include <iostream>
using namespace std;

void passByValue(int x, int y)
{
    y = 20;
    cout << "Inside passByValue - x: " << x << ", y: " << y << endl;
}

void passByReference(int *p)
{
    *p = 20;
}

void passByReferenceAlias(int &ref)
{
    ref = 20;
}

int main()
{
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

    // POINTERS TO VARIABLES
    cout << "\nPOINTERS TO VARIABLES" << endl;
    int a = 10;
    cout << "Value of a: " << a << endl;    // Output: 10
    cout << "Address of a: " << &a << endl; // Output: Address of a

    int *p = &a;                                                                                      // Pointer p holds the address of a
    cout << "Value of p (Address of a): " << p << endl;                                               // Output: Address of a
    cout << "Address of pointer p: " << &p << endl;                                                   // Output: Address of pointer p
    cout << "Value at address stored in p: " << *p << " Using the dereferencing pointer(*p)" << endl; // Output: 10 dereferencing pointer

    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

    // POINTERS TO POINTERS
    cout << "\nPOINTERS TO POINTERS" << endl;
    int **q = &p;                                                                                          // Pointer to pointer q holds the address of pointer p
    cout << "Value of q (Address of p): " << q << endl;                                                    // Output: Address of p
    cout << "Address of pointer q: " << &q << endl;                                                        // Output: Address of pointer q
    cout << "Value at address stored in q (Value of p): " << *q << endl;                                   // Output: Address of a
    cout << "Value at address stored in the pointer to which q is pointing (Value of a): " << **q << endl; // Output: 10

    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

    // PASS BY VALUE
    cout << "\nPass By Value" << endl;
    int x = 5;
    int y = x; // Pass by value, y gets a copy of x
    y = 10;    // Changing y does not affect x
    cout << "Before passByValue - " << "x: " << x << ", y: " << y << endl;

    passByValue(x, y);
    cout << "After passByValue - x: " << x << ", y: " << y << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

    // PASS BY REFERENCE USING POINTERS
    cout << "\nPass By Reference using Pointers" << endl;
    int m = 5;
    cout << "Before passByReference - m: " << m << endl;
    passByReference(&m);
    cout << "After passByReference - m: " << m << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

    // PASS BY REFERENCE USING ALIASES
    cout << "\nPass By Reference using alias" << endl;
    int n = 5;
    cout << "Before aliasing - n: " << n << endl;
    passByReferenceAlias(n);
    cout << "After aliasing - n: " << n << endl;

    return 0;
}