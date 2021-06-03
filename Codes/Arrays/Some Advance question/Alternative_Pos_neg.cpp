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

int main()
{
    int arr[6]={2,3,-4,-1,6,-9};
    int n=6;
    int i=0,j=n-1;
    while(i<=j)
    {
        if(arr[i]>0 and arr[j]<0)
        {
            i++;j--;
        }
        else if(arr[i]<0 and arr[j]>0)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else if(arr[i]>0) i++;
        else if(arr[j]<0) j--;
    }

    if(i==0 or i==n)
    {
        for(int a:arr) cout<<a<<" ";
        return 0;
    }
    int k=0;
    while(k<n or i<n)
    {
        swap(arr[k],arr[i]);
        k+=2;
        i++;
    }
        for(int a:arr) cout<<a<<" ";



    return 0;
}