#include <iostream>
using namespace std;

int main()
{

    // ARRAY IS A CONSTANT POINTER
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "ARRAY IS A CONSTANT POINTER WE CANNOT HOLD ANY OTHER ADDRESS IN THE POINTER" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

    int arr[] = {10, 20, 30};

    cout << "Value of arr: " << arr << endl;               // Output: Address of the first element of the array
    cout << "Address of arr: " << &arr << endl;            // Output: Address of the array (same as above)
    cout << "Value at arr[0]: " << arr[0] << endl;         // Output: 10
    cout << "Value at *arr: " << *arr << endl;             // Output: 10 (dereferencing the pointer to the first element)
    cout << "Value at *(arr + 1): " << *(arr + 1) << endl; // Output: 20 (accessing the second element using pointer arithmetic)
    cout << "Value at arr[1]: " << arr[1] << endl;         // Output: 20
    cout << "Value at *(arr + 2): " << *(arr + 2) << endl; // Output: 30 (accessing the third element using pointer arithmetic)
    cout << "Value at arr[2]: " << arr[2] << endl;         // Output: 30
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "POINTER ARITHMETIC" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    int *p = arr;                                            // Pointer p points to the first element of the array
    cout << "Value of p (Address of arr[0]): " << p << endl; // Output: Address of arr[0]
    cout << "Value at *p: " << *p << endl;                   // Output
    cout << "Value at *(p + 1): " << *(p + 1) << endl;       // Output: 20
    cout << "Value at *(p + 2): " << *(p + 2) << endl;       // Output: 30
    cout << "Value at p[1]: " << p[1] << endl;               // Output: 20
    cout << "Value at p[2]: " << p[2] << endl;               // Output: 30
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    int a = 50;
    int *ptr1 = &a;
    cout << "Initial address stored in ptr: " << ptr1 << endl; // Address of a
    cout << "Value at new address stored in ptr (undefined behavior): " << *ptr1 << endl;
    ptr1++;                                                                               // Incrementing the pointer (moves to the next integer address)
    cout << "Address stored in ptr after incrementing: " << ptr1 << endl;                 // Address of a + 4 (assuming int is 4 bytes)
    cout << "Value at new address stored in ptr (undefined behavior): " << *ptr1 << endl; // Undefined behavior.
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "ADDING AND SUBTRACTING INTEGER TO POINTER ALSO COMPARE POINTERS" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    int arr2[] = {100, 200, 300, 400, 500};
    int *ptr2 = arr2;                                                       // Pointer to the first element of arr2
    cout << "Initial address stored in ptr2: " << ptr2 << endl;             // Address of arr2[0]
    cout << "Value at *ptr2: " << *ptr2 << endl;                            // Output: 100
    ptr2 += 2;                                                              // Move the pointer two integers ahead
    cout << "Address stored in ptr2 after adding 2: " << ptr2 << endl;      // Address of arr2[2]
    cout << "Value at *ptr2 after adding 2: " << *ptr2 << endl;             // Output: 300
    ptr2 -= 1;                                                              // Move the pointer one integer back
    cout << "Address stored in ptr2 after subtracting 1: " << ptr2 << endl; // Address of arr2[1]
    cout << "Value at *ptr2 after subtracting 1: " << *ptr2 << endl;        // Output: 200
    cout << "Comparing two pointers ptr2 and arr2: " << (ptr2 > arr2 ? "ptr2 is greater than arr2" : "ptr2 is not greater than arr2") << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    return 0;
}