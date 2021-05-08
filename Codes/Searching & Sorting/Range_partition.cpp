// This logic can be used to sort 0's 1's and 2's in the array without using any sorting algorithm
//Three way partition 
// Wap to partition around a range
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
void partition(int arr[],int r1,int r2,int n)
{
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(arr[mid]<r1)
        {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        if(arr[mid]>=r1 && arr[mid]<=r2)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[7]={10,5,6,3,20,9,40};
    int r1=5,r2=10;
    partition(arr,r1,r2,7);
    for(int a:arr) cout<<a<<" ";
    return 0;
}


// 3 5 6 10 9 40 20