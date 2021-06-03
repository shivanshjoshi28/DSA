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
    int arr[9]={1,5,8,4,7,6,5,3,1};
    int n=9;
    int idx=-1;
    for(int i=n-1;i>0;i--)
    {
        if(arr[i]>arr[i-1])
        {
            idx=i;
            break;
        }
    }
    if(idx==-1) reverse(arr,arr+n);
    else
    {
        int prev=idx;
        for(int i=idx+1;i<n;i++)
        {
            if(arr[i]>arr[idx-1] && arr[i]<=arr[prev])
            {
                prev=i;
            }
        }
        swap(arr[idx-1],arr[prev]);
        reverse(arr+idx,arr+n);
        // int start= idx,end=n-1;
        // while(start<end)
        // {
        //     swap(arr[start],arr[end]);
        //     start++;
        //     end--;
        // }

    for(int elem:arr) cout<<elem<<"";
    }
    return 0;
}