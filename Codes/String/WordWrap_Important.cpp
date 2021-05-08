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
void calculate(int arr[],int k,int n)
{
    int cost[n][n];
    for(int i=0;i<n;i++)
    {
        cost[i][i]=k-arr[i];
        for(int j=i+1;j<n;j++)
        {
            cost[i][j]=cost[i][j-1]-arr[j]-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            // if(i==n-1 and j==n-1 && cost[i][j]>0)
            //     cost[i][j]=0;
            if(cost[i][j]<0) cost[i][j]=INT_MAX;
            else cost[i][j]=cost[i][j]*cost[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int min[n];
    int ans[n];
    for(int i=n-1;i>=0;i--)
    {
        min[i]=cost[i][n-1];
        ans[i]=n;
        for(int j=n-1;j>i;j--)
        {
            if(cost[i][j-1]==INT_MAX) continue;
            if(min[i]>cost[i][j-1]+min[j])
            {
                min[i]=cost[i][j-1]+min[j];
                ans[i]=j;
            }
        }
        
    }
    for(int i:min) cout<<i<<" ";
    cout<<endl;
    for(int i:ans)cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<n;i=ans[i])
    {
        cout<<i+1<<"-"<<ans[i]<<endl;
    }
}

int main()
{
    // run();
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>k;
    calculate(arr,k,n);
    return 0;
}