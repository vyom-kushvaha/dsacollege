#include<iostream>
using namespace std;

int main()
{
    int size,i,sub;
    cout<<"Enter how many days price to you want to enter:";
    cin>>size;
    int arr[size];

    cout<<"Enter "<<size<<" day's price:"<<endl;
    for(i=0;i<size;i++)
    {
       
        cin>>arr[i];
    }
    int flag = 0, minPrice = arr[0],maxProfit = -1;
    for(i = 1; i < size;i++)
    {
        if(minPrice > arr[i]){
        minPrice = arr[i];
        flag = i;
        }
    }
    for(int j = flag; j < size; j++)
    {
        if ( maxProfit < arr[j] - minPrice)
        maxProfit = arr[j] - minPrice;
    }
    if(maxProfit == 0)
    {
        cout<<"Don't Buy Or Sell";
    }
    else
    {
        cout<<"Maximum profit is :"<<maxProfit;
    }

    return 0;
}