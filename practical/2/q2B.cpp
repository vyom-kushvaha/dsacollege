#include <iostream>
using namespace std;

// Function to demonstrate Call by Reference
void callByReference(int *b) {
    *b = *b + 10;
    cout << "Value of b inside the function: " << *b << endl;
}
int main() {
    int b;

    // Input value
    cout << "Enter the value of b: ";
    cin >> b;

    // Display original value
    cout << "Value of b before function call: " << b << endl;
    // Function call
    callByReference(&b);

    // Display value after function call
    cout << "Value of b after function call: " << b << endl;
    return 0;
}
