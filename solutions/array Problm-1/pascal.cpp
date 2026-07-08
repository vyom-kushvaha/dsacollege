#include<iostream>
using namespace std;

int nCr(int n, int r) { // function for nCr
    
    if (r > n || r < 0) return 0;// r not negetive or greater than form n.
    if (r == 0 || r == n) return 1;
    
    if (r > n - r) {
        r = n - r; 
    }
    int result = 1;
    for (int i = 1; i <= r; ++i) {
        result *= (n - r + i); 
        result /= i;           
    }
    return result;
}
int main()
{
    int row;
    int i,j;

    cout<<"Enter how many rows you want:";
    cin>>row;
    
    cout<<"[";
    for(i=0;i<row;i++)
    {
        cout<<"[";
        for(j=0;j<=i;j++)
        {
            cout<<nCr(i,j);
            if(j != i)
            cout<<",";

        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
}