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
// cp --- sp cp---sp
int main()
{
    int arr[9]={2, 30, 15, 100, 8, 25, 80,3,10};
    int dp[9]={0};
    int n=9;
    int maximum=arr[n-1],minimum=arr[0];

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>maximum) maximum=arr[i];
        dp[i]=max(dp[i+1],maximum-arr[i]);   // here arr[i] is the Cost price and max is selling price
    }
    for(int a:dp) cout<<a<<" ";
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<minimum) minimum=arr[i];
        dp[i]=max(dp[i-1],dp[i]+(arr[i]-minimum));
    }
    for(int a:dp) cout<<a<<" ";
    cout<<endl;
    cout<<dp[n-1]<<endl;

    // second method , but in this it is not limited to two buying and selling  O(n) TC 
    int profit=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            profit+=arr[i]-arr[i-1];
        }
    }
    cout<<profit<<endl;
    return 0;
}