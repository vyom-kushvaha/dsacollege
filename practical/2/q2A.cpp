#include <iostream>
using namespace std;
  // Function to demonstrate Call by Value
void callByValue(int a) {
    a = a + 10;
    cout << "Value of a inside the function: " << a << endl;
}
int main() {
    int a;
   	 // Input value
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Value of a before function call: " << a << endl;
    // Function call
    callByValue(a);
    // Display value after function call
    cout << "Value of a after function call: " << a << endl;
    return 0;
}
