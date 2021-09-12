// longest increasing subsequence

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#include<vector>
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define MP make_pair
#define endl "\n"
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
const int inf =(int) 1e18;
const int ninf = (int)-1e17;
#define rep(a, b) for (int a = 0; a < b; a++)
#define per(a, b) for (int a = b - 1; a >= 0; a--)
#define FOR(it, start, end) for (auto it = start; it != end; it++)

int Tabulation(int arr[],int n)  //O(n^2) approach
{
    vector<int>dp;
    dp.resize(n);
    dp[0]=1;

    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
    // now finding max in dp array
    int maxelm=dp[0];
    for(int i=1;i<n;i++)
    {
        maxelm=max(maxelm,dp[i]);
    }
    return maxelm; 
}
int binarysearch_ceil(vector<int>arr,int l,int h,int elem)
{
    while (l<h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]<elem)
            l=mid+1;
        else
            h=mid;
    }
    return h;
}

int efficient(int arr[],int n)    // O(n log n ) approaach 
{
    vector<int>tail;
    tail.push_back(arr[0]);
    int len=1;
    for(int i=1;i<n;i++)
    {
        if(tail[len-1]<arr[i])
        {
            tail.push_back(arr[i]);
            len++;
        }
        else
        {
            int idx=binarysearch_ceil(tail,0,len-1,arr[i]);
            tail[idx]=arr[i];
        }
    }
    return tail.size();
}


int main()
{
    // boost;
    int arr[8]={4,10,6,5,8,11,2,20};
    int n=8;
    cout<<Tabulation(arr,n);
    cout<<endl;
    cout<<efficient(arr,n);
    
    return 0;
}