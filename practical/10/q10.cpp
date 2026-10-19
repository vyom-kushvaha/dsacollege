
#include <iostream>
using namespace std;

int main() {
    int a[100], n, ch, temp, minIndex;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "1. Bubble Sort\n2. Selection Sort\n";
    cout << "Enter choice: ";
    cin >> ch;

    if (ch == 1) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
    else if (ch == 2) {
        for (int i = 0; i < n - 1; i++) {
            minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[minIndex])
                    minIndex = j;
            }

            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
    else {
        cout << "Invalid choice";
        return 0;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
