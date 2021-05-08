#include<bits/stdc++.h>
#include <iostream>
#define MAX 100
using namespace std;

void heapify(int arr[],int i,int n)
{
    int par=(i-1)/2;
    if(arr[par]>0)
    {
        if(arr[i]>arr[par])
        {
            swap(arr[i],arr[par]);
            heapify(arr,par,n);
        }
    }
}
void insert(int arr[],int& n,int temp)
{
    n=n+1;
    arr[n-1]=temp;
    heapify(arr,n-1,n);
}
int main()
{
    int arr[MAX]; 
    int n;
    cout<<"Enter the no.of element you want to insert in a heap";
    cin>>n;
    int size=0;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        insert(arr,size,temp);
    }
    for (size_t i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

