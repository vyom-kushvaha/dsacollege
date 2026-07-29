#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter how many days price to you want to enter: ";
    cin >> size;
    int arr[size];

    cout << "Enter " << size << " day's price:" << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int minPrice = arr[0];
    int maxProfit = 0;

    for(int i = 1; i < size; i++) {
        int profit = arr[i] - minPrice;
        if(profit > maxProfit) {
            maxProfit = profit;
        }
        
        if(arr[i] < minPrice) {
            minPrice = arr[i];
        }
    }

    if(maxProfit == 0) {
        cout << "Don't Buy Or Sell";
    } else {
        cout << "Maximum profit is: " << maxProfit;
    }

    return 0;
}