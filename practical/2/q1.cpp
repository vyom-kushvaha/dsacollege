/* 

-------- 	Reverse an array	  [Two-pointer swap]-------------

*/

#include<iostream>
using namespace std;
int main()
{
    int size,i,temp;
    cout<<"Enter array size:";
    cin>>size;
    int arr[size];

    cout<<"Enter "<<size<<" elements:"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Entered array order:"<<endl;
    for(i=0;i<size;i++)
    {
        cout<<arr[i];
        cout<<endl;
    }
    cout<<endl;
    for (i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    cout<<"revresd order:"<<endl;
    for(i=0;i<size;i++)
    {
        cout<<arr[i];
        cout<<endl;
    }
    

    return 0;
}