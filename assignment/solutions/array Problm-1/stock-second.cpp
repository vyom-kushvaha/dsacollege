#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    int prices[n];

    cout << "Enter " << n << " day's prices:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int buy1 = 100000, buy2 = 100000;
    int profit1 = 0, profit2 = 0;

    for(int i = 0; i < n; i++) {
        buy1 = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);
        buy2 = min(buy2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - buy2);
    }

    if(profit2 == 0) {
        cout << "Don't Buy Or Sell";
    } else {
        cout << "Maximum profit is: " << profit2;
    }

    return 0;
}