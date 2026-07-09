#include<iostream>
using namespace std;
int main(){

    
    int size;
    cout<<"Enter size of array:";
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" element of arrays:";
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int count,majorityElement = -1;
    for(int i=0;i<size;i++)
    {
        count = 0;
        for(int j=0;j<size;j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if ( count > size/2 )
        {
            majorityElement = arr[i];
        }
    }
    if( majorityElement != -1)
    {
        cout<<"majority element is : "<<majorityElement<<endl;
    }
    else
    {
        cout<<"not any element is majority";
    }

    return 0;
}